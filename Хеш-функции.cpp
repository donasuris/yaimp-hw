#include <iostream>
#include <ctime>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <fstream>

using namespace std;

const int max_len = 1024; // максимальный размер хеш-таблицы
//const int max_len = 512;
//const int max_len = 256;
//const int max_len = 128;
//const int max_len = 64;
//const int max_len = 32;
//const int max_len = 16; 
//const int max_len = 8;
//const int max_len = 4;
//const int max_len = 2;
//const int max_len = 1;

struct Node {
	string key;
	string value;
	Node* next = NULL;
	Node* prev = NULL;

	Node(string key, string value) {
		this->key = key;
		this->value = value;
	}
};

int Hash(string text) { // функция должна возвращать сумму кодов букв по модулю max_len
	int sum = 0;
	for (int i = 0; i < text.length(); ++i) sum += text[i];
	return sum;
}

void Set(Node* table[], string key, string value) { // функция добавляет пару ключ значение в массив
	int ind = Hash(key) % max_len;
	Node* cur = table[ind];
	if (table[ind] == NULL) {
		table[ind] = new Node(key, value);
		return;
	}
	table[ind] = new Node(key, value);
	table[ind]->next = cur;
	cur->prev = table[ind];
}

string Search(Node* table[], string key) { //  функция должна возвращать найденное знаечение по ключу иначе NULL
	int ind = Hash(key) % max_len;
	Node* cur = table[ind];
	while (cur != NULL) {
		if (cur->key == key) return cur->value;
		cur = cur->next;
	}
	return "0";
}

void Print(Node* table[]) { // вывод
	int count = 0;
	for (int i = 0; i < max_len; i++) {
		cout << i << ')' << endl;
		Node* cur = table[i];
		while (cur != NULL) {
			cout << cur->key << " " << cur->value << endl;
			cur = cur->next;
			count++;
		}
		cout << endl;
	}
	cout << count;
}

void Get(Node* table[], string key) {  // функция должна возвращать найденное знаечение по ключу и удалять его из таблицы иначе NULL
	int ind = Hash(key) % max_len;
	Node* cur = table[ind];
	while (cur != NULL) {
		if (cur->key == key) {
			if (cur->next != NULL) {
				if (cur != table[ind]) {
					cur->next->prev = cur->prev;
					cur->prev->next = cur->next;
					delete cur;
					return;
				}
				else table[ind] = cur->next;
			}
			cur->prev->next = NULL;
			delete cur;
			return;
		}
		cur = cur->next;
	}
	cout << "this key doesn't exist" << endl;
}

int main() {
	ifstream fin("input.txt");
	Node* table[max_len]{ NULL };
	string key;
	string value;
	while (fin >> key, fin >> value) Set(table, key, value);
	fin.close();
	ifstream in("input.txt");
	int count = 0;
	unsigned int start_time = clock();
	while (in >> key) {
		cout << Search(table, key) << endl;
		in >> key;
		count++;
	}
	unsigned int end_time = clock();
	cout << end_time - start_time << endl;
	cout << count;
}