#include <iostream>
using namespace std;
//Citation:Data Structures TextBook
//Citation: https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions?view=vs-2019
template <class T> class GenLinkedList
{
public:
	GenLinkedList();

	virtual ~GenLinkedList();

	virtual void insertFront(T d) = 0;
	virtual void insertBack(T d) = 0;

	virtual T removeFront() = 0;
	virtual T removeBack() = 0;
	virtual T remove(T key) = 0;
	virtual T deletePos(int pos) = 0;

  virtual void printList() = 0;
	virtual int find(T val) = 0;
	virtual unsigned int getSize() = 0;
};
