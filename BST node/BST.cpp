// if any of this code sees redundant, its to make sure things are properly assigned and no memory leaks occur 
//
#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "BST.h"

	void Tree::displayBST(Node* node, int level)
	{
		if (node)
		{
			displayBST(node->rightNode, level+1);
			for (int i = 0; i < level; i++)
				cout << "    "; // 4 spaces
			cout << setw(4) << node->item << endl;
			displayBST(node->leftNode, level+1);
		}
	}
	 void Tree::deleteKey(Node* root, int key)
	 {
		 if(!root)
			 return;
		 else if(key < root->item)
			 deleteKey(root->leftNode, key);
		 else if(key > root->item)
			 deleteKey(root->rightNode, key);
		 else
			 deleteNode(root);
	 }
	void Tree::replace(Node* root, Node* child)
	{
		if(root != this->root)
		{
			if(root->parent->leftNode == root)
			{
				root->parent->leftNode = child;
			}
			else
				root->parent->rightNode = child;
		}
		else
		{
			root->item = child->item;
		}

	}
	void Tree::deleteNode(Node* root)
	 {
		 
		 if(root->leftNode != nullptr && root->rightNode == nullptr)
		 {
			replace(root, root->leftNode);
			if(root->parent){
				Node* parent = root->parent;
				delete root;
				checkBalance(parent);
			}
			else{
				delete root->leftNode;
				checkBalance(root);
			}
				
		 }
		 else if(root->leftNode == nullptr && root->rightNode !=nullptr)
		 {
			replace(root, root->rightNode);
			if(root->parent){
				Node* parent = root->parent;
				delete root;
				checkBalance(parent);
			}
			else{
				delete root->rightNode;
				checkBalance(root);
			}
		 }
		 else if(root->leftNode != nullptr && root->rightNode != nullptr)
		 {
			int i = rand() %2;
			Node* replace;
			if(i == 0)
			{
				replace = maxLeft(root);
				root->item = replace->item;
			}
			else
			{
				replace = minRight(root);
				root->item = replace->item;
			}
			deleteNode(replace);
		 }
		 else
		 {
			 if(root != this->root)
			 {
				 if(root->parent->leftNode == root)
				 {
					 root->parent->leftNode = nullptr;
					 Node* parent = root->parent;
					 delete root;
					 checkBalance(parent);
				 }
				 else
				 {
					 root->parent->rightNode = nullptr;
					 Node* parent = root->parent;
					 delete root;
					 checkBalance(parent);
				 }
			 }
			 else
			 {
				 delete root;
				 cout << "no items in tree";
			 }
		}
	 }
	 void Tree::insert(Node* node, int value) 
	{
		if (value < node->item) 
		{
			if (node->leftNode == NULL)
			{
				node->leftNode = new Node(value);
				node->leftNode->parent = node;
				checkBalance(node->leftNode);
			}
			else
				insert(node->leftNode, value);
		}
		else if(value > node->item){
			if(node->rightNode == NULL)
			{
				node->rightNode = new Node(value);
				node->rightNode->parent = node;
				checkBalance(node->rightNode);
			}
			else
				insert(node->rightNode, value);
		}
		else
			cout << "already inserted" << endl;
	 }
	 void Tree::leftRightRotate(Node* pivot)
	 {
		 Node* middle = pivot->leftNode;
		 Node* last = middle->rightNode;
		 pivot->leftNode = last;
		 		 if(last->leftNode){
			 middle->rightNode = last->leftNode;
		 }
		 else{
			 middle->rightNode = nullptr;
		 }
		 last->leftNode = middle; 
		 middle->parent = last; 
		 last->parent = pivot;
		 leftLeftRotate(pivot);
	 }
	 void Tree::leftLeftRotate(Node* pivot)
	 {
		 Node* middle = pivot->leftNode;
		 Node* last = middle->leftNode;
		 swapKeys(pivot,middle);
		 pivot->leftNode = last;
		 last->parent = pivot;
		 if(pivot->rightNode == nullptr){
			pivot->rightNode = middle;
			 middle->parent = pivot;
			if(middle->rightNode){
				middle->leftNode = middle->rightNode;
				middle->rightNode = nullptr;
			}
			 else{
				  middle->leftNode = nullptr;
			}
		 }
		 else{
			 if(middle->rightNode){
				 middle->leftNode = middle->rightNode;
				 middle->rightNode = pivot->rightNode;
			 }
			 else{
				 middle->rightNode = pivot->rightNode;
				 middle->leftNode = nullptr;
			 }
			 pivot->rightNode = middle;
			 middle->parent = pivot;
			 middle->rightNode->parent = middle;
		 }
	 }
	 void Tree::rightLeftRotate(Node* pivot)
	 {
		 Node* middle = pivot->rightNode;
		 Node* last = middle->leftNode;
		 pivot->rightNode = last; 
		 if(last->rightNode){
			 middle->leftNode = last->rightNode;
		 }
		 else{
			 middle->leftNode = nullptr;
		 }
		 last->rightNode = middle; 
		 middle->parent = last; 
		 last->parent = pivot; 
		 rightRightRotate(pivot);
	 }
	 void Tree::rightRightRotate(Node* pivot)
	 {
		 Node* middle = pivot->rightNode;
		 Node* last = middle->rightNode;
		 swapKeys(pivot,middle);
		 pivot->rightNode = last;
		 last->parent = pivot;
		 if(pivot->leftNode == nullptr){
			pivot->leftNode = middle;
			 middle->parent = pivot;
			if(middle->leftNode){
				middle->rightNode = middle->leftNode;
				middle->leftNode = nullptr;
			}
			 else{
				  middle->rightNode = nullptr;
			}
		 }
		 else{
			 if(middle->leftNode){
				 middle->rightNode = middle->leftNode;
				 middle->leftNode = pivot->leftNode;
			 }
			 else{
				 middle->leftNode = pivot->leftNode;
				 middle->rightNode = nullptr;
			 }
			 pivot->leftNode = middle;
			 middle->parent = pivot;
			 middle->leftNode->parent = middle;
		 }
	 }
	 
	 
	 void Tree::checkBalance(Node* root)
	 {
		 
		 if(root->parent != nullptr)
		 {
			root->parent->height=root->height+1;
			setBalance(root);
			if(root->balance > 1 || root-> balance < -1)
			{
				
				//cout << "not balanced\t" << root->balance << endl;
				if(root->balance > 1)
				{
					if(root->rightNode->balance > 0)
					{
						rightRightRotate(root);
					}
					else
					{
						rightLeftRotate(root);
					}
				}
				else
				{
					if(root->leftNode < 0)
					{
						leftLeftRotate(root);
					}
					else
					{
						leftRightRotate(root);
					}
				}
			}
			if(root->parent != nullptr)
			{
				checkBalance(root->parent);
			}
		 }
		 else
		 {
			setBalance(root);
			if(root->balance > 1 || root-> balance < -1)
			{
				//cout << "not balanced\t" << root->balance << endl;
				if(root->balance > 1)
				{
					if(root->rightNode->balance > 0)
					{
						rightRightRotate(root);
					}
					else
					{
						rightLeftRotate(root);
					}
				}
				else
				{
					if(root->leftNode->balance < 0)
					{
						leftLeftRotate(root);
					}
					else
					{
						leftRightRotate(root);
					}
				}
			}
		 }
	 }
	
	 void Tree::setBalance(Node* root)
	 {
		 	 int left, right;
		
			 if (root->leftNode == nullptr)
				 left = 0;
			 else
				 left = root->leftNode->height;
			 if (root->rightNode ==nullptr)
				 right = 0;
			 else
				 right = root->rightNode->height;
			 root->balance= right - left;
	 }
	 void Tree::swapKeys(Node* root, Node* child)
	 {
		 int x = root->item;
		 int y = child-> item;
		 root->item = y;
		 child->item = x;
	 }
	 void Tree::deleteAll(Node* node)
	{
		if (node != nullptr)
		{
			deleteAll(node->leftNode);
			deleteAll(node->rightNode);
			delete node;
		}
	}
	Node* Tree::maxLeft(Node* root)
	{
		Node* maxLeft = root->leftNode;
		while(maxLeft->rightNode != nullptr)
		{
			maxLeft = maxLeft->rightNode;
		}
		return maxLeft;
	}
	Node* Tree::minRight(Node* root)
	{
		Node* minRight = root->rightNode;
		while(minRight->leftNode != nullptr)
		{
			minRight = minRight->leftNode;
		}	
		return minRight;
	}

	
	Tree::Tree(int num)
	{
		root = new Node(num);
	}

	void Tree::insert(int value)
	{
		if(root)
			insert(root, value);
		else
			this->root = new Node(value);
	}
	
	void Tree::deleteItem(int key)
	{
		deleteKey(root, key);
	}
	void Tree::displayBST()
	{
		displayBST(root, 0);
	}

	Tree::~Tree()
	{
		if(root == NULL)
			return;
		deleteAll(root);
	}

