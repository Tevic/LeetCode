// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


//int UniSet[1000] = {0};
//int FindParent(int x)
//{
//	if (x!=UniSet[x])
//	{
//		UniSet[x] = FindParent(UniSet[x]);
//	}
//	return UniSet[x];
//}
//
//void Merge(int x, int y)
//{
//	x = FindParent(x);
//	y = FindParent(y);
//	if (x!=y)
//	{
//		UniSet[x] = y;
//	}
//}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head = new ListNode(1);
	ListNode* L1 = new ListNode(2);
	ListNode* L2 = new ListNode(3);
	ListNode* L3 = new ListNode(4);
	ListNode* L4 = new ListNode(5);
	ListNode* L5 = new ListNode(6);
	head->next = L1;
	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = L5;
	L5->next = L3;
	Solution81 SU81;
	SU81.detectCycle(head);
	return 0;
}

