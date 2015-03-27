// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{	
	Solution75 SU75;
	vector<vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	int result=SU75.minimumTotal(triangle);
	return 0;
}

