#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "BST.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Tree* BST = new Tree(7);
	for(int i = 0; i < 10; ++i)
	{
		BST->insert(rand() % 10);
	}
	BST->insert(20);
	BST->displayBST();
	delete BST;
	system("PAUSE");
}
