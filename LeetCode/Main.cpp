#include "stdafx.h"
#include "DataStructure.h"
//#include "LeetCodeV1.cpp"
//#include "LeetCodeV2.cpp"
#include "LeetCodeV3.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution083 S;
	ListNode* L1 = new ListNode(1);
	ListNode* L2 = new ListNode(2);
	L1->next = L2;
	S.deleteDuplicates(L1);
}



