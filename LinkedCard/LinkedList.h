#ifndef LINKED_LIST_
#define LINKED_LIST_
#include "ListInterface.h"

template<class ItemType>

class LinkedList{

public:
	~LinkedList();
	LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool append(const ItemType & newEntry);
	bool insert(int newPos,const ItemType & newEntry);
	bool remove(int pos);
	ItemType retrieve(int position) const;
	void moveToStart();
	void next();
	bool pastTheEnd() const;
	ItemType getCurrentItem() const;
	
private:
	struct Node{
		Node* next;
		ItemType data;
	}; 
	Node* head;
	Node* tail;
	int size;
	int trackSize;
};
#endif
