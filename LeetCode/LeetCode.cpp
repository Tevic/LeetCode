// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{	
	Solution72 SU72;
	int A[6] = { 1, 1, 1, 2, 2, 3 };
	SU72.removeDuplicates(A,6);
	return 0;
}

