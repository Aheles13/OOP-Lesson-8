#pragma once

#include "Note.h"
class List
{
private:
	Node *_head;
	Node* _tail;
	int _size;


	bool AddMain(Node *Node);
public:
	List();

	void AddTail(int data);

	void AddHead(int data);

	void ShowListFromHead();

	void ShowListFromTail();

	void DeleteAll();

	void DeleteElement(int index);

	Node* FindElement(int index);
};