#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int a) {
		val = a;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

vector<int> inorder(Node* root)
{
	vector<int> out;
	Node* p = root;
	Node* prev = NULL;
	while (p) {
		cout << "current node: "<<p->val<<endl;
		if (prev == p->parent) {
			if (p->left) {
				prev = p;
				p = p->left;
				continue;
			} else {
				prev = NULL;
			}
		}

		if (prev == p->left) {
			out.push_back(p->val);
			if (p->right) {
				prev = p;
				p = p->right;
				continue;
			} else {
				prev = NULL;
			}
		}

		if (prev == p->right) {
			prev = p;
			p = p->parent;
		}
	}
	// the loop ends when p is equal to the parent of root node
	return out;
}

int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	n1->left = n2;
	n1->right = n3;
	n2->right = n4;
	n2->parent = n1;
	n3->parent = n1;
	n4->parent = n2;
	vector<int> out = inorder(n1);
	for (int i=0;i<out.size();i++)
		cout<<out[i]<<" ";
	cout<<endl;
	return 0;
}

