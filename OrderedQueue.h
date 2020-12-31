#ifndef ORDEREDQUEUE_H
#define ORDEREDQUEUE_H
#include <iostream>
#include "HuffmanTree.h"
using namespace std;

class OrderedQueue
{
	private:
		T_Node** orderedQueue;

		int size;

		int front;
		int rear;

	public:
		OrderedQueue(int size);
		~OrderedQueue();

		void Enqueue(int freq, char Char);
		T_Node* Dequeue();

		int getFront();
		int getRear();

		T_Node* getFrontNode();

		bool IsFull();
		bool IsEmpty();
		void MakeNull();

		void QueueDisplay();

		bool InsertAsteriskInOrderedQueue(T_Node* asterisk);
};
#endif
