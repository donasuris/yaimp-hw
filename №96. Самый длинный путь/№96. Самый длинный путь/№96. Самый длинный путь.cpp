#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, max_len = 0;
	cin >> N;
	vector<vector<int>> graph(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> graph[i][j];
	for (int q = 0; q < N; ++q)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) graph[i][j] = min(graph[i][j], graph[i][q] + graph[q][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) max_len = max(graph[i][j], max_len);
	cout << max_len;
}
