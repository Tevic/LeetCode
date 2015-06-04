// StudyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "DataStructure.h"
//#include "Solution.cpp"
#include "LeetCodeV2.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* T1 = new TreeNode(1);
	TreeNode* T2 = new TreeNode(1);
	T1->left = T2;
	Solution098 S;
	cout<<S.isValidBST(T1);
}



