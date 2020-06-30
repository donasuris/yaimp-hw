#include <iostream>
using namespace std;

bool permut(int* mas, int N) {
	int i = N - 2;
	while (i != -1 && mas[i] >= mas[i + 1]) i--;
	if (i == -1) return false;
	int j = N - 1;
	while (mas[i] >= mas[j]) j--;
	swap(mas[i], mas[j]);
	int left = i + 1, right = N - 1;
	while (left < right) swap(mas[left++], mas[right--]);
	return true;
}

int main()
{
	int N;
	cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; ++i) cin >> mas[i];
	permut(mas, N);
	for (int i = 0; i < N; ++i) cout << mas[i] << " ";
}