// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{

	Solution86 SU86;
	vector<vector<char> > vec = { vector<char>{'A', 'B', 'C', 'E'}, vector<char>{'S', 'F', 'C', 'S'}, vector<char>{'A','D','E','E'}};
	string str1 = "ABCCED";
	string str2 = "SEE";
	string str3 = "ABCB";
	bool result;
	result=SU86.exist(vec, str1);
	result=SU86.exist(vec, str2);
	result=SU86.exist(vec, str3);
	return 0;
}

