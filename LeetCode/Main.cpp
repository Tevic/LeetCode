#include "stdafx.h"
#include "DataStructure.h"
//#include "LeetCodeV1.cpp"
//#include "LeetCodeV2.cpp"
#include "LeetCodeV3.cpp"





int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> matrix = {
		{3,0,1,4,2},
		{5,6,3,2,1},
		{1,2,0,1,5},
		{4,1,0,1,7},
		{1,0,3,0,5}
	};
	NumMatrix NM(matrix);
	NM.sumRegion(2, 1, 4, 3);
	NM.sumRegion(1, 1, 2, 2);
	NM.sumRegion(1, 2, 2, 4);
}



