#include "stdafx.h"
#include "DataStructure.h"


/*-------------------------------------------------------------------------------------*/
class Solution008 {
public:
	int myAtoi(string str) {
		int result=0;
		int index = 0;
		int sign = 1;
		int maxDiv10 = INT_MAX / 10;
		while (str[index]==' ')
		{
			index++;
		}
		if (str[index] == '+')
		{
			index++;
		}
		else if (str[index] == '-')
		{
			index++;
			sign = -1;
		}
		while (index<str.size())
		{
			if (str[index] >= '0'&&str[index]<='9')
			{
				if (result>maxDiv10)
				{
					return sign==-1?INT_MIN:INT_MAX;
				}
				if (result==maxDiv10)
				{
					if (str[index]>='8')
					{
						return sign == -1 ? INT_MIN : INT_MAX;
					}
				}
				result = result * 10 + (str[index] - '0');
				index++;
			}
			else
			{
				break;
			}
		}
		return result*sign;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution007 {
public:
	int reverse(int x) {
		int result = 0;
		while (x)
		{
			if (abs(result)>INT_MAX / 10)
			{
				return 0;
			}
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution006 {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		if (len<=numRows)
		{
			return s;
		}
		vector<string> vecStr(numRows);
		int start = 0;
		while (start<len)
		{
			int i = 0;
			while (i<numRows && start+i<len)
			{
				vecStr[i] += s[start + i];
				i++;
			}
			if (start + i==len)
			{
				break;
			}
			start += i;
			i-=2;
			while (i >= 1 && start + (numRows-i)-2<len)
			{
				vecStr[i] += s[start + (numRows - i) - 2];
				i--;
			}
			if (start + (numRows - i) - 2 == len)
			{
				break;
			}
			start = start + (numRows - i)-2;
		}
		string str;
		for (size_t i = 0; i < vecStr.size(); i++)
		{
			str += vecStr[i];
		}
		return str;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution005 {
public:
	string longestPalindrome(string s) {
		const int len = s.size();
		if (len <= 1)return s;
		int start, maxLen = 0;
		for (int i = 1; i < len; i++)
		{
			//寻找以i-1,i为中点偶数长度的回文
			int low = i - 1, high = i;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxLen)
			{
				maxLen = high - low - 1;
				start = low + 1;
			}
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxLen)
			{
				maxLen = high - low - 1;
				start = low + 1;
			}
		}
		return s.substr(start, maxLen);
	}
	//string longestPalindrome(string s) {
	//	int len = s.size();
	//	if (len==0)
	//	{
	//		return "";
	//	}
	//	string s1 = s;
	//	reverse(s.begin(),s.end());
	//	string s2 = s;
	//	vector<vector<int>> mat(len,vector<int>(len,0));
	//	for (int i = 0; i < len; i++)
	//	{
	//		mat[i][0] = s1[i] == s2[0] ? 1 : 0;
	//		mat[0][i] = s1[0] == s2[i] ? 1 : 0;
	//	}
	//	int maxLen = 1;
	//	int index = 0;
	//	for (int i = 1; i < len; i++)
	//	{
	//		for (int j = 1; j < len; j++)
	//		{
	//			if (s1[i]==s2[j])
	//			{
	//				mat[i][j] = mat[i - 1][j - 1] + 1;
	//				if (maxLen< mat[i][j])
	//				{
	//					maxLen = mat[i][j];
	//					index = i;
	//				}
	//			}
	//		}
	//	}
	//	s = s1.substr(index - maxLen+1, maxLen);
	//	return s;
	//}
};
/*-------------------------------------------------------------------------------------*/
class Solution004 {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (m == 0 && n == 0)
		{
			return 0;
		}
		int indexA = 0;
		int indexB = 0;
		vector<int> vecC;
		while (indexA != m&&indexB != n)
		{
			if (A[indexA] < B[indexB])
			{
				vecC.push_back(A[indexA]);
				indexA++;
			}
			else
			{
				vecC.push_back(B[indexB]);
				indexB++;
			}
		}
		while (indexA != m)
		{
			vecC.push_back(A[indexA]);
			indexA++;
		}
		while (indexB != n)
		{
			vecC.push_back(B[indexB]);
			indexB++;
		}
		if ((m + n) % 2 == 0)
		{
			return (vecC[(m + n) / 2] + vecC[(m + n) / 2 - 1]) / 2.0;
		}
		else
		{
			return vecC[(m + n) / 2];
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution003 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> chFlag(256, -1);
		int strLen = s.size();
		int maxLen = 0;
		int i = 0;
		for (int j = 0; j < strLen; j++)
		{
			if (chFlag[s[j]] >= i)
			{
				i = chFlag[s[j]] + 1;
			}
			chFlag[s[j]] = j;
			maxLen = max(maxLen, j - i + 1);
		}
		return maxLen;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution002 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1)
		{
			return l2;
		}
		if (!l2)
		{
			return l1;
		}
		int carry = (l1->val + l2->val) / 10;
		ListNode* head = new ListNode((l1->val + l2->val) % 10);
		ListNode* pCur = head;
		l1 = l1->next;
		l2 = l2->next;
		while (l1&&l2)
		{
			ListNode* node = new ListNode((l1->val + l2->val + carry) % 10);
			carry = (l1->val + l2->val + carry) / 10;
			pCur->next = node;
			pCur = node;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* l = l1 ? l1 : l2;
		while (l)
		{
			ListNode* node = new ListNode((l->val + carry) % 10);
			carry = (l->val + carry) / 10;
			pCur->next = node;
			pCur = node;
			l = l->next;
		}
		if (carry)
		{
			ListNode* node = new ListNode(carry);
			pCur->next = node;
		}
		return head;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution001 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> ump;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (ump.find(target - nums[i]) != ump.end())
			{
				result.push_back(ump[target - nums[i]] + 1);
				result.push_back(i + 1);
				return result;
			}
			ump[nums[i]] = i;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
