#include <iostream>
#include "ListNode.h"
#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H
using namespace std;
//Citation: https://codereview.stackexchange.com/questions/172527/c-doubly-linked-list-implementation?rq=1

template <class T> class GenDoublyLinkedList
{
protected:
	ListNode<T> *front;
	ListNode<T> *back;
	unsigned int size;
public:
	GenDoublyLinkedList();
	~();
	void insertFront(T d);
	void insertBack(T d);
	T removeFront();
	T removeBack();
	T remove(T key);
	T deletePos(int pos);
	T getFront();
	T getBack();
	void printList();
	int find(T val);
	unsigned int getSize();
};

//implementation
template <class T> GenDoublyLinkedList<T>::GenDoublyLinkedList()
{
	size = 0; //blank list(new)
	front = NULL;//Set both front and back to NULL
	back = NULL;
}

template <class T> GenDoublyLinkedList<T>::~GenDoublyLinkedList()
{
	while (size!=0)
	{
		removeFront();
	}
	delete front;
	delete back;
}

template <class T> T GenDoublyLinkedList<T>::getFront()
{
	return this->front->data;
}

template <class T> T GenDoublyLinkedList<T>::getBack()
{
	return this->back->data;
}

template <class T> unsigned int GenDoublyLinkedList<T>::getSize()
{
	return this->size;
}

template <class T> void GenDoublyLinkedList<T>::printList()
{
	ListNode<T> *current = front;
	while(current)
	{
		cout << current->data;
		current = current->next;
	}
}

template <class T> void GenDoublyLinkedList<T>::insertFront(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
	if(size == 0)
	{
		back = node;
		front = back;
	}
	else //not empty
	{
		node->next = front;
		front->previous = node;
	}
	front = node;
	size++;
}

template <class T> void GenDoublyLinkedList<T>::insertBack(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
	if(size == 0)
		front = node;
	else
	{
		back-> next = node;
		node->previous = back;
	}
	back = node;
	size++;
}

template <class T> T GenDoublyLinkedList<T>::removeFront()
{
	//check empty
	try
	{
		if(size == 0)
			throw "Error. List is empty";
		ListNode<T> *node = front;
		//check if only one element exiss
		if(node->next == NULL)
			back = NULL;
		else
			node->next->previous = NULL;
		front = front-> next;
		node->next = NULL;
		T temp = node-> data;
		delete node;
		size--;
		return temp;
	}
	catch(char const* s)
	{
		cout << s << endl;
	}
}

template <class T> T GenDoublyLinkedList<T>::removeBack()
{
	//check empty
	try
	{
		if(size == 0)
			throw "Error. List is empty";
		ListNode<T> *node = back;
		//check if only one element exiss
		if(node->previous == NULL)
			front = NULL;
		else
			node->previous->next = NULL;
		back = back->previous;
		T temp = node->data;
		node->previous = NULL;
		delete node;
		size--;
		return temp;
	}
	catch(char const* s)
	{
		cout << s << endl;
	}
}

template <class T> T GenDoublyLinkedList<T>::remove(T key)
{
	try
	{
		ListNode<T> *current = front;
		//look for it
		while(current->data!=key)
		{
			current = current -> next;
			if(current == NULL)
				throw key;
		}
		if(current == front)//front node
		{
			front = current->next;
		}
		else
		{
			current->previous->next = current->next;
			//current->next->previous = current->previous;
		}
		if(current == back)
		{
			back = current->previous;
		}
		else
		{
			current->next->previous = current->previous;
		}
		current->next = NULL;
		current->previous = NULL;
		--size;
		return current->data;
	}
	catch(T error)
	{
		cout << "Error. Value '" << error << "' not found in list" << endl;
	}
}

//return the position if value exists
template <class T> int GenDoublyLinkedList<T>::find(T val)
{
	int idx = -1;
	ListNode<T> *current = front;
	while(current != NULL)
	{
		++idx;
		if(current->data == val) //found the
		{
			break;
		}
		else
		{
			current = current->next;
		}
	}
	if(current == NULL)
		idx = -1;
	return idx;
}

template <class T> T GenDoublyLinkedList<T>::deletePos(int pos)
{
	try
	{
		if(pos < 0) //check to make sure position is valid (check for negative positions)
			throw "Error. Can't have negative position";
		if(pos > size)
			throw "Error. Position is beyond size of list";
		int idx = 0;
		ListNode<T> *current = front;
		ListNode<T> *previous = front;
		while(idx != pos)
		{
			previous = current; //stay back
			current = current->next;
			++idx;
		}
		//when we find correct position, update pointers
		previous->next = current->next;
		current->next = NULL;
		T temp = current->data;
		delete current;
		--size;
		return temp;
	}
	catch(char const* s)
	{
		cout << s << endl;
	}
}
#endif
