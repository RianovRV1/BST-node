#pragma once
#ifndef NULL
#define NULL 0
#endif

class Node{
public:
	Node()
	{
		leftNode = nullptr;
		rightNode = nullptr;
		parent = nullptr;
		balance = NULL;
		height = 1;
		
	}
	Node(int num)
	{
		item = num;
		balance = NULL;
		leftNode = nullptr;
		rightNode = nullptr;
		parent = nullptr;
		height = 1;
	}
	int getItem()
	{
		return item;
	}
	void setItem(int num)
	{
		item = num;
	}
	Node* getLeft()
	{
		return leftNode;
	}
	void setLeft(Node *leftN)
	{
		leftNode = leftN;
	}
	Node* getRight()
	{
		return rightNode;
	}
	void setRight(Node *rightN)
	{
		rightNode = rightN;
	}
	~Node()
	{
		leftNode = nullptr;
		rightNode = nullptr;
		item = NULL;
		parent = nullptr;
	}
//private:
	int item;
	int balance;
	int height;
	Node* leftNode; 
	Node* rightNode;
	Node* parent;
	
};