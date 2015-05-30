#include "stdafx.h"
#include "DataStructure.h"


/*-------------------------------------------------------------------------------------*/
class Solution031 {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		for (int i = len-2; i>=0; i--)
		{
			if (nums[i]<nums[i+1])
			{
				for (int j = len-1; j >i; j--)
				{
					if (nums[i] < nums[j])
					{
						swap(nums[i] , nums[j]);
						sort(nums.begin()+i+1,nums.end());
						return;
					}
				}
			}
		}
		reverse(nums.begin(),nums.end());
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution029 {
public:
	int divide(int dividend, int divisor) {
		long ldividend = dividend;
		long ldivisor = divisor;
		if (ldivisor == 0)
			return -1;//error
		int bits = sizeof(int) * 8;
		int signMask = 0x01 << (bits - 1);
		int valMask = ~signMask;

		int count = 0;
		bool minus = false;
		long dend = ldividend;
		if (ldividend < 0)
		{
			minus = true;
			dend = ~(dend - 1);//补码还原，先-1，再取反。（-1的补码是，将1的原码0x01取反，在+1，也就是1...1）
		}
		long sor = ldivisor;
		if (ldivisor < 0)
		{
			minus = !minus;
			sor = ~(sor - 1);
		}
		int offset = 0;
		int mask = 0x01 << (bits - 1);
		while ((0 == (sor&mask)) && (sor << 1) <= dend)
		{
			++offset;
			sor = sor << 1;
		}

		long result = 0;
		while (offset >= 0)
		{
			if (dend >= sor)
			{
				result += (0x01 << offset);
				dend -= sor;
			}
			--offset;
			sor = sor >> 1;
		}
		if (minus)
			return 0 - result;
		if (ldividend == INT_MIN&&ldivisor == -1)
		{
			result = INT_MAX;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution028 {
public:
	int strStr(string haystack, string needle) {
		int hLen = haystack.size();
		int nLen = needle.size();
		if (nLen>hLen)
		{
			return -1;
		}
		if (nLen==0)
		{
			return 0;
		}
		vector<int> nextArray(nLen,-1);
		GetNextArray(needle, nextArray);
		int i = 0, j = 0;
		while (i<hLen&&j<nLen)
		{
			if (j == -1 || haystack[i]==needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = nextArray[j];
			}
		}
		if (j==nLen)
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}

	void GetNextArray(string needle, vector<int>& nextArray)
	{
		int nLen = needle.size();
		nextArray[0] = -1;
		int k = -1;
		int j = 0;
		while (j < nLen - 1)
		{
			//p[k]表示前缀，p[j]表示后缀  
			if (k == -1 || needle[j] == needle[k])
			{
				++k;
				++j;
				nextArray[j] = k;
			}
			else
			{
				k = nextArray[k];
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution027 {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		int index = 0;
		int count = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i]==val)
			{
				count++;
			}
			else
			{
				nums[i - count] = nums[i];
			}
		}
		return len - count;;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution026 {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int newLen = len;
		int diff = 0;
		int pre=INT_MIN;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i]==pre)
			{
				diff++;
				newLen--;
			}
			else
			{
				nums[i - diff] = nums[i];
				pre = nums[i];
			}
		}
		nums.resize(newLen);
		return newLen;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution024 {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* fakeHead = new ListNode(-1);
		fakeHead->next = head;
		ListNode* pPre=fakeHead;
		ListNode* p1;
		ListNode* p2;
		while (pPre->next&&pPre->next->next)
		{
			p1 = pPre->next;
			p2 = pPre->next->next;
			pPre->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			pPre = p1;
		}
		return fakeHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution022 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n>=0)
		{
			GenPar(result, n, 0,0,"");
		}
		return result;
	}

	void GenPar(vector<string>& result, int n, int leftCnt, int rightCnt, string patern)
	{
		int len = patern.size();
		if (len==2*n)
		{
			result.push_back(patern);
			return;
		}
		if (leftCnt<n)
		{
			GenPar(result, n, leftCnt + 1, rightCnt, patern + "(");
		}
		if (leftCnt>rightCnt)
		{
			GenPar(result, n, leftCnt, rightCnt + 1, patern + ")");
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution021 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)return l2;
		if (!l2)return l1;
		ListNode* newHead;
		ListNode* pCur;
		if (l1->val < l2->val)
		{
			newHead = l1;
			l1 = l1->next;
		}
		else
		{
			newHead = l2;
			l2 = l2->next;
		}
		pCur = newHead;
		while (l1&&l2)
		{
			if (l1->val < l2->val)
			{
				pCur->next = l1;
				l1 = l1->next;
			}
			else
			{
				pCur->next = l2;
				l2 = l2->next;
			}
			pCur=pCur->next;
		}
		if (l1)
		{
			pCur->next = l1;
		}
		if (l2)
		{
			pCur->next = l2;
		}
		return newHead;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution020 {
public:
	bool isValid(string s) {
		int len = s.size();
		if (len % 2 == 1)
		{
			return false;
		}
		unordered_map<char, char> charMap{ { '(', ')' }, { '[', ']' }, { '{', '}' } };
		stack<char> st;
		for (int i = 0; i < len; i++)
		{
			if (charMap.find(s[i]) != charMap.end())
			{
				st.push(s[i]);
			}
			else
			{
				if (!st.empty() && s[i] == charMap[st.top()])
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
		return st.empty();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution019 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fakeHead = new ListNode(-1);
		fakeHead->next = head;
		if (head)
		{
			ListNode* p1 = fakeHead;
			ListNode* p2 = fakeHead;
			while (n--&&p2)
			{
				p2 = p2->next;
			}
			while (p2->next)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			p1->next = p1->next->next;
		}
		return fakeHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution018 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int len = nums.size();
		if (len >= 4)
		{
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len - 3; i++)
			{
				if (i>0 && nums[i] == nums[i - 1])continue;
				for (int j = i + 1; j < len - 2; j++)
				{
					if (j>i + 1 && nums[j] == nums[j - 1])continue;
					for (int k = j + 1; k < len - 1; k++)
					{
						if (k>j + 1 && nums[k] == nums[k - 1])continue;
						int newTarget = target - nums[i] - nums[j] - nums[k];
						if (nums[k + 1] > newTarget)continue;
						int index = BinarySearch(nums, k + 1, len - 1, newTarget);
						if (index != -1)
						{
							result.push_back(vector < int > {nums[i], nums[j], nums[k], nums[index]});
						}
					}
				}
			}
		}
		return result;
	}

	int BinarySearch(vector<int>& nums, int low, int high, int target)
	{
		while (low < high)
		{
			int mid = low + ((high - low) >> 1);
			if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		return nums[low] == target ? low : -1;
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
		for (int i = 0; i < digLen; i++)
		{
			vector<string> tmp;
			for (size_t j = 0; j < result.size(); j++)
			{
				for (size_t k = 0; k < strArray[digits[i] - '0'].size(); k++)
				{
					tmp.push_back(result[j] + strArray[digits[i] - '0'][k]);
				}
			}
			result = tmp;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution016 {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int len = num.size();
		int distMin = INT_MAX;
		int ret = 0;
		for (int i = 0; i < len; i++)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int dist = target - num[i] - num[j] - num[k];
				if (abs(dist) < distMin)
				{
					distMin = abs(dist);
					ret = num[i] + num[j] + num[k];
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
					return ret;
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
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int len = nums.size();
		if (len < 3)
		{
			return result;
		}
		for (size_t i = 0; i < len - 2; i++)
		{
			if (i>0 && nums[i] == nums[i - 1])continue;
			for (size_t j = i + 1; j < len - 1; j++)
			{
				if (j>i + 1 && nums[j] == nums[j - 1])continue;
				int index = BinarySearch(nums, j + 1, len - 1, 0 - nums[i] - nums[j]);
				if (index != -1)
				{
					result.push_back(vector < int > {nums[i], nums[j], nums[index]});
				}
			}
		}
		return result;
	}

	int BinarySearch(vector<int>& nums, int low, int high, int target)
	{
		while (low < high)
		{
			int mid = low + ((high - low) >> 1);
			if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		return nums[low] == target ? low : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution014 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		if (len == 0)
		{
			return "";
		}
		if (len == 1)
		{
			return strs[0];
		}
		int index = 0;
		while (true)
		{
			if (index == strs[0].size())
			{
				return strs[0].substr(0, index);
			}
			for (int i = 1; i < len; i++)
			{
				if (index == strs[i].size() || strs[i][index] != strs[0][index])
				{
					return strs[0].substr(0, index);
				}
			}
			index++;
		}

	}
};
/*-------------------------------------------------------------------------------------*/
class Solution011 {
public:
	int maxArea(vector<int>& height) {
		int L = 0;
		int R = height.size() - 1;
		int maxArea = 0;
		while (L < R)
		{
			int curArea = min(height[L], height[R])*(R - L);
			maxArea = max(maxArea, curArea);
			if (height[L] < height[R])
			{
				L++;
			}
			else
			{
				R--;
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
		return isMatchWord(s, p, 0, 0);
	}

	bool isMatchWord(string &s, string &p, int sIndex, int pIndex) {
		int sLen = s.size();
		int pLen = p.size();
		if (p[pIndex] == '#')
		{
			return s[sIndex] == '#';
		}
		if (p[pIndex + 1] != '*')
		{
			if (s[sIndex] == p[pIndex] || p[pIndex] == '.'&&s[sIndex] != '#')
			{
				return isMatchWord(s, p, sIndex + 1, pIndex + 1);
			}
			return false;
		}
		else
		{
			while (s[sIndex] == p[pIndex] || p[pIndex] == '.'&&s[sIndex] != '#')
			{
				if (isMatchWord(s, p, sIndex, pIndex + 2))
				{
					return true;
				}
				sIndex++;
			}
			return isMatchWord(s, p, sIndex, pIndex + 2);
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
		int div = 1;
		while (x / div >= 10)
		{
			div *= 10;
		}
		while (x)
		{
			int l = x / div;
			int r = x % 10;
			if (l != r)
			{
				return false;
			}
			x = x%div / 10;
			div /= 100;
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution008 {
public:
	int myAtoi(string str) {
		int result = 0;
		int index = 0;
		int sign = 1;
		int maxDiv10 = INT_MAX / 10;
		while (str[index] == ' ')
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
		while (index < str.size())
		{
			if (str[index] >= '0'&&str[index] <= '9')
			{
				if (result > maxDiv10)
				{
					return sign == -1 ? INT_MIN : INT_MAX;
				}
				if (result == maxDiv10)
				{
					if (str[index] >= '8')
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
			if (abs(result) > INT_MAX / 10)
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
