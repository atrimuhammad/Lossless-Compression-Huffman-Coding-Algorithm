#include <iostream>
#include <fstream>
#include "HuffmanTable.h"
#include "LinkedList.h"
#include "OrderedQueue.h"
#include "HuffmanTree.h"
using namespace std;

int main()
{
	string FileName, temp, temp1, filetext, encodedFileName, reconstructedFileName, CODE = "";

	int i = 0, casenum = 0, TotalUniqueCharactersinFile = 0, ex = 0;

	int numoflines = 0;

	/*-------------------------------------------------------------------------------*/

	cout << "Enter the file's name, from which you have to read text : ";
	cin >> FileName;

	cout << "\nEnter the file's name, in which you have to write Encoded Symbols : ";
	cin >> encodedFileName;

	cout << "\nEnter the file's name, in which you have to write text, reconstructed from Encoded Symbols File : ";
	cin >> reconstructedFileName;

	/*-------------------------------------------------------------------------------*/

	cout << "\n1. Print text, which we read from file \"" << FileName << "\"";
	cout << "\n2. Print count of Unique Characters in file \"" << FileName << "\"";
	cout << "\n3. Print Characters and their Frequencies";
	cout << "\n4. Print Sorted Characters, according to frequency";
	cout << "\n5. Print Huffman Tree, INORDERLY";
	cout << "\n6. Print Huffman Table";
	cout << "\n7. Store Encoding Symbols in file \"" << encodedFileName << "\"";
	cout << "\n8. Reconstruct Original File from file \"" << encodedFileName << "\"";
	cout << "\n9. Bonus Task / Print complete report";

	cout << "\n\nEnter 1/2/3/4/5/6/7/8/9, based on which task you want to perform : ";
	cin >> casenum;

	/*-------------------------------------------------------------------------------*/

	ifstream TextFile(FileName);

	if(!TextFile.is_open())
	{
		cout << "\nError. Reading file \"" << FileName << "\"";

		exit(0);
	}

	/*--------------Reading Text from File "original.txt"------------*/

	while(!TextFile.eof())
	{
		getline(TextFile, temp1);

		numoflines++;
	}

	int* CHARS = new int[numoflines];

	TextFile.close();

	TextFile.open(FileName);

	if(!TextFile.is_open())
	{
		cout << "\nError. Reading file \"" << FileName << "\"";

		exit(0);
	}

	/*--------------Reading Text from File "original.txt"------------*/

	int z = 0;

	while(!TextFile.eof())
	{
		getline(TextFile, temp);

		CHARS[z] = temp.size();

		z++;

		//temp+="\n";
		filetext+=temp;
	}

	TextFile.close();

	ex = filetext.size();

	/*------------------------------------------------------------------------------*/

	if(casenum == 1)
	{
		cout << "\n-----------------------------------------------------------\n";

		cout << endl << filetext;

		cout << "\n-----------------------------------------------------------\n";

		cout << "\nSize of file \"" << FileName << "\"" << " (in Bytes) : " << filetext.size() << " Bytes\n";

		cout << "\nSize of file \"" << FileName << "\"" << " (in Bits) : " << filetext.size() * 7 << " Bits";
	}

	/*------------------------------------------------------------------------------*/

	CharLinkedList CharLL;

	while(filetext[i] != '\0')
	{
		CharLL.InsertUniqueCharacters(filetext[i], TotalUniqueCharactersinFile);

		i++;
	}

	/*------------------------------------------------------------------------------*/

	if(casenum == 2)
	{
		cout << "\n-----------------------------------------------------------\n";

		cout << "\nTotal Unique Characters in File \"" << FileName << "\" : " << TotalUniqueCharactersinFile;
	}

	/*------------------------------------------------------------------------------*/

	if(casenum == 3)
	{
		cout << "\n-----------------------------------------------------------\n\nCharacter : Frequency";

		CharLL.Frequency_Display();
	}

	/*------------------------------------------------------------------------------*/

	LL_Node* Head = CharLL.Sorting(CharLL.getHead());

	CharLL.setHead(Head);

	/*------------------------------------------------------------------------------*/

 	if(casenum == 4)
 	{
		cout << "\n-----------------------------------------------------------\n\nCharacter : Frequency";

		CharLL.Frequency_Display();
 	}

	/*------------------------------------------------------------------------------*/

 	OrderedQueue OQ(TotalUniqueCharactersinFile);

 	CharLL.IntroducetoOrderedQueue(&OQ);

 	/*------------------------------------------------------------------------------*/

 	if(casenum == 4)
 	{
 		cout << endl << endl << "Characters Sorted in Ordered Queue, according to their Frequency\n\n";

 		OQ.QueueDisplay();
 	}

 	/*------------------------------------------------------------------------------*/

	HuffmanTree HT;

	HT.BuildHuffmanTree(&OQ, casenum);

	/*------------------------------------------------------------------------------*/

	if(casenum == 5)
	{
		cout << "\n\n-----------------------------------------------------------\n\nBelow is Huffman Tree printed INORDERLY\n\nCharacter : Frequency\n\n";

		HT.HT_Display(HT.getRoot());
	}

	/*------------------------------------------------------------------------------*/

	HuffmanTable hTable;

	HT.CodeGenerator(HT.getRoot(), CODE, hTable);

	/*------------------------------------------------------------------------------*/

	if(casenum == 6)
	{
		cout << "\n-----------------------------------------------------------\n\nCharacter : Code";

		hTable.hTable_Display();
	}

	/*------------------------------------------------------------------------------*/

	if(casenum == 7)
	{
		hTable.GenerateEncodedFile(filetext);

		hTable.EncodingSymbols(encodedFileName);

		string encodings;

		ifstream EncodedFileSize("encoded.txt");

		while(!EncodedFileSize.eof())
		{
			getline(EncodedFileSize, encodings);
		}

		EncodedFileSize.close();

		cout << "\n\n-----------------------------------------------------------";

		cout << "\n\nSize of file \"" << encodedFileName << "\"" << " (in Bytes) : " << encodings.size() << " Bytes\n";

		cout << "\nSize of file \"" << encodedFileName << "\"" << " (in Bits) : " << encodings.size() * 7 << " Bits";
	}

	/*------------------------------------------------------------------------------*/

	if(casenum == 8)
	{
		hTable.GenerateEncodedFile(filetext);

		hTable.EncodingSymbols(encodedFileName);

		HT.ReconstructFile(encodedFileName, reconstructedFileName, ex, CHARS);
	}

	/*------------------------------------------------------------------------------*/

	if(casenum == 9)
	{
		hTable.GenerateEncodedFile(filetext);

		hTable.EncodingSymbols(encodedFileName);

		HT.ReconstructFile(encodedFileName, reconstructedFileName, ex, CHARS);

		cout << "\n-----------------------------------------------------------\n";

		cout << "\nSize of file \"" << FileName << "\"" << " (in Bytes) : " << filetext.size() << " Bytes\n";

		cout << "\nSize of file \"" << FileName << "\"" << " (in Bits) : " << filetext.size() * 7 << " Bits";

		string encodings;

		ifstream EncodedFileSize("encoded.txt");

		while(!EncodedFileSize.eof())
		{
			getline(EncodedFileSize, encodings);
		}

		EncodedFileSize.close();

		cout << "\n\n-----------------------------------------------------------";

		cout << "\n\nSize of file \"" << encodedFileName << "\"" << " (in Bytes) : " << encodings.size() << " Bytes\n";

		cout << "\nSize of file \"" << encodedFileName << "\"" << " (in Bits) : " << encodings.size() * 7 << " Bits";

		string restructuredfiletext = "";

		ifstream RestructuredFileSize(reconstructedFileName);

		while(!RestructuredFileSize.eof())
		{
			getline(RestructuredFileSize, restructuredfiletext);
		}

		RestructuredFileSize.close();

		cout << "\n\n-----------------------------------------------------------";

		cout << "\n\nSize of file \"" << reconstructedFileName << "\"" << " (in Bytes) : " << restructuredfiletext.size() << " Bytes\n";

		cout << "\nSize of file \"" << reconstructedFileName << "\"" << " (in Bits) : " << restructuredfiletext.size() * 7 << " Bits";

		int i = 0;
		bool flag = false;

		cout << "\n\n-------------------------------------------\n\nCharacter : Column #\n";

		while(restructuredfiletext[i] != '\0')
		{
			if(filetext[i] != restructuredfiletext[i])
			{
				flag = true;

				cout << endl << restructuredfiletext[i] << " : " << i;
			}

			i++;
		}

		if(flag == true)
		{
			cout << "\n\n\"" << FileName << "\" and \"" << reconstructedFileName << "\" are not exactly same.";
		}
		else
		{
			cout << "\n\n\"" << FileName << "\" and \"" << reconstructedFileName << "\" are exactly same.";
		}
	}

	return 0;
}
