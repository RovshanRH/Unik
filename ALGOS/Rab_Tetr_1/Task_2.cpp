#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

void appendNode(Node*& head, Node*& tail, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = tail;

	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void displayNodeList(Node* head) {
	Node* current = head;
	while (current) {
		cout << current->data;
		if (current->next) cout << " <-> ";
		current = current->next;
	}
}

void createNewLists(Node* head, int x, Node*& lessX, Node*& greaterX) {
    lessX = nullptr; // head для списка элементов меньших Х
    greaterX = nullptr; // head для списка элементов больших Х

    Node* lessTail = nullptr; // tail для списка элементов меньших Х
    Node* greaterTail = nullptr; // tail для списка элементов больших Х

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;

        current->next = nullptr;

        if (current->data < x) {
            if (lessX == nullptr) {
                lessX = current;
                lessTail = current;
            }
            else {
                lessTail->next = current;
                lessTail = current;
            }
        }
        else if (current->data > x) {
            if (greaterX == nullptr) {
                greaterX = current;
                greaterTail = current;
            }
            else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }

        current = nextNode; // переключаемся на следующий узел
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    Node* head = nullptr;
    Node* tail = nullptr;
    
    appendNode(head, tail, 1);
    appendNode(head, tail, 2);
    appendNode(head, tail, 3);
    appendNode(head, tail, 4);
    appendNode(head, tail, 5);

    Node* lessX = nullptr;
    Node* greaterX = nullptr;
    cout << "Пример: диапозон от 1 до 2 и диапозон от 4 до 5" << endl;
    createNewLists(head, 3, lessX, greaterX);
    displayNodeList(lessX);
    cout << endl;
    displayNodeList(greaterX);

}