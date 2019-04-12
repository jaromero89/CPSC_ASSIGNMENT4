#include <iostream>
#ifndef LISTNODE_H
#define LISTNODE_H
using namespace std;

template <typename T>
class GenDoublyLinkedList;

template <class T>
class GenQueue;

template <typename T>
class GenNode {

template <class T> class ListNode
{
public:
	ListNode();
	ListNode(T d);
	~ListNode();

private:
	T data;
	ListNode *previous;
	ListNode *next;
	ListNode *header;

	friend class GenDoublyLinkedList<T>;
	friend class GenQueue<T>;
  friend class TrafficFlowManager;

};
//implementation
template <class T> ListNode<T>::ListNode() //default constructor
{
	data = NULL;
	next = NULL;
	previous = NULL;
}
template <class T> ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	previous = NULL;
}
template <class T> ListNode<T>::~ListNode()
{ //no delete, set pointers to null
	next = NULL;
	previous = NULL;
}
#endif
