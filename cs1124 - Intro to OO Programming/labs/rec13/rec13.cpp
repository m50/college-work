// #include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

void displayBinary(int num) {
	if(num == 0) {
		cout << 0;
		return;
	}
	displayBinary(num / 2);
	cout << num % 2;
}

struct Node {
	int data;
	Node* next;
	Node(int d, Node* n = NULL) : data(d), next(n) {}
};

Node* addTrees(Node* head1, Node* head2) {
	if(head1 == nullptr) return nullptr;
	return new Node(head1->data + head2->data, addTrees(head1->next, head2->next));
}

struct TreeNode { 
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d, TreeNode* left = NULL, TreeNode* right = NULL) : data(d), left(left), right(right) {}
};

int max(TreeNode* root) {
	if(root == nullptr) return INT_MIN;
	if(root->left->data > root->data && root->left->data > root->right->data)
		return max(root->left);
	else if(root->right->data > root->data && root->right->data > root->left->data)
		return max(root->right);
	else
		return root->data;
}

int sumCString(char str [], int length) {
	if(length < 0) return 0;
	return str[length-1] + sumCString(str, length - 1);
}

int cbinarySearch(char str [], char searchFor, int low, int high) {
	int mid = (low + high) / 2;
	if(searchFor == str[mid])
		return mid;
	else if(searchFor < str[mid])
		return cbinarySearch(str, searchFor, low, mid);
	else
		return cbinarySearch(str, searchFor, mid, high);
}

int main () {
	////----1----////
	// displayBinary(10);
	// cout << endl;
	// displayBinary(15);
	// cout << endl;
	// displayBinary(4);
	// cout << endl;
	
	////----2----////
	// Node* nodes1 = new Node(10, new Node(15, new Node(2)));
	// Node* nodes2 = new Node(5, new Node(30, new Node(100)));
	// Node* sum = addTrees(nodes1, nodes2);
	// Node* stepper = sum;
	// while(stepper != nullptr) {
	// 	cout << stepper->data << endl;
	// 	stepper = stepper->next;
	// }
	
	////----3----////
	// TreeNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	// cout << max(&f) << endl;
	
	////----4----////
	// cout << sumCString("E", 1) << endl;
	 
	////----5----//// 
	// char str [27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// int index = cbinarySearch(str, 'I', 0, 26);
	// cout << index << ") " << str[index] << endl;
}