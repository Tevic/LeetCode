// StudyTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"
#include "Solution.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	 Trie trie;
	 trie.insert("a");
	 bool res1 = trie.search("ab");
	 res1 = trie.startsWith("a");
	return 0;
}



