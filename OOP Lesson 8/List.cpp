#include  "List.h"
#include <iostream>

List::List() : _head(nullptr), _tail(nullptr), _size(0){}

void List::AddTail(int data)
{
	Node* node{ new Node(data) };
	//Node* node = new Node(data)

	if (AddMain(node)) return;

	_size++;
	
	node->next = _tail;
	_tail->prev = node;
	_tail = node;
}

void List::AddHead(int data)
{
	Node *newHead{ new Node(data) };
	if (AddMain(newHead)) return;

	_size++;

	/*if (_head == nullptr)
	{
		_head = newNode;
		_tail = newNode;
		return;
	}*/
	_head->next = newHead;
	newHead->prev = _head;
	_head = newHead;
}

bool List::AddMain(Node* node)
{
	if (_head != nullptr) return false;

	_head = node;
	_tail = node;
	_size++;

	return true;
}

void List::ShowListFromHead()
{
	for (Node* node = _head; node != _tail->prev; node = node->prev)
		std::cout << node->GetData() << "\n";
}

void List::ShowListFromTail()
{
	if (_size == 0)
	{
		std::cout << "Not elements" << "\n";
		return;
	}

	for (Node* node = _tail; node != nullptr; node = node->next)
		std::cout << node->GetData() << "\n";
}

void List::DeleteAll()
{
	for (Node* node = _tail; node != nullptr; )
	{
		Node *temp = node;
		node = node->next;
		delete(temp);
		_size--;
	}
		
}

void List::DeleteElement(int index)
{
	if (index > _size || index < 0) return;

	if (index = _size)
	{
		Node* temp = _tail;
		_tail = _tail->next;
		delete(temp);
		_size--;
		return;
	}
	
	else if (index == 1)
	{
		Node* temp = _head;
		_head = _head->prev;
		delete(temp);
		_size--;
		return;
	}
	Node *nextNode = FindElement(index + 1);
	Node* prevNode = FindElement(index - 1);
	Node* deleteNode = FindElement(index);

	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	delete(deleteNode);
}

Node *List::FindElement(int index)
{
	
	Node* node = _head;
	index--;
	while (index != 0)
	{
		node = node->prev;
		index--;
	}
	return (node);

}