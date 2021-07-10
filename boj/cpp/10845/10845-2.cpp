#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* link;

	Node(int v, Node* l) : val(v), link(l) {}
};

struct Queue {
	Node* head;
	int q_size{ 0 };

	void push(Node* node) {
		if (head == nullptr) {
			head = node;
		} else {
			Node* p = head;
			while (p -> link != nullptr) {
				p = p -> link;
			}
			p -> link = node;
		}
		q_size++;
	}

	void pop() {
		if (head != nullptr) {
			Node* p = head -> link;
			delete head;
			head = p;
			q_size--;
		}
	}

	int front() {
		return head -> val;
	}

	int empty() {
		if (head == nullptr) return 1;
		else return 0;
	}

	int size() {
		return q_size;
	}

	int back() {
		Node* p = head;
		while (p -> link != nullptr) {
			p = p -> link;
		}
		return p -> val;
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	Queue* q = new Queue;
	int n, x;
	string op;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == "push") {
			cin >> x;
			q -> push(new Node(x, nullptr));
		} else if (op == "pop") {
			if (q -> empty()) cout << -1 << '\n';
			else {
				cout << q -> front() << '\n';
				q -> pop();
			}
		} else if (op == "size") {
			cout << q -> size() << '\n';
		} else if (op == "empty") {
			cout << q -> empty() << '\n';
		} else if (op == "front") {
			if (q -> empty()) cout << -1 << '\n';
			else cout << q -> front() << '\n';
		} else if (op == "back") {
			if (q -> empty()) cout << -1 << '\n';
			else cout << q -> back() << '\n';
		}
	}
	delete q;
	return 0;
}
