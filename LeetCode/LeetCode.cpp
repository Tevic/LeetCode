// StudyTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"



int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(2);
	root->left = left;
	left->left = right;
	Solution12 SU;
	SU.isBalanced(root);
	return 0;
}

