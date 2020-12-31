#include <iostream>
#include "OrderedQueue.h"
using namespace std;

OrderedQueue::OrderedQueue(int Size)
{
	orderedQueue = new T_Node *[Size];
	size = Size;

	front = -1;
	rear = -1;
}
OrderedQueue::~OrderedQueue()
{
	for(int i=0; i<size; i++)
	{
		delete [] orderedQueue[i];
	}

	delete[] orderedQueue;
}
int OrderedQueue::getFront()
{
	return front;
}
int OrderedQueue::getRear()
{
	return rear;
}
void OrderedQueue::Enqueue(int freq, char Char)
{
	HuffmanTree HT;

	if(IsFull())
	{
		cout << "\nFrequency Queue is Full";

		return;
	}
	if(IsEmpty())
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear = (rear + 1) % size;
	}

	orderedQueue[rear] = HT.Make_BT_Node(Char, freq);
}
T_Node* OrderedQueue::Dequeue()
{
	if(IsEmpty())
	{
		cout << "Can't Dequeue, as Queue is Empty";

		return NULL;
	}

	T_Node* node = orderedQueue[front];

	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % size;
	}

	return node;
}
bool OrderedQueue::IsFull()
{
	if(((rear + 1) % size) == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool OrderedQueue::IsEmpty()
{
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void OrderedQueue::MakeNull()
{
	front = -1;
	rear = -1;
}
void OrderedQueue::QueueDisplay()
{
	int i = front;

	while(i < rear+1)
	{
		cout << orderedQueue[i]->Character << " : " << orderedQueue[i]->Frequency <<  " ";

		i++;
	}
}
bool OrderedQueue::InsertAsteriskInOrderedQueue(T_Node* asterisk)
{
	if(front == -1)
	{
		front = size - 1;

		rear = size - 1;

		orderedQueue[front] = asterisk;

		return true;
	}
	else
	{
		int i = front;

		while(i < rear+1)
		{
			if(asterisk->Frequency <= orderedQueue[i]->Frequency)
			{
				if(i == front)
				{
					front--;

					orderedQueue[front] = asterisk;

					break;
				}
				else
				{
					int j = front;

					front--;

					while(j < i)
					{
						orderedQueue[j - 1] = orderedQueue[j];

						j++;
					}

					orderedQueue[i - 1] = asterisk;

					break;
				}
			}

			i++;
		}

		if(i == rear+1)
		{
			int k = front;

			while(k < rear+1)
			{
				orderedQueue[k - 1] = orderedQueue[k];

				k++;
			}

			front--;

			orderedQueue[rear] = asterisk;
		}

		return false;
	}
}
T_Node* OrderedQueue::getFrontNode()
{
	return orderedQueue[front];
}
