// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"



int _tmain(int argc, _TCHAR* argv[])
{
	int A[10] = { 0, 0, 0, 1, 0, 1, 1, 0, 2, 1 };
	Solution13 SU13;
	SU13.sortColors(A, 10);
	return 0;
}

