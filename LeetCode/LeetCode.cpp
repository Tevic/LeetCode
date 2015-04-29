// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution94 SU94;
	vector<int> vec = { 7, 2, 4, 1 };
	SU94.maxProfit(vec);
	return 0;
}

