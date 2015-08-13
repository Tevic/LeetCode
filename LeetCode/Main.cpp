#include "stdafx.h"
#include "DataStructure.h"
//#include "LeetCodeV1.cpp"
//#include "LeetCodeV2.cpp"
#include "LeetCodeV3.cpp"

class A
{
public:
	A() {};
	virtual ~A() {};

private:

};

class B:virtual public A
{
public:
	B() {};
	virtual ~B() {};

private:

};


int _tmain(int argc, _TCHAR* argv[])
{
	//Solution034 SU034;
	//SU034.searchRange(vector < int > {1},0);
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
}



