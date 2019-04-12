#include <iostream>
#include "ListNode.h"
#include "GenDoublyLinkedList.h"
#ifndef GENQUEUE_H
#define GENQUEUE_H
//Citation: Built in class/Data Structures TextBook
using namespace std;

template <class T> class GenQueue
{
protected:
	DoublyLinkedList<T> *list;
	unsigned int size;
public:
	GenQueue();
	~GenQueue();
	void insert(T data);
	T remove();
	T front();
	unsigned int getSize();
	bool isEmpty();
};

//implementation
template <class T> GenQueue<T>::GenQueue()
{
	list = new DoublyLinkedList<T>();
	size = 0;
}

template <class T> GenQueue<T>::~GenQueue()
{
	while(!isEmpty())
	{
		this->remove();
	}
	delete list;
}

template <class T> void GenQueue<T>::insert(T data)
{
	list->insertBack(data);
	size++;
}

template <class T> T GenQueue<T>::remove()
{
	try
	{
		if(size == 0)
			throw "Queue is empty. Can't remove elements";
		T temp = list->removeFront();
		size--;
		return temp;
	}
	catch(char const* s)
	{
		cout << s << endl;
	}
}

template <class T> T GenQueue<T>::front()
{
	try
	{
		if(size == 0)
			throw "Queue is empty. Can't return front";
		T temp = list->getFront();
		return temp;
	}
	catch(char const* s)
	{
		cout << s << endl;
	}
}

template <class T> unsigned int GenQueue<T>::getSize()
{
	return size;
}

template <class T> bool GenQueue<T>::isEmpty()
{
	if(size == 0)
		return true;
	else
		return false;
}
#endif
