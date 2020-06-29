#include <iostream>
using namespace std;

void dfs(bool& Case, int** vv, int* v, int n, int cur) {
	v[cur] = 1;
	for (int i = 0; i < n && !Case; i++) {
		if (vv[cur][i] == 1) {
			if (v[i] == 0) dfs(Case, vv, v, n, i);
			else if (v[i] == 1) {
				Case = true;
				return;
			}
		}
	}
	v[cur] = 2;
}

int main()
{
	bool Case = false;
	int** vv;
	int* v;
	int n, res = 0;
	cin >> n;
	v = new int[n];
	vv = new int* [n];

	for (int i = 0; i < n; i++) {
		vv[i] = new int[n];
		v[i] = 0;
		for (int j = 0; j < n; j++) cin >> vv[i][j];
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			dfs(Case, vv, v, n, i);
			if (Case) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
