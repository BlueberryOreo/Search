#pragma once
#include "SeqList.h"

class Search
{
	static int cmpcnt;
public:
	static int seqSearch(SeqList &l, int begin, int end, int target);
	static int binSearch(SeqList &l, int begin, int end, int target); // �ҵ�target��һ�γ��ֵ��±�
	static int recursiveBinSearch(SeqList &l, int begin, int end, int target);
	static void init();
	static int getcnt();
};
