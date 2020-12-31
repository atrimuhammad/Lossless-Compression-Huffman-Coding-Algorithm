#include <iostream>
#include "HuffmanTable.h"
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
using namespace std;

struct T_Node
{
	public:
		T_Node* left;
		T_Node* right;

		char Character;
		int Frequency;

		char code;
};

class OrderedQueue;

class HuffmanTree
{
	private:
		T_Node* root;

	public:
		HuffmanTree();
		~HuffmanTree();

		T_Node* Make_BT_Node(char Char, int Freq);

		void BuildHuffmanTree(OrderedQueue* oq, int casenum);

		void HT_Display(T_Node *node);

		T_Node* getRoot();

		int ArraySearch(int* arr, int charnum, int linenum);

		void CodeGenerator(T_Node* node, string CodeStirng, HuffmanTable &hTable);

		void ReconstructFile(string EncodedFileName, string ReconstructedFileName, int extra, int* arr);
};
#endif
