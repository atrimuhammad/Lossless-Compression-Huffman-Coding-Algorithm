#ifndef HUFFMANTABLE_H
#define HUFFMANTABLE_H
#include <iostream>
using namespace std;

struct HT_Node
{
	public:
		HT_Node* next;

		char Character;
		string Code;

};
class HuffmanTable
{
	private:
		HT_Node* head;
		HT_Node* tail;
		HT_Node* current;

	public:
		HuffmanTable();
		~HuffmanTable();

		void Insert(char Char, string code);

		void hTable_Display();

		void GenerateEncodedFile(string FileDataString);

		void EncodingSymbols(string FileName);
};
#endif
