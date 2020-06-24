#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	char height;
	Node(int value) {
		left = NULL;
		right = NULL;
		height = 1;
		val = value;
	}
};

int height(Node* node) { //высота
	if (node) return node->height;
	else return NULL;
}

void node_height(Node* node) { //высота поомков node
	int heightLeft = height(node->left);
	int heightRight = height(node->right);
	if (heightLeft > heightRight) node->height = heightLeft + 1;
	else node->height = heightRight + 1;
}

int height_diff(Node* node) { //разница высот
	return height(node->right) - height(node->left);
}

Node* Right_rotation(Node* node) { //правый поворот
	Node* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node_height(node);
	node_height(tmp);
	return tmp;
}

Node* Left_rotation(Node* node) { //левый поворот
	Node* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	node_height(node);
	node_height(tmp);
	return tmp;
}

Node* balance(Node* node) { //балансировка
	node_height(node); //пересчитывает высоты потомков для node
	int x = height_diff(node); //находим разницу высот П и Л потомков
	if (x == 2) { //если правое поддерево больше левого
		if (height_diff(node->right) < 0) // определяем левый поворот или большой левый поворот (если баланс правого потомка < 0, то выполняем большой правый поворот)
			node->right = Right_rotation(node->right);
		return Left_rotation(node);
	}
	if (x == -2) { //если левое поддерево больше правого
		if (height_diff(node->left) > 0) //определяем правый поворот или большой правй поворот (если баланс левого потомка < 0, то выполняем большой левый поворот)
			node->left = Left_rotation(node->left);
		return Right_rotation(node);
	}
	return node;
}

Node* add(Node* node, int val) { //добавление 
	if (!node) return new Node(val);
	if (val < node->val) node->left = add(node->left, val);
	else node->right = add(node->right, val);
	return balance(node);
}

bool search(Node* node, int n) { //поиск
	if (node != NULL) {
		if (search(node->left, n)) return true;
		if (n == node->val) return true;
		if (search(node->right, n)) return true;
	}
	else return false;
	return false;
}

Node* Min(Node* node) { //минимум
	if (node) {
		Node* tmp = node;
		while (tmp->left) tmp = tmp->left;
		return tmp;
	}
}

Node* Max(Node* node) { //максимум
	if (node) {
		Node* tmp = node;
		while (tmp->right) tmp = tmp->right;
		return tmp;
	}
}

Node* del_min(Node* node) { //удаление минимульного значения
	if (node->left == NULL) return node->right;
	node->left = del_min(node->left);
	return balance(node);
}

Node* del(Node* node, int val) { //удаление
	if (!node)return NULL;
	if (val < node->val) node->left = del(node->left, val);
	else if (val > node->val) node->right = del(node->right, val);
	else {
		Node* l = node->left;
		Node* r = node->right;
		delete node;
		if (!r)return l;
		Node* min = Min(r);
		min->right = del_min(r);
		min->left = l;
		return balance(min);
	}
	return balance(node);
}

void print(Node* node, int root = 0) { //вывод
	if (node == NULL) return;
	print(node->left, root + 1);
	for (int i = 0; i < root; i++) cout << " ";
	cout << node->val << endl;
	print(node->right, root + 1);
}

//void print_LRR(Node* node) { //левый корень правый
//	if (node != NULL) {
//		print_LRR(node->left);
//		cout << node->val << endl;
//		print_LRR(node->right);
//	}
//}
//
//void print_RLR(Node* node) { //корень левый правый
//	if (node != NULL) {
//		cout << node->val << endl;
//		print_LRR(node->left);
//		print_LRR(node->right);
//	}
//}
//
//void print_LRR(Node* node) { //левый правый корень
//	if (node != NULL) {
//		print_LRR(node->left);
//		print_LRR(node->right);
//		cout << node->val << endl;
//	}
//}

int main()
{
	ifstream fin("input.txt");
	Node* node = NULL;
	int n;
	while ((fin >> n) && (n != 0)) node = add(node, n);
	print(node);
	cout << "max: " << Max(node)->val << endl;
	cout << "min: " << Min(node)->val << endl;

	if (search(node, 3))
		cout << "find" << endl;
	else
		cout << "not find" << endl;
	if (search(node, 15))
		cout << "find" << endl;
	else
		cout << "not find" << endl;

	node = del(node, 15);
	print(node); cout << endl;
	node = del(node, 38);
	print(node); cout << endl;
	node = del(node, 6);
	print(node); cout << endl;
	fin.close();
}