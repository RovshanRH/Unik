#include <iostream>
struct Node {
	int data;
	Node* next;
	Node* prev;
};

std::string findCollision(Node* head) {
	if (head == nullptr || head->next == nullptr) return "список пуст или состоит из 1 элемента";
	
	Node* ukaz1 = head; // 1 указатель находиться на "старте" - голова
	Node* ukaz2 = head->next; // 2 указатель находиться на следующем узле после головы

	while (ukaz1 != ukaz2) { // 
		if (ukaz2 == nullptr || ukaz2->next == nullptr) return "перескоков нет";

		ukaz1 = ukaz1->next; // 1 указатель движется на 1 шаг вперёд
		ukaz2 = ukaz2->next->next; // 2 указатель движется на 2 шага вперёд

	}
	return "перескоки есть";
}
