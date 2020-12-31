#include <iostream>
#include "LinkedList.h"
using namespace std;

CharLinkedList::CharLinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
CharLinkedList::~CharLinkedList()
{
	current = head;

	LL_Node *nextNode = NULL;

	while(current != NULL)
	{
		nextNode = current->next;

		delete current;

		current = nextNode;
	}
}
LL_Node* CharLinkedList::getHead()
{
	return head;
}
void CharLinkedList::setHead(LL_Node* Head)
{
	head = Head;
}
void CharLinkedList::InsertUniqueCharacters(char Char, int &TotalUniqueCharacters)
{
	if(head == NULL)
	{
		LL_Node *new_node = new LL_Node;

		new_node->Character = Char;

		new_node->Frequency = 1;

		TotalUniqueCharacters++;

		head = new_node;

		tail = new_node;

		tail->next = NULL;
	}
	else
	{
		current = head;

		while(current != NULL)
		{
			if(current->Character == Char)
			{
				current->Frequency++;

				break;
			}
			if(current->next == NULL)
			{
				LL_Node *new_node = new LL_Node;

				new_node->Character = Char;

				new_node->Frequency = 1;

				TotalUniqueCharacters++;

				tail->next = new_node;

				tail = new_node;

				tail->next = NULL;

				break;
			}

			current = current->next;
		}
	}
}
void CharLinkedList::Frequency_Display()
{
	current = head;

	while(current != NULL)
	{
		cout << endl << endl << current->Character << " : " << current->Frequency;

		current = current->next;
	}
}
LL_Node* CharLinkedList::FindMiddleNode(LL_Node* Head)
{
	LL_Node* slow = Head;

	LL_Node* fast = Head;

	while(fast->next != NULL)
	{
		if(fast->next->next == NULL)
		{
			fast = fast->next;
		}
		else
		{
			slow = slow->next;

			fast = fast->next->next;
		}
	}

	return slow;
}
LL_Node* CharLinkedList::Merge2LinkedLists(LL_Node* first, LL_Node* second)
{
	LL_Node* headofSortedLL = NULL;

    if(first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }
    if(first->Frequency <= second->Frequency)
    {
    	headofSortedLL = first;

    	headofSortedLL->next = Merge2LinkedLists(first->next, second);
    }
    else
    {
    	headofSortedLL = second;

    	headofSortedLL->next = Merge2LinkedLists(first, second->next);
    }

    return headofSortedLL;
}
LL_Node* CharLinkedList::Sorting(LL_Node* Head)
{
	if((Head == NULL) || (Head->next == NULL))
	{
		return Head;
	}

	LL_Node* Middle = FindMiddleNode(Head);
	LL_Node* Middle_Next = Middle->next;

	Middle->next = NULL;

	LL_Node* first = Sorting(Head);
	LL_Node* second = Sorting(Middle_Next);

	LL_Node* SortedLL = Merge2LinkedLists(first, second);

	return SortedLL;
}
void CharLinkedList::IntroducetoOrderedQueue(OrderedQueue *oq)
{
	current = head;
	LL_Node* Current;

	while(current != NULL)
	{
		Current = current;

		oq->Enqueue(current->Frequency, current->Character);

		current = current->next;

		head = current;

		delete Current;
	}
}
