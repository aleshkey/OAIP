#pragma once
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;


struct node
{
	int info;
	string name;
	node* left;
	node* right;
	int balance;
};

int Height(node* root);

int Task(node* search_node, int count);

void SetBalance(node* (&root));

void TurnRight(node* (&root));

void TurnLeft(node* (&root));

void Insert(node* (&root), int d, string name);

void PrintInorder(node* root);

void PrintPreorder(node* root);

void Delete(int x, node* (&root));

void Clear(node* (&p));

node* Search(node* root, int value);

void View_Tree(node* p, int level);

#endif