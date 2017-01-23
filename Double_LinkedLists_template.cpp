#include <iostream>
#include "Double_LinkedLists.h"

int main() {
	LinkList<int> first;
	first.Push_front(11);
	first.Push_front(10);
	first.Push_front(9);
	first.Push_front(8);
	first.Push_back(12);
	first.Push_back(13);
	first.Push_back(14);
	first.Reverse();
	first.Delete(14);
	first.Delete(8);
	//first.Reverse();
	first.PrintList();

	LinkList<char> first1;
	first1.Push_front('d');
	first1.Push_front('c');
	first1.Push_front('b');
	first1.Push_front('a');
	first1.Push_back('e');
	first1.Push_back('f');
	first1.Push_back('g');
	first1.Delete('b');
	first1.Delete('g');
	//first1.Reverse();
	first1.PrintList();

	system("pause");
	return 0;
}