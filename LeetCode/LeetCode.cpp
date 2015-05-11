// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* T1 = new TreeNode(3);
	TreeNode* T2 = new TreeNode(9);
	TreeNode* T3 = new TreeNode(20);
	TreeNode* T4 = new TreeNode(15);
	TreeNode* T5 = new TreeNode(7);
	T1->left = T2;
	T1->right = T3;
	T3->left = T4;
	T3->right = T5;
	Solution112 SU112;
	SU112.zigzagLevelOrder(T1);
	return 0;
}



