#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

void permut(int* mas, int n, int h = 0) {
	if (h == n) {
		arr.push_back(0);
		int size = arr.size();
		for (int i = 0; i <= n; i++) 
			arr[size - 1] = arr[size - 1] * 10 + mas[i];
	}
	else {
		for (int i = h; i <= n; i++) {
			swap(mas[i], mas[h]);
			permut(mas, n, h + 1);
			swap(mas[i], mas[h]);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; i++)
		mas[i] = i + 1;
	permut(mas, N - 1);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
}
