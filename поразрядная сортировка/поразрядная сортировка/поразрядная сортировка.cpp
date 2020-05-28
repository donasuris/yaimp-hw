#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>& arr) {
	vector<vector<int>> rad(100);
	int a = 10, b = 1;
	while (rad[0].size() != arr.size()) {
		for (int i = 0; i < 10; i++) rad[i].clear();
		for (int i = 0; i < arr.size(); i++) rad[abs(arr[i]) % a / b].push_back(arr[i]);
		b *= 10, a *= 10;
		for (int i = 0, j = 0; i < 10; i++)
			for (int k = 0; k < rad[i].size(); k++)
				arr[j++] = rad[i][k];
	}
}

int main()
{
	vector<int> arr;
	int n, x, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr);
	for (i = 0; i < n; i++) cout << arr[i] << ' ';
	return 0;
}