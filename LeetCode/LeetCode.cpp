// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution143 SU143;
	SU143.spiralOrder(vector < vector<int> > {vector < int > {1, 2, 3,4, 5, 6,7, 8, 9,10}});
	//SU143.spiralOrder(vector < vector<int> > {vector < int > {1, 2, 3}, vector < int > {4, 5, 6}, vector < int > {7, 8, 9}});
	//SU143.spiralOrder(vector < vector<int> > {vector < int > {1, 2, 3, 4}, vector < int > {5, 6, 7, 8}, vector < int > {9, 10, 11, 12}});
	return 0;
}



