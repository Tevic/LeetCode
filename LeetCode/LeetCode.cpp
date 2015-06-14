// StudyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "DataStructure.h"
//#include "Solution.cpp"
#include "LeetCodeV2.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution224 S;
	//vector<string> vec = S.ConvertToRPN("(3-4*5)*(3+5)-5");
	//copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
	S.ConvertToRPN("(80 - 41)*(8  /2/1)");
}



