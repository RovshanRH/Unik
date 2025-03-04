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
		// Если список пуст, то новый узел образует кольцо сам с собой
		newNode->data = data;
		head = newNode;
		head->next = head;
		head->prev = head;
	}
	else {
		// Вставка между последним и первым элементами
		newNode->data = data;
		Node* last = head->prev; // Последний элемент

		// Обновляем указатели
		last->next = newNode;    // Последний -> Новый
		newNode->prev = last;    // Новый <- Последний
		newNode->next = head;    // Новый -> Первый
		head->prev = newNode;    // Первый <- Новый
	}
}

bool deleteNode(int data, Node* head, Node* tail) {
	if (head == nullptr) return false;
	Node* current = head;
	do {
		if (current->data == data) {
			// Если это единственный узел
			if (current->next == current) {
				delete current;
				head = nullptr;
				return true;
			}

			// Обновляем указатели соседних узлов
			current->prev->next = current->next;
			current->next->prev = current->prev;

			// Если удаляемый узел - голова списка
			if (current == head) {
				head = current->next;
			}

			delete current;
			return true;
		}
		current = current->next;
	} while (current != head);

	return false; // Узел не найден
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
	cout << endl << "Удаление элемента 2: " << endl;
	deleteNode(2, head, tail);
	display(head);

}