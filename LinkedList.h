#ifndef CHARLINKEDLIST_H
#define CHARLINKEDLIST_H
#include <iostream>
#include "OrderedQueue.h"
using namespace std;

struct LL_Node
{
	public:
		LL_Node* next;

		char Character;
		int Frequency;
};
class CharLinkedList
{
	private:
		LL_Node* head;
		LL_Node* tail;
		LL_Node* current;

	public:
		CharLinkedList();
		~CharLinkedList();

		LL_Node* getHead();

		void setHead(LL_Node* Head);

		void InsertUniqueCharacters(char Char, int &TotalUniqueCharacters);

		void Frequency_Display();

		LL_Node* Sorting(LL_Node* Head);

		LL_Node* FindMiddleNode(LL_Node* Head);

		LL_Node* Merge2LinkedLists(LL_Node* first, LL_Node* second);

		void IntroducetoOrderedQueue(OrderedQueue *OQ);
};
#endif
