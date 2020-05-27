#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N <= 1) {
		cout << N;
		return 0;
	}
	bool* boo = new bool[N];
	int* s = new int[N];
	int* f = new int[N];

	int count = 1;
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> f[i];
		boo[i] = true;
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = (N - 1); j >= (i + 1); j--) {
			if (f[j] < f[j - 1]) {
				swap(f[j], f[j - 1]);
				swap(s[j], s[j - 1]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (boo[i]) {
			for (int j = 0; j < N; j++) {
				if (boo[j]) {
					if (f[i] <= s[j]) {
						count++;
						break;
					}
					else boo[j] = false;
				}
			}
		}
	}

	cout << count;
}