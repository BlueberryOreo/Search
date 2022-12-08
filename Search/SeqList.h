#pragma once
#include "utility.h"

class SeqList {
protected:
	int* list;
	int l_size;
public:
	SeqList();
	SeqList(int *arr, int n);
	SeqList(vector<int> &v);
	~SeqList();

	int begin();
	int end();
	void sort(int start, int end);

	int& operator[](int i);
	int size();
	void print();
};