// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution99 SU99;
	vector<int> vec = { 0,-1,1 };
	SU99.permute(vec);
	return 0;
}

