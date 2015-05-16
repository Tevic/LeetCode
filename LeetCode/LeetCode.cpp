// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* T1 = new ListNode(1);
	ListNode* T2 = new ListNode(2);
	//ListNode* T3 = new ListNode(3);
	//ListNode* T4 = new ListNode(4);
	//ListNode* T5 = new ListNode(5);
	T1->next = T2;
	//T2->next = T3;
	//T3->next = T4;
	//T4->next = T5;
	Solution122 SU122;
	SU122.reverseBetween(T1, 1, 2);
	return 0;
}



