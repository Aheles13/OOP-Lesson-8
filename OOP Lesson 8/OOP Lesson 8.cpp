#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "List.h"


int main() {
	setlocale(LC_ALL, "Ru");


	List list;
	list.AddHead(10);
	list.AddTail(20);
	list.AddTail(69);
	list.AddTail(14);
	list.AddTail(13);
	list.ShowListFromHead();
	std::cout << "\n";
	//list.ShowListFromTail();

	list.DeleteElement(2);
	list.ShowListFromHead();


	return 0;
}
