#include "Note.h"
#include <iostream>

Node::Node(int data) : _data(data), next(nullptr), prev(nullptr) {};

int Node::GetData()
{
	return _data;
}

Node::~Node()
{
	//printf("Node delete\n"); // ����������� ����������� iostream 
	std::cout << "Node delete" << "\n";

}