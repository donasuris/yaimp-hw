#include <iostream>
using namespace std;

void counting_sort(int* a, int n) {
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	
	int* c = new int[max - min + 1];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}

	int k = 0;
	for (int i = min; i < max + 1; i++) {
		while (c[i - min] != 0) {
			a[k] = i;
			cout << i << " ";
			c[i - min]--;
			k++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++){
		cin >> mas[i];
	}

	counting_sort(mas, n);
}
