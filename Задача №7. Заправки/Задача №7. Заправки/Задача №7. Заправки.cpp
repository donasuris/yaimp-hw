#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int s = 0;
	int f = N - 1;
	vector<int> price(N);
	int val = 100000;
	for (int i = 0; i < N; i++) cin >> price[i];
	vector<vector<pair<int, int>>> arr(N);
	vector<int> mas(N, val), mass(N);

	mas[s] = 0;
	vector<bool> check(N);
	int M;
	cin >> M;

	for (int i = 0, n1, n2; i < M; i++) {
		cin >> n1 >> n2;
		n1--;
		n2--;
		arr[n1].push_back(make_pair(n2, price[n1]));
		arr[n2].push_back(make_pair(n1, price[n2]));
	}

	for (int i = 0; i < N; i++) {
		int v = -1;
		for (int j = 0; j < N; j++)
			if (!check[j] && (v == -1 || mas[j] < mas[v])) v = j;
		if (mas[v] == val) break;
		check[v] = true;
		for (int j = 0; j < arr[v].size(); j++) {
			int to = arr[v][j].first;
			int len = arr[v][j].second;
			if (mas[v] + len < mas[to]) {
				mas[to] = mas[v] + len;
				mass[to] = v;
			}
		}
	}
	if (mas[f] == val) cout << -1;
	else cout << mas[f];

}
