#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

//declare the node structure
template <typename T>
struct ListNode
{
	T data;    //the data
	ListNode<T>* next;  //the pointer to (address of) the next node 
};


template <typename T>
class LinkedList
{
public:
	//constructor
	LinkedList()
	{
		head = nullptr; //head points to null
		lsize = 0;
	}

	//list operations

	void insert_at(int k, T x);
	//insert the element x at position k
	//keeping with c++ tradition, the counting starts at 0
	//i.e., insert_at(0, x) will imply that x is inserted at the beginning
	//insert_at(1,x) : x is inserted after the first element etc.
	// if k is negative or larger than the size of the list, insert at the end
	//e.g., if list L={10,15,25,40,-50}
	//L.insert_at(0,200) will result in L={200,10,15,25,40,-50}, next
	//L.insert_at(2,-33) will result in L={200,10,-33, 15,25,40,-50}, next
	//L.insert_at(-1,4000) will result in L={200,10,-33, 15,25,40,-50, 4000}


	void remove_at(int k);
	//remove the node at position k
	//keeping with c++ tradition, the counting starts at 0
	//i.e., remove(0) will imply the first element in the list is removed (index 0)
	// if k is negative or larger than the size of the list, do nothing
	//e.g., if list L={10,15,25,40,-50}
	//L.remove_at(0) will result in L={15,25,40,-50}, next
	//L.remove_at(2) will result in L={15,25,-50}, next
	//L.remove_at(10) will result in L={15,25,-50}


	bool isSorted() const;
	//return true if the elements in the list are sorted (in ascending order)

	void print() const;
	//print the contents of the list

	//destructor
	~LinkedList();

private:
	ListNode<T>* head;  //pointer to the first element
	int lsize; //the number of elements in the list
};


template <typename T>
void LinkedList<T>::print() const
{
	cout << "{";
	ListNode<T>* walker = head; //create a pointer that will "walk" to the end of the list
	while (walker != nullptr)  //walker is not the last element
	{
		cout << walker->data << ", "; //print the data field of the current node
		walker = walker->next;  //move to the next node
	}
	cout << "}";
}

//destructor

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* walker = head;
	while (walker != nullptr)
	{
		ListNode<T>* temp = walker;
		walker = walker->next;
		delete temp;
	}
}


//////////////////////implement the functions below///////////////////////////////

template <class T>
void LinkedList<T>::insert_at(int k, T x)
{

}



template <class T>
void LinkedList<T>::remove_at(int k)
{

}

template <class T>
bool LinkedList<T>::isSorted() const
{

}




#endif


