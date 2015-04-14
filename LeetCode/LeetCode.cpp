// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


//int UniSet[1000] = {0};
//int FindParent(int x)
//{
//	if (x!=UniSet[x])
//	{
//		UniSet[x] = FindParent(UniSet[x]);
//	}
//	return UniSet[x];
//}
//
//void Merge(int x, int y)
//{
//	x = FindParent(x);
//	y = FindParent(y);
//	if (x!=y)
//	{
//		UniSet[x] = y;
//	}
//}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution77 SU77;
	SU77.numIslands(vector < vector<char> > {
			vector < char > {'1', '1', '0', '0', '0'},
			vector < char > {'1', '1', '0', '0', '0'},
			vector < char > {'0', '0', '1', '0', '0'},
			vector < char > {'0', '0', '0', '1', '1'}
	});
	return 0;
}

