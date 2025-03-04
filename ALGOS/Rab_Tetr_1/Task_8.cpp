#include <iostream>
using namespace std;

struct SegmentedTreeNode {
	int l, r;
	SegmentedTreeNode* right;
	SegmentedTreeNode* left;
	SegmentedTreeNode(int l, int r) : l(l), r(r), left(nullptr), right(nullptr) {}
};

SegmentedTreeNode* recursivebuildTree(int l, int r) { // ����������� ���������� ������
	if (l > r) return nullptr;
	
	SegmentedTreeNode* node = new SegmentedTreeNode(l, r);
	
	if (l == r) return node; // ������ ����

	int mid = l + (r - l) / 2;
	node->left = recursivebuildTree(l, mid);
	node->right = recursivebuildTree(mid + 1, r);

	return node;
}

void printSegmentedTree (SegmentedTreeNode* root) { // ������ ����� �� ������
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

	cout << "����� ������ �������� �� ��������� (1,5) �� �����: ";
	printSegmentedTree(root);
	cout << endl;
	cout << "���-�� ����������, ���������� ����� 1: ";
	cout << countintervalofTree(root, 1);
}