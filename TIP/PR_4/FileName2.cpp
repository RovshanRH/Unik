#include <iostream>
using namespace std;

void SendBK(const string& id, const string& message) {
	cout << "Send '" << message << "' to BK user " << id << endl;
}

void SendTelegraph(const string& login, const string& message) {
	cout << "Send '" << message << "' to Telegraph user " << login << endl;
}

class NotifierBase {
public:
	virtual void notify() {
		cout << "";
	}
};

class BKNotifier : public NotifierBase {
private:
	string id;
	string message;
public:
	BKNotifier(const string id, const string message) {
		this->id = id;
		this->message = message;
	}
	void notify() {
		SendBK(id, message);
	}
};

class TelegraphNotifier : public NotifierBase {
private:
	string login;
	string message;
public:
	TelegraphNotifier(const string login, const string message) {
		this->login = login;
		this->message = message;
	}
	void notify() {
		SendBK(login, message);
	}
};

int main() {
	NotifierBase* notifier;
	BKNotifier bknotifier{ "1234", "hello" };
	notifier = &bknotifier;
	notifier->notify();
	cout << endl;
	TelegraphNotifier telegraphnotifier{ "1235", "bye" };
	notifier = &telegraphnotifier;
	notifier->notify();
}