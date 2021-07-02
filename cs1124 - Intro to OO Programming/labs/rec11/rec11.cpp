#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* next = NULL) : data(data), next(next) {}
	int data;
	Node* next;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void spliceInto(Node*& spliceLoc, Node* insertedList) {
	Node* next = spliceLoc->next;

	spliceLoc->next = insertedList;

	Node* end = insertedList;
	while(end->next != NULL) {
		end = end->next;
	}
	end->next = next;
}

Node* isSubList(Node* searchable, Node* searchterm) {
	bool isSub = false;
	Node* endsearchable = searchable;
	Node* endterm = searchterm;
	Node* sublistBegin;
	while(endsearchable->next != NULL) {
		if(endsearchable->data == endterm->data) {
			if(endterm->data == searchterm->data) sublistBegin = endsearchable;
			if(!(endterm->next)) { 
				isSub = true; 
				break; 
			}
			endterm = endterm->next;
		}
		endsearchable = endsearchable->next;
	}

	if(isSub) return sublistBegin;
	return NULL;
}

void display(Node* head) {
	Node* next = head;
	cout << "Begin" << endl;
	while(next != NULL) {
		cout << next->data << endl;
		next = next->next;
	}
	cout << "End" << endl;
}

int main() {
	Node* head = new Node(3, new Node(5, new Node(20, new Node(15, new Node(25)))));
	Node* head2 = new Node(5);

	display(head);
	cout << endl;
	display(head2);
	cout << endl << "Display isSubList()s: " << endl;
	display(isSubList(head, head2));
}