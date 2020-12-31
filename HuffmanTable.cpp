#include <iostream>
#include <fstream>
#include "HuffmanTable.h"
using namespace std;

HuffmanTable::HuffmanTable()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
HuffmanTable::~HuffmanTable()
{
	current = head;

	HT_Node *nextNode = NULL;

	while(current != NULL)
	{
		nextNode = current->next;

		delete current;

		current = nextNode;
	}
}
void HuffmanTable::Insert(char Char, string code)
{
	if(head == NULL)
	{
		HT_Node *new_node = new HT_Node;

		new_node->Character = Char;

		new_node->Code = code;

		head = new_node;

		tail = new_node;

		tail->next = NULL;
	}
	else
	{
		current = head;

		while(current != NULL)
		{
			if(current->next == NULL)
			{
				HT_Node *new_node = new HT_Node;

				new_node->Character = Char;

				new_node->Code = code;

				tail->next = new_node;

				tail = new_node;

				tail->next = NULL;

				break;
			}

			current = current->next;
		}
	}
}
void HuffmanTable::hTable_Display()
{
	current = head;

	while(current != NULL)
	{
		cout << endl << endl << current->Character << " : " << current->Code;

		current = current->next;
	}
}
void HuffmanTable::GenerateEncodedFile(string FileDataString)
{
	int i = 0, k=0, total = 0;

	ofstream encoded("binaryencodings.txt", ios::app);

	while(FileDataString[i] != '\0')
	{
		HT_Node* node = head;

		while(node != NULL)
		{
			if(node->Character == FileDataString[i])
			{
				string Char = node->Code;

				int j = 0;

				while(Char[j] != '\0')
				{
					if(k == 7)
					{
						encoded << endl;

						k=0;
					}

					encoded << Char[j];

					total++;

					j++;
					k++;
				}

				break;
			}

			node = node->next;
		}

		i++;
	}

	int l = 7 - (k%7);

	while(l > 0)
	{
		encoded << '0';

		l--;
	}

	encoded.close();
}
void HuffmanTable::EncodingSymbols(string FileName)
{
	string encoding_string;

	ifstream Encoding("binaryencodings.txt");

	ofstream EncodedSymbols(FileName, ios::app);

	ofstream Decimals("encodedcharactersASCII.txt", ios::app);

	while(!Encoding.eof())
	{
		Encoding >> encoding_string;

	    int dec_val = 0;

	    int base = 1;

	    for (int i = 6; i >= 0; i--)
	    {
	        if(encoding_string[i] == '1')
	        {
	            dec_val+=base;
	        }

	        base*=2;
	    }

	    if(dec_val < 32)
	    {
	    	dec_val = dec_val + 224;
	    }

	    EncodedSymbols << (char)dec_val;

	    if(dec_val > 223)
	    {
	    	dec_val = dec_val - 224;
	    }

	    Decimals << dec_val << endl;
	}

	Decimals.close();

	EncodedSymbols.close();

	Encoding.close();
}
