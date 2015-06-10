// StudyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "DataStructure.h"
//#include "Solution.cpp"
#include "LeetCodeV2.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* L = new ListNode(1);
	L->next = new ListNode(-1);
	Solution147 S;
	ListNode* L2=S.sortList(L);
}



