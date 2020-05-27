#include <iostream>
using namespace std;

void heapify(int* mas, int n, int i) {
	int l = i * 2 + 1, r = i * 2 + 2, cur = i;
	if (l < n && mas[l] > mas[cur])
		cur = l;
	if (r < n && mas[r] > mas[cur])
		cur = r;
	if (i != cur)
	{
		swap(mas[i], mas[cur]);
		heapify(mas, n, cur);
	}
}

/*void build_heap(int* mas, int& size){
	for (int i = (size / 2) - 1; i >= 0; i--)
		heapify(mas, i, size);
}*/

/*void add(int* mas, int val, int& size){
	mas[size] = val;
	size++;
	int cur = size - 1;
	int p = (cur / 2) - 1;
	while (p > 0 && mas[p] < mas[cur])
	{
		swap(mas[p], mas[cur]);
		cur = p;
		p = (cur / 2) - 1;
	}
}*/

/*void del(int* mass, int& size){
	int tmp = mass[0];
	mass[0] = mass[size - 1];
	size--;
	heapify(mass, 0, size);
}*/

void sort(int* mas, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(mas, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(mas[0], mas[i]);
		heapify(mas, i, 0);
	}
}

void print(int* mas, int n) {
	for (int i = 0; i < n; i++) cout << mas[i] << " ";
}


int main()
{
	int n;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}

	sort(mas, n);
	print(mas, n);
}