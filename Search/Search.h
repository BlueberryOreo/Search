#pragma once
#include "SeqList.h"

class Search
{
	static int cmpcnt;
public:
	static int seqSearch(SeqList &l, int begin, int end, int target);
	static int binSearch(SeqList &l, int begin, int end, int target); // 找到target第一次出现的下标
	static int recursiveBinSearch(SeqList &l, int begin, int end, int target);
	static void init();
	static int getcnt();
};
