#include <iostream>
struct Node {
	int data;
	Node* next;
	Node* prev;
};

std::string findCollision(Node* head) {
	if (head == nullptr || head->next == nullptr) return "������ ���� ��� ������� �� 1 ��������";
	
	Node* ukaz1 = head; // 1 ��������� ���������� �� "������" - ������
	Node* ukaz2 = head->next; // 2 ��������� ���������� �� ��������� ���� ����� ������

	while (ukaz1 != ukaz2) { // 
		if (ukaz2 == nullptr || ukaz2->next == nullptr) return "���������� ���";

		ukaz1 = ukaz1->next; // 1 ��������� �������� �� 1 ��� �����
		ukaz2 = ukaz2->next->next; // 2 ��������� �������� �� 2 ���� �����

	}
	return "��������� ����";
}
