#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

void appendNode(int data, Node*& head, Node*& tail) {
	Node* newNode = new Node;

	if (!head) {
		// ���� ������ ����, �� ����� ���� �������� ������ ��� � �����
		newNode->data = data;
		head = newNode;
		head->next = head;
		head->prev = head;
	}
	else {
		// ������� ����� ��������� � ������ ����������
		newNode->data = data;
		Node* last = head->prev; // ��������� �������

		// ��������� ���������
		last->next = newNode;    // ��������� -> �����
		newNode->prev = last;    // ����� <- ���������
		newNode->next = head;    // ����� -> ������
		head->prev = newNode;    // ������ <- �����
	}
}

bool deleteNode(int data, Node* head, Node* tail) {
	if (head == nullptr) return false;
	Node* current = head;
	do {
		if (current->data == data) {
			// ���� ��� ������������ ����
			if (current->next == current) {
				delete current;
				head = nullptr;
				return true;
			}

			// ��������� ��������� �������� �����
			current->prev->next = current->next;
			current->next->prev = current->prev;

			// ���� ��������� ���� - ������ ������
			if (current == head) {
				head = current->next;
			}

			delete current;
			return true;
		}
		current = current->next;
	} while (current != head);

	return false; // ���� �� ������
}


void display(Node* head) {
	Node* current = head;
	do {
		std::cout << current->data;
		current = current->next;
		if (current != head) {
			std::cout << " <-> ";
		}
	} while (current != head);
}

int main() {

	setlocale(LC_ALL, "Russian");

	Node* head = nullptr;
	Node* tail = nullptr;

	appendNode(1, head, tail);
	appendNode(2, head, tail);
	appendNode(3, head, tail);

	display(head);
	cout << endl << "�������� �������� 2: " << endl;
	deleteNode(2, head, tail);
	display(head);

}