#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	char key;
	int frequency;
	Node* left;
	Node* right;
	Node(char val, int freq) {
		key = val;
		left = NULL;
		right = NULL;
		frequency = freq;
	}
};

bool compare(Node* f, Node* s) {
	return f->frequency < s->frequency;
}

struct tree {

	Node* root;
	string* table;
	string str;
	string code;
	int count_table[256]{ 0 };

	tree(string _str) {
		root = NULL;
		str = _str;
		build();
	}

	void build() {
		int arr_count = 0;
		Node** arr = new Node * [256];
		for (int i = 0; i < str.length(); i++)
			count_table[str[i]]++;

		for (int i = 0; i < 256; i++) 
			if (count_table[i]) arr[arr_count++] = new Node(i, count_table[i]);
		
		int x = arr_count;
		while (arr_count > 1) {
			sort(arr, arr + arr_count, compare);
			arr[0] = merger(arr[0], arr[1]);
			arr_count--;
			arr[1] = arr[arr_count];
		}

		root = arr[0];
		make_table();
	}

	Node* merger(Node* f, Node* s) {
		Node* temp = new Node('#', f->frequency + s->frequency);
		temp->left = f;
		temp->right = s;
		return temp;
	}

	void make_table() {
		table = new string[256]{ "" };
		intersection(root, "");
	}

	void intersection(Node* node, string code) {
		if (node->key != '#') table[node->key] = code;

		if (node->left && node->right) {
			intersection(node->left, code + '0');
			intersection(node->right, code + '1');
		}
	}

	bool is_list(string str) {
		return !get_node(str)->left;
	}

	Node* get_node(string str) {
		Node* node = root;
		for (int i = 0; i < str.length(); i++) node = str[i] == '0' ? node->left : node->right;
		return node;
	}

	string encode() {
		for (int i = 0; i < str.length(); i++) code += table[str[i]];
		return code;
	}

	string decode() {
		string temp = "";
		string result = "";
		for (int i = 0; i < code.length(); i++) {
			temp += code[i];
			if (is_list(temp)) {
				result += get_node(temp)->key;
				temp = "";
			}
		}
		return result;
	}
};

int main()
{
	cout << "done, check the output.txt";

	ifstream input("input.txt", ios::in);
	freopen("output.txt", "w", stdout);
	string str = "";
	string temp;

	while (true) {
		getline(input, temp);
		str += temp;
		if (input.eof()) break;
		str += "\n";
	}

	tree tr(str);

	cout << "the frequency table:" << '\n';
	for (int i = 0; i < 256; i++)
		if (tr.count_table[i]) cout << '"' << char(i) << '"' << ":\t" << tr.count_table[i] << '\n';

	cout << endl << endl;

	for (int i = 0; i < 256; i++)
		if (tr.table[i] != "") cout << (char)i << " " << tr.table[i] << '\n';

	cout << endl << endl;
	cout << "encoded:" << '\n';
	cout << tr.encode() << '\n';
	cout << endl << endl;
	cout << "decoded:" << '\n';
	cout << tr.decode() << '\n';

	return 0;
}