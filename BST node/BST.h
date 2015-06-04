
#pragma once
#include "BSTnode.h"

using namespace std;
class Tree{
private:
	Node* root;
	void displayBST(Node* node, int level = 0);

	 void deleteKey(Node* root, int key);

	void replace(Node* root, Node* child);

	 void deleteNode(Node* root);

	 void insert(Node* node, int value); 

	 void leftRightRotate(Node* pivot);

	 void leftLeftRotate(Node* pivot);

	 void rightLeftRotate(Node* pivot);
	
	 void rightRightRotate(Node* pivot);

	void checkBalance(Node* root);

	 void setBalance(Node* root);

	void swapKeys(Node* root, Node* child);
	
	void deleteAll(Node* node);

	Node* maxLeft(Node* root);

	Node* minRight(Node* root);

public:
	
	Tree(int num);

	void insert(int value);
	
	void deleteItem(int key);

	void displayBST();


	~Tree();

};
