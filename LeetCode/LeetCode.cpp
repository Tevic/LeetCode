// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{	
	Solution91 SU88;
	ListNode* head = new ListNode(1);
	ListNode* L2 = new ListNode(2);
	//ListNode* L3 = new ListNode(3);
	//ListNode* L4 = new ListNode(4);
	//ListNode* L5 = new ListNode(5);
	head->next = L2;
	//L2->next = L3;
	//L3->next = L4;
	//L4->next = L5;
	SU88.rotateRight(head,1);
	return 0;
}

