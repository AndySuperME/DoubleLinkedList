#ifndef DOUBLE_LINKEDLISTS_H
#define DOUBLE_LINKEDLISTS_H

using std::cout;
using std::endl;

template <class T>
class LinkList;

template <class T>
class Node
{
	friend class LinkList<T>;
public:
	Node() :Data(0), llink(0), rlink(0) {};
	Node(T a) :Data(a), llink(0), rlink(0) {};
private:
	T Data;
	Node<T> *llink;
	Node<T> *rlink;
};

template <class T>
class LinkList
{
public:
	LinkList() :first(0) {};
	void PrintList();
	void Push_front(T);
	void Push_back(T);
	void Delete(T);
	void Reverse();
	Node<T> *GetLast();
private:
	Node<T> *first;
};


template <class T>
void LinkList<T>::PrintList()
{
	if (first == 0)
	{
		cout << "List is empty!" << endl;
		return;
	}

	Node<T> *current = first;
	while (current->rlink != first && current->rlink != 0)
	{
		cout << current->Data << " ";
		current = current->rlink;
	}
	cout << current->Data << endl;
}

template <class T>
void LinkList<T>::Push_front(T x)
{
	Node<T> *newnode = new Node<T>(x);
	Node<T> *tmp;
	if (first == 0)
	{
		first = newnode;
		return;
	}

	if (first->rlink == 0)
	{
		newnode->llink = first;
		newnode->rlink = first;
		first->rlink = newnode;
		first->llink = newnode;
		tmp = first;
		first = newnode;
		newnode = tmp;
	}
	else
	{
		newnode->llink = GetLast();
		GetLast()->rlink = newnode;
		newnode->rlink = first;
		first->llink = newnode;
		tmp = first;
		first = newnode;
		newnode = tmp;
	}
}

template <class T>
void LinkList<T>::Push_back(T x)
{
	Node<T> *newnode = new Node<T>(x);
	if (first == 0)
	{
		first = newnode;
		return;
	}

	if (first->rlink == 0)
	{
		newnode->rlink = first;
		newnode->llink = first;
		first->rlink = newnode;
		first->llink = newnode;
	}
	else
	{
		newnode->llink = GetLast();
		GetLast()->rlink = newnode;
		newnode->rlink = first;
		first->llink = newnode;
	}

}

template <class T>
void LinkList<T>::Delete(T x)
{
	if (first == 0)
	{
		cout << "The list is empty !!" << endl;
		return;
	}

	Node<T> *current = first,
		*tmp = GetLast();
	while (current->rlink != first)
	{
		if (x == current->Data && x == first->Data)
		{
			tmp->rlink = current->rlink;
			current->rlink->llink = tmp;
			first = current->rlink;
			break;
		}
		else if (x == current->Data)
		{
			current->rlink->llink = current->llink;
			current->llink->rlink = current->rlink;
			break;
		}
		current = current->rlink;
	}

	if (current->rlink != first)
	{
		delete current;
		return;
	}
	if (x == current->Data)
	{
		current->llink->rlink = first;
		first->llink = current->llink;
	}
	delete current;
}

template <class T>
void LinkList<T>::Reverse()
{
	Node<T> *current = first,
		*tmp;
	while (current->rlink != first)
	{
		tmp = current->llink;
		current->llink = current->rlink;
		current->rlink = tmp;
		current = current->llink;
	}
	current->rlink = current->llink;
	current->llink = first;
	first = current;
}

template <class T>
Node<T>* LinkList<T>::GetLast()
{
	Node<T> *current = first;
	while (current->rlink != first)
	{
		current = current->rlink;
	}
	return current;
}

#endif
