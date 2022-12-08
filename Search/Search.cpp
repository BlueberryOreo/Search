#include "Search.h"

int Search::cmpcnt = 0;

int Search::seqSearch(SeqList& l, int begin, int end, int target)
{
    for (int i = begin; i < end; i ++) {
        cmpcnt++;
        if (l[i] == target) return i;
    }
    return -1;
}

int Search::binSearch(SeqList& l, int begin, int end, int target)
{
    if (begin < l.begin() || end > l.size()) return -1;
    int lft = begin, rgt = end;
    while (lft < rgt - 1) {
        int mid = (lft + rgt) / 2;
        cmpcnt++;
        //cout << lft << " " << mid << " " << rgt << endl;
        //if (l[mid] == target) return mid;
        if (l[mid] < target) lft = mid;
        else rgt = mid;
    }
    if (l[lft] == target) return lft;
    if (rgt < l.size() && l[rgt] == target) return rgt;
    return -1;
}

int Search::recursiveBinSearch(SeqList& l, int begin, int end, int target)
{
    if (begin >= end - 1) {
        if (l[begin] == target) return begin;
        else if (l[end] == target) return end;
        else return -1;
    }
    int mid = (begin + end) / 2;
    cmpcnt++;
    if (l[mid] < target) return recursiveBinSearch(l, mid, end, target);
    else return recursiveBinSearch(l, begin, mid, target);
}

void Search::init()
{
    cmpcnt = 0;
}

int Search::getcnt()
{
    return cmpcnt;
}
