// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution102 SU102;
	SU102.maxSubArray(vec);
	return 0;
}



