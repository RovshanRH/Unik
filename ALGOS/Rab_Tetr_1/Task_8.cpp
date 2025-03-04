#include <iostream>
using namespace std;

struct SegmentedTreeNode {
	int l, r;
	SegmentedTreeNode* right;
	SegmentedTreeNode* left;
	SegmentedTreeNode(int l, int r) : l(l), r(r), left(nullptr), right(nullptr) {}
};

SegmentedTreeNode* recursivebuildTree(int l, int r) { // Рекурсивное построение дерева
	if (l > r) return nullptr;
	
	SegmentedTreeNode* node = new SegmentedTreeNode(l, r);
	
	if (l == r) return node; // Создаём лист

	int mid = l + (r - l) / 2;
	node->left = recursivebuildTree(l, mid);
	node->right = recursivebuildTree(mid + 1, r);

	return node;
}

void printSegmentedTree (SegmentedTreeNode* root) { // Прямой обход по дереву
	if (root == nullptr) return;

	cout << "[" << root->l << ", " << root->r << "] ";

	printSegmentedTree(root->left);
	printSegmentedTree(root->right);
}

int countintervalofTree(SegmentedTreeNode* root, int x) {
	if (root == nullptr) return 0;
	if (x >= root->l && x <= root->r) {
		return 1 + countintervalofTree(root->left, x) + countintervalofTree(root->right, x);
	}
	else if (x < root->l) {
		return countintervalofTree(root->left, x);
	}
	else {
		return countintervalofTree(root->right, x);
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	SegmentedTreeNode* root = recursivebuildTree(1, 5);

	cout << "Вывод дерева отрезков на интервале (1,5) на экран: ";
	printSegmentedTree(root);
	cout << endl;
	cout << "Кол-во интервалов, содержащих точку 1: ";
	cout << countintervalofTree(root, 1);
}