#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

void bucket_sort(int* arr, int n) {
	int min = arr[0];
	int max = arr[0];
	int num = n / 2;
	float x;
	vector<vector<int>> bucket(num);

	for (int i = 0; i < n; i++) {
		if (min > arr[i]) min = arr[i];
		else if (max < arr[i]) max = arr[i];
	}

	x = (float(max - min)) / num;

	for (int i = 0, index = -1; i < n; i++) {
		index = (int)((arr[i] - min) / x);
		bucket.at(index >= num ? num - 1 : index).push_back(arr[i]);
	}

	for (int i = 0; i < num; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}

	for (int i = 0, j = 0; i < num; i++) {
		for (int k = 0; k < bucket[i].size(); k++) arr[j++] = bucket[i][k];
	}
}

int main()
{
	int n;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) cin >> mas[i];

	bucket_sort(mas, n);

	for (int i = 0; i < n; i++) cout << mas[i] << " ";
}
