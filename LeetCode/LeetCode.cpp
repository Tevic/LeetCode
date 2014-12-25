// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	Solution33 SU33;
	bool result = SU33.isPalindrome("A man, a plan, a canal: Panama");
	result = SU33.isPalindrome("race a car");
	return 0;
}

