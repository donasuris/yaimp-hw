#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int x, y; //вершины
	edge() {}
	edge(int a, int b) {
		x = a;
		y = b;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector <edge>  graph(M); //ребра исходного графа
	vector <edge> tree; //ребра дерева
	vector <int> multiplicity(N); //множество вершин
	for (int i = 0; i < N; i++) multiplicity[i] = i;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[i].x = a;
		graph[i].y = b;
	}

	for (int i = 0; i < M; i++) {
		int a = graph[i].x;
		int b = graph[i].y;
		if (multiplicity[a] != multiplicity[b]) {
			tree.push_back(graph[i]);
			int old_multiplicity = multiplicity[b], new_variety = multiplicity[a];
			for (int j = 0; j < N; j++) 
				if (multiplicity[j] == old_multiplicity) multiplicity[j] = new_variety;	
		}
	}

	for (int i = 0; i < N - 1; i++) {
		cout << tree[i].x << " " << tree[i].y;
		if (i != N - 2) cout << endl;
	}
}
