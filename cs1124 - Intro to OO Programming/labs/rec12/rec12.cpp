
#include <iostream>

using namespace std;

class Sequence {
public:
	Sequence() : head(nullptr), current(nullptr), prev(nullptr) {}
	Sequence(const Sequence& seq) {
		head = prev = current = seq.copy();
	}

	~Sequence() {
		clear();
	}

	void add(int value) {
		if(!valid()) {
			if(prev)
			{
				current = new Node(value);
				return;
			}
			current = prev = head = new Node(value);
			return;
		}
		current->next = new Node(value, current->next);
		current = current->next;
	}
	void remove() {
		if(!valid()) return;
		
		prev->next = current->next;
		delete current;
		current = prev->next;

	}
	void next() {
		if(!valid()) return;
		prev = current;
		current = current->next;
	}
	int data() {
		return current->value;
	}
	void reset() {
		current = head;
		prev = head;
	}
	void display(char sepChar = ' ', ostream& out = cout) const {
		if(head == nullptr) {
			out << endl;
			return;
		}
		
		Node* cur = head;
		while(cur != nullptr) {
			out << cur->value << sepChar;
			cur = cur->next;
		}
		out << endl;
	}
	void clear() {
		while(valid()) {
			delete current;
			next();
		}
		head = current = prev = nullptr;
	}
	bool valid() const {
		return bool(current);
	}
	Sequence operator=(const Sequence& rhs) {
		clear();
		head = prev = current = seq.copy();
	}
private:
	struct Node {
		Node(int v, Node* n = NULL) : value(v), next(n) {}
		int value;
		Node* next;
	} *head, *current, *prev;

	Node* copy() const {
		Node* step = head->next;
		Node* last = new Node(head->value);
		Node* result = last;

		while(step != nullptr) {
			last->next = new Node(step->value);
			step = step->next;
			last = last->next;
		}

		return result;
	}
};

int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i) s.next();
	s.add(42);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display();
	cout << "==========\n";
	s.clear();
	s.display();
	cout << "==========\n";
}