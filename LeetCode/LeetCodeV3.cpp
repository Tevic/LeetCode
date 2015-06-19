#include "stdafx.h"
#include "DataStructure.h"



/*-------------------------------------------------------------------------------------*/
class Solution020 {
public:
	bool isValid(string s) {
		unordered_map<char, char> chMap{ {'(',')'}, {'[',']'}, {'{','}'} };
		stack<char> st;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (chMap.find(s[i])==chMap.end())
			{
				if (!st.empty() && s[i] == chMap[st.top()])
				{
					st.pop();
					continue;
				}
			}
			st.push(s[i]);
		}
		return st.empty();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution019 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fakeHead = new ListNode(0);
		fakeHead->next = head;
		ListNode* pCur1 = fakeHead;
		ListNode* pCur2 = fakeHead;
		while (n--&&pCur2)
		{
			pCur2 = pCur2->next;
		}
		while (pCur2->next)
		{
			pCur1 = pCur1->next;
			pCur2 = pCur2->next;
		}
		pCur1->next = pCur1->next->next;
		return fakeHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution018 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<vector<int>> result;
		if (len > 3)
		{
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len - 3; i++)
			{
				if ( i > 0 && nums[i] == nums[i - 1])continue;
				for (int j = i + 1; j < len - 2; j++)
				{
					if (j>i + 1 && nums[j] == nums[j - 1])continue;
					for (int k = j + 1; k < len - 1; k++)
					{
						if (k>j + 1 && nums[k] == nums[k - 1])continue;
						int searchTarget = target-nums[i] - nums[j] - nums[k];
						if (searchTarget<nums[k + 1])continue;
						int m = BinarySearch(nums, k + 1, len - 1, searchTarget);
						if (m!=-1)
						{
							result.push_back(vector < int > {nums[i],nums[j],nums[k],nums[m]});
						}
					}
				}
			}
		}
		return result;
	}
	int BinarySearch(vector<int>& nums, int L, int R, int target)
	{
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (target > nums[M])
			{
				L = M + 1;
			}
			else
			{
				R = M;
			}
		}
		return nums[L] == target ? L : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution017 {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> strArray = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		int digLen = digits.size();
		vector<string> result;
		if (digLen == 0)
		{
			return result;
		}
		result.push_back("");
		for (size_t i = 0; i < digLen; i++)
		{
			int resLen = result.size();
			for (size_t k = 0; k < resLen; k++)
			{
				for (size_t j = 0; j < strArray[digits[i] - '0'].size() - 1; j++)
				{
					result.push_back(result[k] + strArray[digits[i] - '0'][j]);
				}
				result[k] += strArray[digits[i] - '0'][strArray[digits[i] - '0'].size() - 1];
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution016 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int distMin = INT_MAX;
		int ret = 0;
		for (size_t i = 0; i < len - 2; i++)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int dist = target - nums[i] - nums[j] - nums[k];
				if (abs(dist) < distMin)
				{
					distMin = abs(dist);
					ret = target - dist;
				}
				if (dist > 0)
				{
					j++;
				}
				else if (dist < 0)
				{
					k--;
				}
				else
				{
					return target;
				}
			}
		}
		return ret;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution015 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> result;
		if (len>2)
		{
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len - 2; i++)
			{
				if (i > 0 && nums[i] == nums[i - 1])continue;
				for (int j = i + 1; j < len - 1; j++)
				{
					if (j > i + 1 && nums[j] == nums[j - 1])continue;
					int k = BinarySearch(nums, j + 1, len - 1, 0 - nums[i] - nums[j]);
					if (k != -1)
					{
						result.push_back(vector < int > {nums[i], nums[j], nums[k]});
					}
				}
			}
		}
		return result;
	}
	int BinarySearch(vector<int>& nums, int L, int R, int target)
	{
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] < target)
			{
				L = M + 1;
			}
			else
			{
				R = M;
			}
		}
		return nums[L] == target ? L : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution014 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		if (len <= 0)
		{
			return "";
		}
		int index = 0;
		while (CheckCommon(strs, index))
		{
			index++;
		}
		return strs[0].substr(0, index);
	}

	bool CheckCommon(vector<string>& strs, int index)
	{
		int len = strs.size();
		char ch;
		if (index >= strs[0].size())
		{
			return false;
		}
		ch = strs[0][index];
		for (size_t i = 1; i < len; i++)
		{
			if (index >= strs[i].size() || strs[i][index] != ch)
			{
				return false;
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution013 {
public:
	int romanToInt(string s) {
		int result = 0;
		unordered_map<char, int> chMap{
				{ 'I', 1 },
				{ 'V', 5 },
				{ 'X', 10 },
				{ 'L', 50 },
				{ 'C', 100 },
				{ 'D', 500 },
				{ 'M', 1000 },
		};
		for (int i = 0; i < s.size(); i++)
		{
			int cur = chMap[s[i]];
			int pre = chMap[s[i - 1]];
			if (i>0 && cur > pre)
			{
				result += (cur - 2 * pre);
			}
			else
			{
				result += cur;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution012 {
public:
	string intToRoman(int num) {
		string str;
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		for (int i = 0; num != 0; ++i)
		{
			while (num >= value[i])
			{
				num -= value[i];
				str += symbol[i];
			}
		}
		return str;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution011 {
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;
		int L = 0;
		int R = height.size() - 1;
		while (L < R)
		{
			int curArea = (R - L)*min(height[L], height[R]);
			maxArea = max(maxArea, curArea);
			if (height[L] > height[R])
			{
				R--;
			}
			else
			{
				L++;
			}
		}
		return maxArea;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution010 {
public:
	bool isMatch(string s, string p) {
		s += '#';
		p += '#';
		return CheckMatch(s, p, 0, 0);
	}
	bool CheckMatch(string& s, string& p, int sIndex, int pIndex)
	{
		if (p[pIndex] == '#')
		{
			return s[sIndex] == '#';
		}
		if (p[pIndex + 1] != '*')
		{
			if (p[pIndex] == s[sIndex] || p[pIndex] == '.'&&s[sIndex] != '#')
			{
				return CheckMatch(s, p, sIndex + 1, pIndex + 1);
			}
			return false;
		}
		else
		{
			while (p[pIndex] == s[sIndex] || p[pIndex] == '.'&&s[sIndex] != '#')
			{
				if (CheckMatch(s, p, sIndex, pIndex + 2))
				{
					return true;
				}
				sIndex++;
			}
			return CheckMatch(s, p, sIndex, pIndex + 2);
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution009 {
public:
	bool isPalindrome(int x) {
		if (x < 0)
		{
			return false;
		}
		int factor = 1;
		while (x / factor >= 10)
		{
			factor *= 10;
		}
		while (x)
		{
			int H = x / factor;
			int L = x % 10;
			if (L != H)
			{
				return false;
			}
			x = x%factor / 10;
			factor /= 100;
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution008 {
public:
	int myAtoi(string str) {
		int len = str.size();
		int res = 0;
		int sign = 1;
		int index = 0;
		while (index < len && isspace(str[index]))
		{
			index++;
		}
		if (index < len && (str[index] == '+' || str[index] == '-'))
		{
			if (str[index] == '-')
			{
				sign = -1;
			}
			index++;
		}
		while (index < len&& isdigit(str[index]))
		{
			if (sign == -1)
			{
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[index] > '8'))
				{
					return INT_MIN;
				}
			}
			else
			{
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[index] >= '8'))
				{
					return INT_MAX;
				}
			}
			res = res * 10 + (str[index] - '0');
			index++;
		}
		while (index < len && isspace(str[index]))
		{
			index++;
		}
		return res*sign;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution007 {
public:
	int reverse(int x) {
		int result = 0;
		while (x)
		{
			if (result > INT_MAX / 10 || result < INT_MIN / 10)
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
		if (len <= numRows)
		{
			return s;
		}
		vector<string> vecStr(numRows);
		int start = 0;
		while (start < len)
		{
			int i = 0;
			while (i < numRows && start + i < len)
			{
				vecStr[i] += s[start + i];
				i++;
			}
			if (start + i == len)
			{
				break;
			}
			start += i;
			i -= 2;
			while (i >= 1 && start + (numRows - i) - 2 < len)
			{
				vecStr[i] += s[start + (numRows - i) - 2];
				i--;
			}
			if (start + (numRows - i) - 2 == len)
			{
				break;
			}
			start = start + (numRows - i) - 2;
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
		int maxLen = 0;
		int len = s.size();
		int start = 0;
		for (int i = 0; i < len; i++)
		{
			int j = 0;
			while (i - j >= 0 && i + j < len&&s[i - j] == s[i + j])
			{
				j++;
			}
			if (maxLen < 2 * j - 1)
			{
				maxLen = 2 * j - 1;
				start = i - j + 1;
			}
			j = 1;
			while (i - j >= 0 && i + j - 1 < len&&s[i - j] == s[i + j - 1])
			{
				j++;
			}
			if (maxLen < 2 * (j - 1))
			{
				maxLen = 2 * (j - 1);
				start = i - j + 1;
			}
		}
		return s.substr(start, maxLen);
	}
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
		int maxLen = 0;
		int index = 0;
		vector<int> chMap(256, -1);
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			if (chMap[s[i]] >= index)
			{
				index = chMap[s[i]] + 1;
			}
			chMap[s[i]] = i;
			maxLen = max(maxLen, i - index + 1);
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
		ListNode* L3 = new ListNode(0);
		ListNode* pCur = L3;
		int carry = 0;
		while (l1&&l2)
		{
			int val = l1->val + l2->val + carry;
			carry = val / 10;
			ListNode* node = new ListNode(val % 10);
			pCur->next = node;
			pCur = node;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			int val = l1->val + carry;
			carry = val / 10;
			ListNode* node = new ListNode(val % 10);
			pCur->next = node;
			pCur = node;
			l1 = l1->next;
			if (!carry)
			{
				pCur->next = l1;
				break;
			}
		}
		while (l2)
		{
			int val = l2->val + carry;
			carry = val / 10;
			ListNode* node = new ListNode(val % 10);
			pCur->next = node;
			pCur = node;
			l2 = l2->next;
			if (!carry)
			{
				pCur->next = l2;
				break;
			}
		}
		if (carry)
		{
			ListNode* node = new ListNode(carry);
			pCur->next = node;
		}
		return L3->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution001 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int> result;
		unordered_map<int, int> ump;
		for (size_t i = 0; i < len; i++)
		{
			auto m = ump.find(target - nums[i]);
			if (m != ump.end())
			{
				result.push_back(m->second);
				result.push_back(i + 1);
				break;
			}
			else
			{
				ump[nums[i]] = i + 1;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
