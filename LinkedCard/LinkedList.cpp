#include "LinkedList.h"
#include <cassert>
using namespace std;

template<class ItemType>
LinkedList<ItemType>::LinkedList(){
	size=0;
	trackSize=0;
	tail=NULL;
	head=NULL;
}


template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	Node* tmp=head;
	while(head!=NULL){
		tmp=head->next;
		delete head;
		head=tmp;
	}
}


template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
	if(size==0){
		return true;
	}
	return false;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
	return size;
}

template<class ItemType>
bool LinkedList<ItemType>::append(const ItemType& newEntry) {	
	Node* tmp=new Node();
	tmp->next=NULL;
	if(size==0){
		tmp->data=newEntry;
		head=tmp;
		tail=head;
	}
	else{	
		tmp->data=newEntry;
		tail->next=tmp;
		tail=tmp;
	}
	size++;
	return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int pos){
	if(pos<=0||pos>size){
		return false;
	}
	int counter;
    Node* tmp = head;
    for(counter=1; counter<pos-1; ++counter)
    {
        tmp = tmp->next;
        assert( tmp!= NULL );
    }
    Node* const del=tmp->next;
    assert( del != NULL );
    tmp->next = del->next;
    delete del;
    --size;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos,const ItemType & newEntry){
	int counter;
	int save=0;
	int tmpsave=0;
	
	if(newPos<=0||newPos>size+1){
		return false;
	}
	
	else if(size==0){
		append(newEntry);
	}
	
	else if(newPos==size+1){
		Node* tmp=new Node();
		tmp->data=newEntry;
		tail->next=tmp;
		tail=tmp;	
		size++;
	}
	
	else if(newPos==size){
		Node* tmp=tail;
		save=tmp->data;
		tmp->data=newEntry;
		append(save);
	}
	
	else{
		Node* tmp=head;		
		
		for(counter=1;counter<newPos;counter++){
			tmp=tmp->next;
		}
		
		save=retrieve(newPos);
		tmp->data=newEntry;
		
		for(counter=0;counter<=size-newPos;counter++){
			tmpsave=save;
			tmp=tmp->next;
			if(tmp==NULL){
				append(save);
			}
			else{
				save=retrieve(++newPos);
				tmp->data=tmpsave;
			}
		}
		size++;
	}
	return true;
}

template<class ItemType>
ItemType LinkedList<ItemType>::retrieve(int position) const {
	int counter=1;
	Node* tmp=head;
	while(tmp!=NULL){
		if(counter==position)	return tmp->data;
		tmp=tmp->next;
		counter++;
	}
}

template<class ItemType>
void LinkedList<ItemType>::moveToStart(){
	trackSize=1;
}

template<class ItemType>
void LinkedList<ItemType>::next(){
	trackSize++;
}

template<class ItemType>
bool LinkedList<ItemType>::pastTheEnd() const{
	if(trackSize>size){
		return true;
	}
	return false;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getCurrentItem() const{
	assert(size>=trackSize);
	return retrieve(trackSize);
}
	
	

