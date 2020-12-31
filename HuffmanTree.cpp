#include <iostream>
#include <fstream>
#include "HuffmanTree.h"
#include "OrderedQueue.h"
using namespace std;

HuffmanTree::HuffmanTree()
{
	root = NULL;
}
HuffmanTree::~HuffmanTree()
{

}
T_Node* HuffmanTree::Make_BT_Node(char Char, int Freq)
{
	T_Node* new_node = new T_Node;

	new_node->left = NULL;
	new_node->right = NULL;

	new_node->Character = Char;
	new_node->Frequency = Freq;

	return new_node;
}
void HuffmanTree::BuildHuffmanTree(OrderedQueue* oq, int casenum)
{
	bool flag = false;

	if(casenum == 5)
	{
		cout << "\n---------------------------------------------------------\n\nBelow is Ordered Queue, after each iteration, while building Huffman Tree. 1st row, show Ordered Queue at Start\n\nCharacter : Frequency Character : Frequency ............ at each node of Ordered Queue\n\n";

		oq->QueueDisplay();
	}

	while(flag != true)
	{
		T_Node* asterisk = new T_Node;

		asterisk->Character = '*';

		asterisk->left = oq->Dequeue();

		asterisk->right = oq->Dequeue();

		asterisk->left->code = '0';
		asterisk->right->code = '1';

		asterisk->Frequency = asterisk->left->Frequency + asterisk->right->Frequency;

		flag = oq->InsertAsteriskInOrderedQueue(asterisk);

		if(casenum == 5)
		{
			cout << endl << endl;

			oq->QueueDisplay();
		}
	}

	root = oq->getFrontNode();
}
void HuffmanTree::HT_Display(T_Node* node)
{
	if(node == NULL)
	{
		return;
	}

	HT_Display(node->left);

	cout << node->Character << " : " << node->Frequency << endl << endl;

	HT_Display(node->right);
}
T_Node* HuffmanTree::getRoot()
{
	return root;
}
void HuffmanTree::CodeGenerator(T_Node* node, string Code, HuffmanTable &hTable)
{
	if(node == NULL)
	{
		return;
	}

	if(node != root)
	{
		Code+=(node->code);
	}

	CodeGenerator(node->left, Code, hTable);

	if(node->Character != '*')
	{
		hTable.Insert(node->Character, Code);
	}

	CodeGenerator(node->right, Code, hTable);
}
int HuffmanTree::ArraySearch(int arr[], int charnum, int linenum)
{
	if(charnum == arr[linenum])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void HuffmanTree::ReconstructFile(string EncodedFileName, string ReconstructedFileName, int extra, int* arr)
{
	int CHARnum = 0;

	int linenum = 0;

	T_Node* NODE = root;

    string decoded = "";

	char Char;
	int ASCII = -1, i=0, k=0, l=6;

	int Remainder = 0, charnum = 0;

	char intChar;

	string Binary = "";
	string EncodedSymbols = "";

	ifstream Symbols(EncodedFileName);
	ofstream Reconstruct(ReconstructedFileName, ios::app);

	/*---------------------------------------------------*/

	while(!Symbols.eof())
	{
		getline(Symbols, EncodedSymbols);

		i = 0;

		while(EncodedSymbols[i] != '\0')
		{
			Char = EncodedSymbols[i];

			ASCII = (int)Char;

			if(ASCII < 0)
			{
				ASCII = ASCII + 32;
			}

			while(k < 7)
			{
				Remainder = ASCII % 2;

				intChar = Remainder + 48;

				Binary+=intChar;

				ASCII = ASCII / 2;

				k++;
			}

			while(l >= 0)
			{
			    while((NODE->left != NULL) && (NODE->right != NULL))
			    {
			    	if(Binary[l] == '0')
			        {
			    		NODE = NODE->left;
			        }
			        if(Binary[l] == '1')
			        {
			        	NODE = NODE->right;
			        }

			        l--;

			        if(l < 0)
			        {
			        	break;
			        }
			    }

		        if(l < 0)
		        {
		        	break;
		        }
		        else
		        {
		        	Reconstruct << NODE->Character;

		        	charnum++;

		        	NODE = root;

		        	if(charnum == extra)
		        	{
		        		break;
		        	}

		        	CHARnum++;

		        	if(ArraySearch(arr, CHARnum, linenum))
		        	{
		        		Reconstruct << endl;

		        		CHARnum = 0;

		        		linenum++;
		        	}

		        	//decoded+=(NODE->Character);
		        }
			}

			l = 6;

			Binary = "";

			k = 0;

			i++;
		}

		//Reconstruct << decoded;
	}

    Reconstruct.close();

	Symbols.close();
}
