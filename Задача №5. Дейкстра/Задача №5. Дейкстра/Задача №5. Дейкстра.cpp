#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, S, F;
	cin >> N;
	cin >> S;
	S--;
	cin >> F;
	F--;
	int val = 100000;
	vector<vector<pair<int, int>>> arr(N);
	vector<int> mas(N, val), mass(N);

	mas[S] = 0;
	vector<bool> x(N);
	for (int i = 0, tmp; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (i != j && tmp != -1) arr[i].push_back(make_pair(j, tmp));
		}
	}

	for (int i = 0; i < N; i++) {
		int a = -1;
		for (int j = 0; j < N; j++)
			if (!x[j] && (a == -1 || mas[j] < mas[a])) a = j;

		if (mas[a] == val) break;
		x[a] = true;
		for (int j = 0; j < arr[a].size(); j++) {
			int res = arr[a][j].first;
			int length = arr[a][j].second;
			if (mas[a] + length < mas[res]) {
				mas[res] = mas[a] + length;
				mass[res] = a;
			}
		}
	}
	if (mas[F] == val) cout << -1;
	else cout << mas[F];
}
