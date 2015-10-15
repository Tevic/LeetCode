#include "stdafx.h"
#include "DataStructure.h"






/*-------------------------------------------------------------------------------------*/
class Solution293 {
public:
	bool canWinNim(int n) {
		return n % 4 > 0;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution290 {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> strList;
		istringstream ss(str);
		string strTemp;
		int index = 0;
		unordered_map<char, string> ump;
		unordered_map<string, char> rump;
		while (getline(ss, strTemp, ' '))
		{
			strList.push_back(strTemp);
		}
		if (strList.size() != pattern.size())
		{
			return false;
		}
		for (size_t i = 0; i < pattern.size(); i++)
		{
			if (ump.find(pattern[i]) != ump.end())
			{
				if (ump[pattern[i]] != strList[i])
				{
					return false;
				}
			}
			else
			{
				ump[pattern[i]] = strList[i];
			}
			if (rump.find(strList[i]) != rump.end())
			{
				if (rump[strList[i]] != pattern[i])
				{
					return false;
				}
			}
			else
			{
				rump[strList[i]] = pattern[i];
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution289 {
public:
	int getState(vector<vector<int> >& board, int i, int j) {
		if (board[i][j] & 0xFFFF0000)
			return board[i][j] ^ 0xFFFF0000;
		else
			return board[i][j];
	}
	int count(vector<vector<int> >& board, int i, int j) {
		int m = board.size();
		int n = m ? board[0].size() : 0;
		int cnt = 0;
		for (int x = i - 1; x <= i + 1; x++) {
			for (int y = j - 1; y <= j + 1; y++) {
				if (x >= 0 && x < m&&y >= 0 && y < n && (x != i || y != j)) {
					if (getState(board, x, y))
						cnt++;
				}
			}
		}
		return cnt;
	}
	void mark(vector<vector<int> >& board, int i, int j) {
		int state = getState(board, i, j);
		int live = count(board, i, j);
		switch (state) {
		case 0:
			if (live == 3)
				board[i][j] ^= 0xFFFF0000;
			break;
		case 1:
			if (live < 2 || live>3)
				board[i][j] ^= 0xFFFF0000;
			break;
		}
	}
	void mark(vector<vector<int> >& board) {
		int m = board.size();
		int n = m ? board[0].size() : 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mark(board, i, j);
			}
		}

	}
	void update(vector<vector<int> >& board) {
		int m = board.size();
		int n = m ? board[0].size() : 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] & 0xFFFF0000) {
					int state = getState(board, i, j);
					if (state)
						board[i][j] = 0;
					else
						board[i][j] = 1;
				}
			}
		}

	}
	void gameOfLife(vector<vector<int>>& board) {
		mark(board);
		update(board);
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution287 {
public:
	int findDuplicate(vector<int>& nums) {
		int len = nums.size();
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == i + 1)
			{
				continue;
			}
			while (nums[i] != i + 1)
			{
				if (nums[i] <= len&&nums[i] == nums[nums[i] - 1])
				{
					return nums[i];
				}
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		if (Iterator::hasNext())
		{
			cur = Iterator::next();
			mHasNext = true;
		}

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return cur;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int pre = cur;
		if (Iterator::hasNext())
		{
			cur = Iterator::next();
		}
		else
		{
			mHasNext = false;
		}
		return pre;
	}

	bool hasNext() const {
		return mHasNext;
	}
private:
	int cur;
	bool mHasNext;
};
/*-------------------------------------------------------------------------------------*/
class Solution283 {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		int iCnt = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == 0)
			{
				iCnt++;
			}
			else
			{
				nums[i - iCnt] = nums[i];
				if (iCnt)
				{
					nums[i] = 0;
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution279 {
public:
	int numSquares(int n) {
		int* DP = new int[n + 1]{ 0 };
		for (int i = 1; i <= n; i++)
		{
			int minVal = INT_MAX;
			for (int j = 1; j * j <= i; j++)
			{
				minVal = min(minVal, DP[i - j * j] + 1);
			}
			DP[i] = minVal;
		}
		return DP[n];
	}
};
/*-------------------------------------------------------------------------------------*/
bool isBadVersion(int version);

class Solution278 {
public:
	int firstBadVersion(int n) {
		int L = 1;
		int R = n;
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (isBadVersion(M))
			{
				R = M;
			}
			else
			{
				L = M + 1;
			}
		}
		return L;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution273 {
public:
	string numberToWords(int num) {
		string res = convertHundred(num % 1000);
		vector<string> v = { "Thousand", "Million", "Billion" };
		for (int i = 0; i < 3; ++i) {
			num /= 1000;
			res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
		}
		while (res.back() == ' ') res.pop_back();
		return res.empty() ? "Zero" : res;
	}
	string convertHundred(int num) {
		vector<string> v1 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		vector<string> v2 = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		string res;
		int a = num / 100, b = num % 100, c = num % 10;
		res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
		if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution268 {
public:
	int missingNumber(vector<int>& nums) {
		int len = nums.size();
		int sum = len;
		for (int i = 0; i < len; i++)
		{
			sum += (i - nums[i]);
		}
		return sum;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution264 {
public:
	int nthUglyNumber(int n) {
		int index = 0;
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;
		vector<int> uglyVec(n, 1);
		while (index < n - 1)
		{
			int uglyVal = min(min(uglyVec[index2] * 2, uglyVec[index3] * 3), uglyVec[index5] * 5);
			if (uglyVal == uglyVec[index2] * 2)
			{
				index2++;
			}
			if (uglyVal == uglyVec[index3] * 3)
			{
				index3++;
			}
			if (uglyVal == uglyVec[index5] * 5)
			{
				index5++;
			}
			uglyVec[++index] = uglyVal;
		}
		return uglyVec[n - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution263 {
public:
	bool isUgly(int num) {
		if (num <= 0)
		{
			return false;
		}
		while (num % 2 == 0)
		{
			num /= 2;
		}
		while (num % 3 == 0)
		{
			num /= 3;
		}
		while (num % 5 == 0)
		{
			num /= 5;
		}
		return num == 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution260 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int len = nums.size();
		int xorSum = 0;
		for (int i = 0; i < len; i++)
		{
			xorSum ^= nums[i];
		}
		int index = -1;
		for (int i = 0; i < 32; i++)
		{
			if ((xorSum >> i) & 1 == 1)
			{
				index = i;
				break;
			}
		}
		int N1 = 0;
		int N2 = 0;
		for (size_t i = 0; i < len; i++)
		{
			if ((nums[i] >> index) & 1 == 1)
			{
				N1 ^= nums[i];
			}
			else
			{
				N2 ^= nums[i];
			}
		}
		return vector < int > {N1, N2};
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution258 {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution257 {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		DFS(root, result, "");
		for (size_t i = 0; i < result.size(); i++)
		{
			result[i].pop_back();
			result[i].pop_back();
		}
		return result;
	}

	void DFS(TreeNode* root, vector<string>& result, string path)
	{
		if (root)
		{
			path += (to_string(root->val) + "->");
			if (!root->left&&!root->right)
			{
				result.push_back(path);
			}
			else
			{
				if (root->left)
				{
					DFS(root->left, result, path);
				}
				if (root->right)
				{
					DFS(root->right, result, path);
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution242 {
public:
	bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution241 {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i + 1));
				for (int j = 0; j < left.size(); ++j) {
					for (int k = 0; k < right.size(); ++k) {
						if (input[i] == '+') res.push_back(left[j] + right[k]);
						else if (input[i] == '-') res.push_back(left[j] - right[k]);
						else res.push_back(left[j] * right[k]);
					}
				}
			}
		}
		if (res.empty()) res.push_back(stoi(input));
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution240 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int M = matrix.size();
		int N = 0;
		if (M)
		{
			N = matrix[0].size();
		}
		int bFind = false;
		if (M&&N)
		{
			int iIndex = 0;
			int jIndex = N - 1;
			while (iIndex < M && jIndex >= 0)
			{
				if (target > matrix[iIndex][jIndex])
				{
					iIndex++;
				}
				else if (target < matrix[iIndex][jIndex])
				{
					jIndex--;
				}
				else
				{
					bFind = true;
					break;
				}
			}
		}
		return bFind;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution239 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;
		for (int i = 0; i < nums.size(); ++i) {
			if (!q.empty() && q.front() == i - k) q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
			q.push_back(i);
			if (i >= k - 1) res.push_back(nums[q.front()]);
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> res(len, 0);
		int left = 1;
		for (int i = 0; i < len; i++)
		{
			res[i] = left;
			left *= nums[i];
		}
		int right = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution237 {
public:
	void deleteNode(ListNode* node) {
		if (node&&node->next)
		{
			node->val = node->next->val;
			node->next = node->next->next;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution236 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)return NULL;
		if (root == p || root == q)return root;
		TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
		if (leftNode&&rightNode)return root;
		return leftNode ? leftNode : rightNode;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution235 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
		{
			return NULL;
		}
		if (max(p->val, q->val) < root->val)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (min(p->val, q->val) > root->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else
		{
			return root;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution234 {
public:
	bool isPalindrome(ListNode* slow, ListNode* fast)
	{
		if (fast == nullptr) {
			half = slow;
			return true;
		}
		if (fast->next == nullptr) {
			half = slow->next;
			return true;
		}

		if (isPalindrome(slow->next, fast->next->next) && slow->val == half->val) {
			half = half->next;
			return true;
		}

		return false;
	}

	bool isPalindrome(ListNode* head) {
		return isPalindrome(head, head);
	}

	ListNode* half;
};
/*-------------------------------------------------------------------------------------*/
class Solution233 {
public:
	int countDigitOne(int n) {
		if (n <= 0)
		{
			return 0;
		}
		long x = n;
		long count = 0;
		long high = 0;
		long low = 0;
		long cur = 0;
		long i = 1;
		while ((x / i) != 0)
		{
			cur = x / i % 10;
			high = x / i / 10;
			low = x - x / i*i;
			if (cur == 0)
			{
				count = count + high*i;
			}
			else if (cur > 1)
			{
				count = count + (high + 1)*i;
			}
			else
			{
				count = count + high*i + low + 1;
			}
			i = i * 10;
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
class Queue {
public:
	stack<int> ST1;
	stack<int> ST2;
	// Push element x to the back of queue.
	void push(int x) {
		ST1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!ST2.empty())
		{
			ST2.pop();
		}
		else
		{
			while (!ST1.empty())
			{
				ST2.push(ST1.top());
				ST1.pop();
			}
			if (!ST2.empty())
			{
				ST2.pop();
			}
		}
	}

	// Get the front element.
	int peek(void) {
		if (!ST2.empty())
		{
			return ST2.top();
		}
		else
		{
			while (!ST1.empty())
			{
				ST2.push(ST1.top());
				ST1.pop();
			}
			if (!ST2.empty())
			{
				return ST2.top();
			}
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return ST1.empty() && ST2.empty();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution231 {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
		{
			return false;
		}
		int cntOne = 0;
		while (n)
		{
			cntOne++;
			n &= (n - 1);
		}
		return cntOne == 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution230 {
public:
	int kthSmallest(TreeNode* root, int k) {
		TreeNode* pCur = root;
		stack<TreeNode*> st;
		while (!st.empty() || pCur)
		{
			if (pCur)
			{
				st.push(pCur);
				pCur = pCur->left;
			}
			else
			{
				TreeNode* cur = st.top();
				if (--k == 0)
				{
					return cur->val;
				}
				st.pop();
				pCur = cur->right;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution229 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int len = nums.size();
		vector<int> result;
		int iCnt1 = 0;
		int iCnt2 = 0;
		int iNum1, iNum2;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == iNum1)
			{
				iCnt1++;
			}
			else if (nums[i] == iNum2)
			{
				iCnt2++;
			}
			else if (iCnt1 == 0)
			{
				iNum1 = nums[i];
				iCnt1++;
			}
			else if (iCnt2 == 0)
			{
				iNum2 = nums[i];
				iCnt2++;
			}
			else
			{
				iCnt1--;
				iCnt2--;
			}
		}
		if (count(nums.begin(), nums.end(), iNum1) > len / 3)
		{
			result.push_back(iNum1);
		}
		if (count(nums.begin(), nums.end(), iNum2) > len / 3)
		{
			result.push_back(iNum2);
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution228 {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int len = nums.size();
		vector<string> result;
		if (len > 0)
		{
			int start = 0;
			int end = 0;
			int last = nums[start];
			nums.push_back(INT_MAX);
			for (size_t i = 1; i <= len; i++)
			{
				if (nums[i] == last + 1)
				{
					end = i;
					last = nums[i];
				}
				else
				{
					if (start == end)
					{
						result.push_back(to_string(nums[start]));
					}
					else
					{
						result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
					}
					start = end = i;
					last = nums[i];
				}
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution227 {
public:
	int calculate(string s) {
		vector<string> vec;
		ConvertToRPN(s, vec);
		return EvalRPN(vec);
	}
	void ConvertToRPN(string s, vector<string>& vec)
	{
		stack<char> S;
		S.push('#');
		unordered_map<char, int> prioMap{ { '#', -1 }, { '(', 0 }, { '+', 1 }, { '-', 1 }, { '*', 3 }, { '/', 3 } };
		int len = s.size();
		for (size_t i = 0; i < len; i++)
		{
			char ch = s[i];
			if (isspace(ch))
			{
				continue;
			}
			if (ch == '(')
			{
				S.push(ch);
			}
			else if (ch == ')')
			{
				while (S.top() != '(')
				{
					vec.push_back(string(1, S.top()));
					S.pop();
				}
				S.pop();
			}
			else if (isdigit(ch))
			{
				string num;
				while (isdigit(s[i]))
				{
					num += s[i];
					i++;
				}
				i--;
				vec.push_back(num);
			}
			else
			{
				while (prioMap[S.top()] >= prioMap[ch])
				{
					vec.push_back(string(1, S.top()));
					S.pop();
				}
				S.push(ch);
			}
		}
		while (S.top() != '#')
		{
			vec.push_back(string(1, S.top()));
			S.pop();
		}
	}

	int EvalRPN(vector<string>& vec)
	{
		stack<long> S;
		int len = vec.size();
		for (size_t i = 0; i < len; i++)
		{
			long num;
			if (vec[i] == "+")
			{
				num = S.top();
				S.pop();
				S.top() += num;
			}
			else  if (vec[i] == "-")
			{
				num = S.top();
				S.pop();
				S.top() -= num;
			}
			else if (vec[i] == "*")
			{
				num = S.top();
				S.pop();
				S.top() *= num;
			}
			else if (vec[i] == "/")
			{
				num = S.top();
				S.pop();
				S.top() /= num;
			}
			else
			{
				S.push(stol(vec[i]));
			}
		}
		return S.top();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution226 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root)
		{
			swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Stack {
public:
	queue<int> Q1;
	queue<int> Q2;
	// Push element x onto stack.
	void push(int x) {
		if (Q2.empty())
		{
			Q1.push(x);
		}
		else
		{
			Q2.push(x);
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!Q1.empty())
		{
			while (Q1.size() != 1)
			{
				Q2.push(Q1.front());
				Q1.pop();
			}
			Q1.pop();
		}
		else if (!Q2.empty())
		{
			while (Q2.size() != 1)
			{
				Q1.push(Q2.front());
				Q2.pop();
			}
			Q2.pop();
		}
	}

	// Get the top element.
	int top() {
		int val = -1;
		if (!Q1.empty())
		{
			while (!Q1.empty())
			{
				val = Q1.front();
				Q2.push(Q1.front());
				Q1.pop();
			}
		}
		else if (!Q2.empty())
		{
			while (!Q2.empty())
			{
				val = Q2.front();
				Q1.push(Q2.front());
				Q2.pop();
			}
		}
		return val;
	}

	// Return whether the stack is empty.
	bool empty() {
		return Q1.empty() && Q2.empty();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution224 {
public:
	int calculate(string s) {
		vector<string> vec;
		ConvertToRPN(s, vec);
		return EvalRPN(vec);
	}
	void ConvertToRPN(string s, vector<string>& vec)
	{
		stack<char> S;
		S.push('#');
		unordered_map<char, int> prioMap{ { '#', -1 }, { '(', 0 }, { '+', 1 }, { '-', 1 }, { '*', 3 }, { '/', 3 } };
		int len = s.size();
		for (size_t i = 0; i < len; i++)
		{
			char ch = s[i];
			if (isspace(ch))
			{
				continue;
			}
			if (ch == '(')
			{
				S.push(ch);
			}
			else if (ch == ')')
			{
				while (S.top() != '(')
				{
					vec.push_back(string(1, S.top()));
					S.pop();
				}
				S.pop();
			}
			else if (isdigit(ch))
			{
				string num;
				while (isdigit(s[i]))
				{
					num += s[i];
					i++;
				}
				i--;
				vec.push_back(num);
			}
			else
			{
				while (prioMap[S.top()] >= prioMap[ch])
				{
					vec.push_back(string(1, S.top()));
					S.pop();
				}
				S.push(ch);
			}
		}
		while (S.top() != '#')
		{
			vec.push_back(string(1, S.top()));
			S.pop();
		}
	}

	int EvalRPN(vector<string>& vec)
	{
		stack<int> S;
		int len = vec.size();
		for (size_t i = 0; i < len; i++)
		{
			int num;
			if (vec[i] == "+")
			{
				num = S.top();
				S.pop();
				S.top() += num;
			}
			else  if (vec[i] == "-")
			{
				num = S.top();
				S.pop();
				S.top() -= num;
			}
			else if (vec[i] == "*")
			{
				num = S.top();
				S.pop();
				S.top() *= num;
			}
			else if (vec[i] == "/")
			{
				num = S.top();
				S.pop();
				S.top() /= num;
			}
			else
			{
				S.push(stoi(vec[i]));
			}
		}
		return S.top();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution223 {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int X1 = max(A, E);
		int Y1 = max(B, F);
		int X2 = min(C, G);
		int Y2 = min(D, H);
		int A1 = abs(A - C)*abs(B - D);
		int A2 = abs(E - G)*abs(F - H);
		int A3 = abs(X1 - X2)*abs(Y1 - Y2);
		if (X1 < X2&&Y1 < Y2)
		{
			return A1 + A2 - A3;
		}
		else
		{
			return A1 + A2;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution222 {
public:
	int countNodes(TreeNode* root) {
		if (root)
		{
			int lDepth = GetLDepth(root->left);
			int rDepth = GetRDepth(root->right);
			if (lDepth == rDepth)
			{
				return (1 << (lDepth + 1)) - 1;
			}
			else
			{
				return countNodes(root->left) + countNodes(root->right) + 1;
			}
		}
		else
		{
			return 0;
		}
	}
	int GetLDepth(TreeNode* root)
	{
		int cnt = 0;
		while (root)
		{
			cnt++;
			root = root->left;
		}
		return cnt;
	}
	int GetRDepth(TreeNode* root)
	{
		int cnt = 0;
		while (root)
		{
			cnt++;
			root = root->right;
		}
		return cnt;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution221 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int M = matrix.size();
		int N = 0;
		if (M)
		{
			N = matrix[0].size();
		}
		int maxLen = 0;
		if (M&&N)
		{
			vector<vector<int>> dp(M, vector<int>(N, 0));
			for (size_t i = 0; i < M; i++)
			{
				dp[i][0] = matrix[i][0] - '0';
			}
			for (size_t i = 0; i < N; i++)
			{
				dp[0][i] = matrix[0][i] - '0';
			}
			for (size_t i = 1; i < M; i++)
			{
				for (size_t j = 1; j < N; j++)
				{
					if (matrix[i][j] == '1')
					{
						dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					}
				}
			}
			for (size_t i = 0; i < M; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					maxLen = max(maxLen, dp[i][j]);
				}
			}
		}
		return maxLen*maxLen;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<long long, int> M;
		int l = 0;
		for (int r = 0; r < nums.size(); r++) {
			if (r - l > k && M[nums[l]] == l)
				M.erase(nums[l++]);
			auto it = M.lower_bound(nums[r] - t);
			if (it != M.end() && abs(it->first - nums[r]) <= t)
				return true;
			M[nums[r]] = r;
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution219 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int len = nums.size();
		unordered_map<int, vector<int>> ump;
		for (size_t i = 0; i < len; i++)
		{
			ump[nums[i]].push_back(i);
		}
		for (auto m : ump)
		{
			if (m.second.size() == 2 && abs(m.second[0] - m.second[1]) <= k)
			{
				return true;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution217 {
public:
	bool containsDuplicate(vector<int>& nums) {
		int len = nums.size();
		unordered_set<int> ust;
		for (size_t i = 0; i < len; i++)
		{
			if (ust.find(nums[i]) != ust.end())
			{
				return true;
			}
			ust.insert(nums[i]);
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution216 {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> vec;
		GetComb(result, vec, 0, k, n, 0);
		return result;
	}
	void GetComb(vector<vector<int>>& result, vector<int>& vec, int index, int cnt, int target, int sum)
	{
		if (vec.size() == cnt)
		{
			if (sum == target)
			{
				result.push_back(vec);
			}
		}
		else
		{
			for (int i = index + 1; i <= 9; i++)
			{
				vec.push_back(i);
				GetComb(result, vec, i, cnt, target, sum + i);
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution215 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> heap;
		int len = nums.size();
		for (size_t i = 0; i < k; i++)
		{
			heap.push(nums[i]);
		}
		for (size_t i = k; i < len; i++)
		{
			if (nums[i] > heap.top())
			{
				heap.pop();
				heap.push(nums[i]);
			}
		}
		return heap.top();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution213 {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		int maxProf = 0;
		if (len > 0)
		{
			vector<int> dp(len, 0);
			dp[0] = nums[0];
			if (len == 1)
			{
				return dp[0];
			}
			dp[1] = nums[0];
			for (size_t i = 2; i < len - 1; i++)
			{
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			}
			maxProf = dp[len - 2];
			dp[0] = 0;
			dp[1] = nums[1];
			for (size_t i = 2; i < len; i++)
			{
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			}
			maxProf = max(maxProf, dp[len - 1]);
		}
		return maxProf;
	}
};
/*-------------------------------------------------------------------------------------*/
class WordDictionary {
public:

	class TrieNode {
	public:
		// Initialize your data structure here.
		TrieNode() {
			isWord = false;
			nextNodes.assign(26, NULL);
		}
		bool isWord;
		vector<TrieNode*> nextNodes;
	};

	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string s) {
			int len = s.size();
			if (len <= 0)
			{
				return;
			}
			TrieNode* pCur = root;
			for (size_t i = 0; i < len; i++)
			{
				if (!pCur->nextNodes[s[i] - 'a'])
				{
					pCur->nextNodes[s[i] - 'a'] = new TrieNode();

				}
				pCur = pCur->nextNodes[s[i] - 'a'];
			}
			pCur->isWord = true;
		}

		// Returns if the word is in the trie.
		bool search(string key, TrieNode* root) {
			int len = key.size();
			if (!root)
			{
				return false;
			}
			if (len == 0)
			{
				return root->isWord;
			}
			if (key[0] == '.')
			{
				for (size_t i = 0; i < 26; i++)
				{
					if (search(key.substr(1), root->nextNodes[i]))
					{
						return true;
					}
				}
				return false;
			}
			else
			{
				return search(key.substr(1), root->nextNodes[key[0] - 'a']);
			}
		}

		TrieNode* root;
	};


	// Adds a word into the data structure.
	void addWord(string word) {
		mTrieTree.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return mTrieTree.search(word, mTrieTree.root);
	}

	Trie mTrieTree;
};
/*-------------------------------------------------------------------------------------*/
class Solution210 {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result;
		vector<int> inDegree(numCourses, 0);
		int len = prerequisites.size();
		for (size_t i = 0; i < len; i++)
		{
			inDegree[prerequisites[i].first]++;
		}
		while (true)
		{
			int index = -1;
			for (int i = 0; i < numCourses; i++)
			{
				if (inDegree[i] == 0)
				{
					index = i;
					result.push_back(i);
					inDegree[i] = -1;
					break;
				}
			}
			if (index == -1)
			{
				if (accumulate(inDegree.begin(), inDegree.end(), 0) != -numCourses)
				{
					result.clear();
				}
				return result;
			}
			else
			{
				for (size_t i = 0; i < len; i++)
				{
					if (prerequisites[i].second == index)
					{
						inDegree[prerequisites[i].first]--;
					}
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution209 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		int sum = 0;
		int minLen = len + 1;
		int L = 0, R = 0;
		while (R < len)
		{
			while (sum < s&&R < len)
			{
				sum += nums[R];
				R++;
			}
			while (sum >= s&&L < len)
			{
				minLen = min(minLen, R - L);
				sum -= nums[L];
				L++;
			}
		}
		return minLen > len ? 0 : minLen;
	}
};
/*-------------------------------------------------------------------------------------*/
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		isWord = false;
		nextNodes.assign(26, NULL);
	}
	bool isWord;
	vector<TrieNode*> nextNodes;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		int len = s.size();
		if (len <= 0)
		{
			return;
		}
		TrieNode* pCur = root;
		for (size_t i = 0; i < len; i++)
		{
			if (!pCur->nextNodes[s[i] - 'a'])
			{
				pCur->nextNodes[s[i] - 'a'] = new TrieNode();

			}
			pCur = pCur->nextNodes[s[i] - 'a'];
		}
		pCur->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		int len = key.size();
		if (len <= 0)
		{
			return true;
		}
		TrieNode* pCur = root;
		for (size_t i = 0; i < len; i++)
		{
			pCur = pCur->nextNodes[key[i] - 'a'];
			if (!pCur)
			{
				return false;
			}
		}
		return pCur->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		int len = prefix.size();
		if (len <= 0)
		{
			return true;
		}
		TrieNode* pCur = root;
		for (size_t i = 0; i < len; i++)
		{
			pCur = pCur->nextNodes[prefix[i] - 'a'];
			if (!pCur)
			{
				return false;
			}
		}
		return true;
	}

private:
	TrieNode* root;
};
/*-------------------------------------------------------------------------------------*/
class Solution207 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses > 1)
		{
			vector<int> inDegree(numCourses, 0);
			int len = prerequisites.size();
			for (size_t i = 0; i < len; i++)
			{
				inDegree[prerequisites[i].first]++;
			}
			while (true)
			{
				int index = -1;
				for (int i = 0; i < numCourses; i++)
				{
					if (inDegree[i] == 0)
					{
						index = i;
						inDegree[i] = -1;
						break;
					}
				}
				if (index == -1)
				{
					return accumulate(inDegree.begin(), inDegree.end(), 0) == -numCourses;
				}
				else
				{
					for (size_t i = 0; i < len; i++)
					{
						if (prerequisites[i].second == index)
						{
							inDegree[prerequisites[i].first]--;
						}
					}
				}
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution206 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* fakeHead = new ListNode(-1);
		ListNode* pCur = head;
		ListNode* pNext = head;
		while (pCur)
		{
			pNext = pCur->next;
			pCur->next = fakeHead->next;
			fakeHead->next = pCur;
			pCur = pNext;
		}
		return fakeHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution205 {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> ump1;
		unordered_map<char, char> ump2;
		int len = s.size();
		for (size_t i = 0; i < len; i++)
		{
			if (ump1.find(s[i]) != ump1.end())
			{
				if (ump1[s[i]] != t[i])
				{
					return false;
				}
			}
			else
			{
				ump1[s[i]] = t[i];
			}
			if (ump2.find(t[i]) != ump2.end())
			{
				if (ump2[t[i]] != s[i])
				{
					return false;
				}
			}
			else
			{
				ump2[t[i]] = s[i];
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution204 {
public:
	int countPrimes(int n) {
		vector<int> isPrime(n, 1);
		int cnt = 0;
		if (n > 0)
		{
			isPrime[0] = 0;
			isPrime[1] = 0;
			int m = sqrt(n);
			int index = 2;
			while (index <= m)
			{
				if (isPrime[index])
				{
					for (int i = index + index; i < n; i += index)
					{
						isPrime[i] = 0;
					}
				}
				index++;
			}
		}
		cnt = accumulate(isPrime.begin(), isPrime.end(), 0);
		return cnt;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution203 {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* fakeNode = new ListNode(INT_MAX);
		fakeNode->next = head;
		ListNode* pCur = fakeNode;
		ListNode* pPre = fakeNode;
		while (pCur)
		{
			if (pCur->val == val)
			{
				pPre->next = pCur->next;
				pCur = pCur->next;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution202 {
public:
	bool isHappy(int n) {
		unordered_set<int> ust;
		while (true)
		{
			int sqSum = GetSumSquare(n);
			if (sqSum == 1)
			{
				return true;
			}
			if (ust.find(sqSum) != ust.end())
			{
				return false;
			}
			else
			{
				ust.insert(sqSum);
			}
			n = sqSum;
		}
	}
	int GetSumSquare(int num)
	{
		int res = 0;
		while (num)
		{
			int digit = num % 10;
			num /= 10;
			res += digit*digit;
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (n > m)
		{
			n = n&(n - 1);
		}
		return m&n;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution200 {
public:
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		int M = grid.size();
		int N = 0;
		if (M)
		{
			N = grid[0].size();
		}
		if (M&&N)
		{
			vector<vector<bool>> isVisited(M, vector<bool>(N, false));
			for (size_t i = 0; i < M; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					if (DFS(grid, isVisited, M, N, i, j))
					{
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
	bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& isVisited, int M, int N, int iIndex, int jIndex)
	{
		if (isVisited[iIndex][jIndex] || grid[iIndex][jIndex] == '0')
		{
			return false;
		}
		isVisited[iIndex][jIndex] = true;
		if (iIndex - 1 >= 0 && !isVisited[iIndex - 1][jIndex])
		{
			DFS(grid, isVisited, M, N, iIndex - 1, jIndex);
		}
		if (jIndex - 1 >= 0 && !isVisited[iIndex][jIndex - 1])
		{
			DFS(grid, isVisited, M, N, iIndex, jIndex - 1);
		}
		if (iIndex + 1 < M && !isVisited[iIndex + 1][jIndex])
		{
			DFS(grid, isVisited, M, N, iIndex + 1, jIndex);
		}
		if (jIndex + 1 < N && !isVisited[iIndex][jIndex + 1])
		{
			DFS(grid, isVisited, M, N, iIndex, jIndex + 1);
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution199 {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> qu;
		vector<int> result;
		if (root)
		{
			qu.push(root);
			int curCnt = 1;
			int nextCnt = 0;
			while (!qu.empty())
			{
				TreeNode* cur = qu.front();
				qu.pop();
				curCnt--;
				if (cur->left)
				{
					qu.push(cur->left);
					nextCnt++;
				}
				if (cur->right)
				{
					qu.push(cur->right);
					nextCnt++;
				}
				if (!curCnt)
				{
					curCnt = nextCnt;
					nextCnt = 0;
					result.push_back(cur->val);
				}
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution198 {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len + 1, 0);
		if (len == 0)
		{
			return 0;
		}
		dp[1] = nums[0];
		for (size_t i = 2; i <= len; i++)
		{
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		}
		return dp[len];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution191 {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n)
		{
			n &= (n - 1);
			cnt++;
		}
		return cnt;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution190 {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (size_t i = 0; i < 32; i++)
		{
			uint32_t bit = (n >> i) & 0x1;
			res = (res << 1) | bit;
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution189 {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		if (k > 0 && len > 0)
		{
			Reverse(nums, 0, len - k - 1);
			Reverse(nums, len - k, len - 1);
			Reverse(nums, 0, len - 1);
		}
	}
	void Reverse(vector<int>& nums, int L, int R)
	{
		while (L < R)
		{
			swap(nums[L], nums[R]);
			L++;
			R--;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution187 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<char, int> chMap{ { 'A', 0 }, { 'C', 1 }, { 'T', 2 }, { 'G', 3 } };
		vector<string> res;
		unordered_map<int, int> mp;
		int len = s.size();
		for (int i = 0; i + 9 < len; i++)
		{
			string str = s.substr(i, 10);
			if (++mp[Str2Int(chMap, str)] == 2)
			{
				res.push_back(str);
			}
		}
		return res;
	}
	int Str2Int(unordered_map<char, int>& chMap, string str)
	{
		int len = str.size();
		int res = 0;
		for (size_t i = 0; i < len; i++)
		{
			res = res * 4 + chMap[str[i]];
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution179 {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> vec;
		for (size_t i = 0; i < nums.size(); i++)
		{
			vec.push_back(to_string(nums[i]));
		}
		sort(vec.begin(), vec.end(), Cmp);
		string res;
		if (vec[0] == "0")
		{
			return vec[0];
		}
		for (size_t i = 0; i < vec.size(); i++)
		{
			res += vec[i];
		}
		return res;
	}
	static bool Cmp(string str1, string str2)
	{
		return str1 + str2 > str2 + str1;
	}
};
/*-------------------------------------------------------------------------------------*/
class BSTIterator {
public:
	stack<TreeNode*> st;
	BSTIterator(TreeNode *root) {
		while (root)
		{
			st.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* curNode = st.top();
		st.pop();
		int res = curNode->val;
		if (curNode->right)
		{
			curNode = curNode->right;
			while (curNode)
			{
				st.push(curNode);
				curNode = curNode->left;
			}
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution172 {
public:
	int trailingZeroes(int n) {
		int cnt = 0;
		long x = 5;
		while (x > 0 && n >= x)
		{
			cnt += n / x;
			x *= 5;
		}
		return cnt;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution171 {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			res = res * 26 + (s[i] - 'A' + 1);
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution169 {
public:
	int majorityElement(vector<int>& nums) {
		int majNum;
		int iCnt = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] == majNum)
			{
				iCnt++;
			}
			else if (iCnt == 0)
			{
				majNum = nums[i];
				iCnt++;
			}
			else
			{
				iCnt--;
			}
		}
		return majNum;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution168 {
public:
	string convertToTitle(int n) {
		string res;
		while (n)
		{
			res += ((n - 1) % 26 + 'A');
			n = (n - 1) / 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution166 {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
		{
			return "0";
		}
		vector<long long> integerList;
		vector<long long> decimalList;
		vector<long long> remainList;
		int loopIndex = -1;
		bool isNeg = false;
		if (numerator < 0 ^ denominator < 0)
		{
			isNeg = true;
		}
		long long numerator1 = numerator;
		numerator1 = abs(numerator1);
		long long denominator1 = denominator;
		denominator1 = abs(denominator1);
		if (numerator1 > denominator1)
		{
			integerList.push_back(numerator1 / denominator1);
			numerator1 = numerator1 % denominator1;
		}
		long remain = numerator1;
		long decimal = (remain * 10) / denominator1;
		decimalList.push_back(decimal);
		remainList.push_back(remain);
		while (remain != 0)
		{
			remain = (remain * 10) % denominator1;
			decimal = (remain * 10) / denominator1;
			decimalList.push_back(decimal);
			auto loopValue = find(remainList.begin(), remainList.end(), remain);
			if (loopValue != remainList.end())
			{
				loopIndex = *loopValue;
				break;
			}
			else
			{
				remainList.push_back(remain);
			}
		}
		if (!remain || loopIndex != -1)
		{
			decimalList.erase(decimalList.end() - 1);
		}
		string res;
		if (isNeg)
		{
			res += "-";
		}
		if (integerList.size() == 0)
		{
			res += "0";
		}
		else
		{
			for (size_t i = 0; i < integerList.size(); i++)
			{
				res += to_string(integerList[i]);
			}
		}
		if (decimalList.size() != 0)
		{
			res += ".";
			if (loopIndex != -1)
			{
				for (size_t i = 0; i < remainList.size(); i++)
				{
					if (loopIndex == remainList[i])
					{
						loopIndex = i;
						break;
					}
				}
				for (int i = 0; i < loopIndex; i++)
				{
					res += to_string(decimalList[i]);
				}
				res += "(";
				for (int i = loopIndex; i < decimalList.size(); i++)
				{
					res += to_string(decimalList[i]);
				}
				res += ")";
			}
			else
			{
				for (size_t i = 0; i < decimalList.size(); i++)
				{
					res += to_string(decimalList[i]);
				}
			}
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution165 {
public:
	int compareVersion(string version1, string version2) {
		vector<int> vList1;
		vector<int> vList2;
		istringstream iss1(version1);
		istringstream iss2(version2);
		string strVerNum;
		while (getline(iss1, strVerNum, '.'))
		{
			vList1.push_back(stoi(strVerNum));
		}
		while (getline(iss2, strVerNum, '.'))
		{
			vList2.push_back(stoi(strVerNum));
		}
		int len1 = vList1.size();
		int len2 = vList2.size();
		int diff = abs(len1 - len2);
		if (len1 > len2)
		{
			while (diff--)
			{
				vList2.push_back(0);
			}
		}
		else
		{
			while (diff--)
			{
				vList1.push_back(0);
			}
		}
		int len = max(len1, len2);
		int i = 0;
		while (i < len)
		{
			if (vList1[i] < vList2[i])
			{
				return -1;
			}
			else if (vList1[i] > vList2[i])
			{
				return 1;
			}
			i++;
		}
		return 0;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution162 {
public:
	int findPeakElement(vector<int>& nums) {
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] < nums[M + 1])
			{
				L = M + 1;
			}
			else
			{
				R = M;
			}
		}
		return L;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution160 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
		{
			return NULL;
		}
		int lenA = 0;
		int lenB = 0;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while (pA)
		{
			lenA++;
			pA = pA->next;
		}
		while (pB)
		{
			lenB++;
			pB = pB->next;
		}
		ListNode* pL = NULL;
		ListNode* pS = NULL;
		if (lenA > lenB)
		{
			pL = headA;
			pS = headB;
		}
		else
		{
			pL = headB;
			pS = headA;
		}
		int dist = abs(lenA - lenB);
		while (dist--)
		{
			pL = pL->next;
		}
		while (pL)
		{
			if (pL == pS)
			{
				break;
			}
			pL = pL->next;
			pS = pS->next;
		}
		return pL;
	}
};
/*-------------------------------------------------------------------------------------*/
class MinStack {
public:
	stack<int> st;
	stack<int> stMin;

	void push(int x) {
		st.push(x);
		if (stMin.empty() || x <= stMin.top())
		{
			stMin.push(x);
		}
	}

	void pop() {
		if (!st.empty())
		{
			if (st.top() == stMin.top())
			{
				stMin.pop();
			}
			st.pop();
		}
	}

	int top() {
		if (!st.empty())
		{
			return st.top();
		}
	}

	int getMin() {
		if (!stMin.empty())
		{
			return stMin.top();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution154 {
public:
	int findMin(vector<int>& nums) {
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] < nums[R])
			{
				R = M;
			}
			else if (nums[M] > nums[R])
			{
				L = M + 1;
			}
			else
			{
				R--;
			}
		}
		return nums[L];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution153 {
public:
	int findMin(vector<int>& nums) {
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] < nums[R])
			{
				R = M;
			}
			else
			{
				L = M + 1;
			}
		}
		return nums[L];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution152 {
public:
	int maxProduct(vector<int>& nums) {
		int gMax = nums[0];
		int lMax = nums[0];
		int lMin = nums[0];
		int len = nums.size();
		for (int i = 1; i < len; i++)
		{
			int tmpMin = lMin;
			lMin = min(nums[i], min(lMax*nums[i], lMin*nums[i]));
			lMax = max(lMax*nums[i], max(tmpMin*nums[i], nums[i]));
			gMax = max(gMax, lMax);
		}
		return gMax;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution151 {
public:
	void reverseWords(string &s)
	{
		string rs;
		for (int i = s.length() - 1; i >= 0;)
		{
			while (i >= 0 && s[i] == ' ') i--;
			if (i < 0) break;
			if (!rs.empty()) rs.push_back(' ');
			string t;
			while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
			reverse(t.begin(), t.end());
			rs.append(t);
		}
		s = rs;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution149 {
public:
	int evalRPN(vector<string>& tokens) {
		unordered_map<string, function<int(int, int)>> mpFunc =
		{
			{ "+",[](int a,int b) {return a + b; } },
			{ "-",[](int a,int b) {return a - b; } },
			{ "*",[](int a,int b) {return a * b; } },
			{ "/",[](int a,int b) {return a / b; } }
		};
		stack<int> st;
		int len = tokens.size();
		if (len > 0)
		{
			for (size_t i = 0; i < len; i++)
			{
				if (mpFunc.find(tokens[i]) != mpFunc.end())
				{
					int Op2 = st.top();
					st.pop();
					int Op1 = st.top();
					st.pop();
					st.push(mpFunc[tokens[i]](Op1, Op2));
				}
				else
				{
					st.push(stoi(tokens[i]));
				}
			}
		}
		return st.empty() ? -1 : st.top();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution148 {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		ListNode* pSlow = fakeNode;
		ListNode* pFast = fakeNode;
		while (pFast&&pFast->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		pFast = sortList(pSlow->next);
		pSlow->next = NULL;
		pSlow = sortList(head);
		return Merge(pSlow, pFast);
	}

	ListNode* Merge(ListNode* L1, ListNode* L2)
	{
		if (!L1)
		{
			return L2;
		}
		if (!L2)
		{
			return L1;
		}
		ListNode* fakeNode = new ListNode(0);
		ListNode* pCur = fakeNode;
		while (L1&&L2)
		{
			if (L1->val < L2->val)
			{
				pCur->next = L1;
				L1 = L1->next;
			}
			else
			{
				pCur->next = L2;
				L2 = L2->next;
			}
			pCur = pCur->next;
		}
		if (L1)
		{
			pCur->next = L1;
		}
		if (L2)
		{
			pCur->next = L2;
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		vector<ListNode*> vec;
		ListNode* pCur = head;
		while (pCur)
		{
			vec.push_back(pCur);
			pCur = pCur->next;
		}
		sort(vec.begin(), vec.end(), Cmp);
		if (vec.size() == 0)
		{
			return head;
		}
		head = vec[0];
		pCur = head;
		for (size_t i = 1; i < vec.size(); i++)
		{
			pCur->next = vec[i];
			pCur = vec[i];
		}
		pCur->next = NULL;
		return head;
	}
	static bool Cmp(ListNode* ln1, ListNode* ln2)
	{
		return ln1->val < ln2->val;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		if (root)
		{
			st.push(root);
			while (!st.empty())
			{
				TreeNode* cur = st.top();
				st.pop();
				res.push_back(cur->val);
				if (cur->left)
				{
					st.push(cur->left);
				}
				if (cur->right)
				{
					st.push(cur->right);
				}
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution144 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		if (root)
		{
			st.push(root);
			while (!st.empty())
			{
				TreeNode* cur = st.top();
				st.pop();
				res.push_back(cur->val);
				if (cur->right)
				{
					st.push(cur->right);
				}
				if (cur->left)
				{
					st.push(cur->left);
				}
			}
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution143 {
public:
	void reorderList(ListNode *head) {
		if (head == NULL) return;
		// find the median node
		ListNode* fast = head;
		ListNode* slow = head;
		while (true)
		{
			fast = fast->next;
			if (fast == NULL)
				break;
			fast = fast->next;
			if (fast == NULL)
				break;
			slow = slow->next;
		}

		if (slow == NULL) return;

		// reverse second half of link list
		ListNode* cur = slow;
		ListNode* pre = slow->next;
		cur->next = NULL;
		while (pre != NULL)
		{
			ListNode* temp = pre->next;
			pre->next = cur;
			cur = pre;
			pre = temp;
		}

		// merge two lists
		ListNode* first = head;
		ListNode* second = cur;

		while (second != NULL&& first != NULL && first != second)
		{
			ListNode* temp = second->next;
			second->next = first->next;
			first->next = second;
			first = second->next;
			second = temp;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution142 {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		ListNode* pSlow = fakeNode;
		ListNode* pFast = fakeNode;
		while (pFast&&pFast->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pSlow == pFast)
			{
				break;
			}
		}
		if (!pFast || !pFast->next)
		{
			return NULL;
		}
		pFast = fakeNode;
		while (pFast != pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution141 {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		ListNode* pSlow = fakeNode;
		ListNode* pFast = fakeNode;
		while (pFast&&pFast->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pSlow == pFast)
			{
				return true;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution139 {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		s = '#' + s;
		int len = s.size();
		vector<bool> isOK(len, true);
		for (size_t i = 1; i < len; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				isOK[i] = isOK[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end();
				if (isOK[i])
				{
					break;
				}
			}
		}
		return isOK[len - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution137 {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> mp;
		for (size_t i = 0; i < nums.size(); i++)
		{
			mp[nums[i]]++;
		}
		for (auto m : mp)
		{
			if (m.second == 1)
			{
				return m.first;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution136 {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int res = 0;
		for (size_t i = 0; i < len; i++)
		{
			res ^= nums[i];
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution135 {
public:
	int candy(vector<int>& ratings) {
		vector<int> candy(ratings.size());
		candy[0] = 1;
		int i = 1;
		for (; i < ratings.size(); ++i)
		{
			if (ratings[i] > ratings[i - 1]) //递增  
			{
				candy[i] = candy[i - 1] + 1;
			}
			if (ratings[i] == ratings[i - 1]) //平行  
			{
				candy[i] = 1;
			}
			if (ratings[i] < ratings[i - 1]) //递减  
			{
				candy[i] = candy[i - 1] - 1;
			}
			if (i < ratings.size() - 1 && ratings[i] < ratings[i - 1] && ratings[i] <= ratings[i + 1])
				ReAdjustCandy(ratings, candy, i);
		}
		if (ratings[i - 1] < ratings[i - 2])
			ReAdjustCandy(ratings, candy, ratings.size() - 1);
		int total = 0;
		std::for_each(candy.begin(), candy.end(), [&](int n) {
			total += n;
		});
		return total;
	}
	void ReAdjustCandy(vector<int>& ratings, vector<int>& candy, int startIndex)
	{
		int k = startIndex;
		int diff = 1 - candy[k];
		while (k > 0 && ratings[k - 1] > ratings[k])
		{
			candy[k] = candy[k] + diff;
			k--;
		}
		if (diff > 0) candy[k] += diff;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution134 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		if (len == 0)
		{
			return -1;
		}
		vector<int> res(len, 0);
		for (size_t i = 0; i < gas.size(); i++)
		{
			res[i] = gas[i] - cost[i];
		}
		int index = 0;
		int sum = 0;
		int leftGas = 0;
		for (size_t i = 0; i < res.size(); i++)
		{
			sum += res[i];
			leftGas += res[i];
			if (sum < 0)
			{
				sum = 0;
				index = i + 1;
			}
		}
		return leftGas >= 0 ? index : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution133 {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
		{
			return NULL;
		}
		queue<UndirectedGraphNode*> qu;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
		qu.push(node);
		UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
		mp[node] = nodeCopy;
		while (!qu.empty())
		{
			UndirectedGraphNode* curNode = qu.front();
			qu.pop();
			for (size_t i = 0; i < curNode->neighbors.size(); i++)
			{
				if (mp.find(curNode->neighbors[i]) == mp.end())
				{
					UndirectedGraphNode* newNode = new UndirectedGraphNode(curNode->neighbors[i]->label);
					mp[curNode->neighbors[i]] = newNode;
					mp[curNode]->neighbors.push_back(newNode);
					qu.push(curNode->neighbors[i]);
				}
				else
				{
					mp[curNode]->neighbors.push_back(mp[curNode->neighbors[i]]);
				}
			}
		}
		return nodeCopy;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution132 {
public:
	int minCut(string s) {
		int len = s.size();
		vector<int> D(len + 1);
		vector<vector<bool>> P(len, vector<bool>(len, false));
		for (int i = 0; i <= len; i++)
			D[i] = len - i;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len; j++) {
				if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1])) {
					P[i][j] = true;
					D[i] = min(D[i], D[j + 1] + 1);
				}
			}
		}
		return D[0] - 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution131 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> vec;
		int len = s.size();
		if (len > 0)
		{
			GetPa(result, vec, s, 0);
		}
		return result;
	}
	void GetPa(vector<vector<string>>& result, vector<string>& vec, string& s, int index)
	{
		if (index == s.size())
		{
			result.push_back(vec);
		}
		else
		{
			for (int i = 1; i + index - 1 < s.size(); i++)
			{
				string strPa = s.substr(index, i);
				if (IsPa(strPa))
				{
					vec.push_back(strPa);
					GetPa(result, vec, s, i + index);
				}
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
	bool IsPa(string& str)
	{
		int L = 0;
		int R = str.size() - 1;
		while (L < R)
		{
			if (str[L] != str[R])
			{
				return false;
			}
			L++;
			R--;
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution130 {
public:
	void solve(vector<vector<char>>& board) {
		int M = board.size();
		int N = 0;
		if (M)
		{
			N = board[0].size();
		}
		if (M&&N)
		{
			vector<int> xList;
			vector<int> yList;
			for (size_t i = 0; i < M; i++)
			{
				if (board[i][0] == 'O')
				{
					board[i][0] = 'N';
					xList.push_back(i);
					yList.push_back(0);
				}
				if (board[i][N - 1] == 'O')
				{
					board[i][N - 1] = 'N';
					xList.push_back(i);
					yList.push_back(N - 1);
				}
			}
			for (size_t i = 1; i < N - 1; i++)
			{
				if (board[0][i] == 'O')
				{
					board[0][i] = 'N';
					xList.push_back(0);
					yList.push_back(i);
				}
				if (board[M - 1][i] == 'O')
				{
					board[M - 1][i] = 'N';
					xList.push_back(M - 1);
					yList.push_back(i);
				}
			}
			int index = 0;
			while (index < xList.size())
			{
				int X = xList[index];
				int Y = yList[index];
				if (X - 1 >= 0 && board[X - 1][Y] == 'O')
				{
					board[X - 1][Y] = 'N';
					xList.push_back(X - 1);
					yList.push_back(Y);
				}
				if (Y - 1 >= 0 && board[X][Y - 1] == 'O')
				{
					board[X][Y - 1] = 'N';
					xList.push_back(X);
					yList.push_back(Y - 1);
				}
				if (X + 1 < M && board[X + 1][Y] == 'O')
				{
					board[X + 1][Y] = 'N';
					xList.push_back(X + 1);
					yList.push_back(Y);
				}
				if (Y + 1 < N && board[X][Y + 1] == 'O')
				{
					board[X][Y + 1] = 'N';
					xList.push_back(X);
					yList.push_back(Y + 1);
				}
				index++;
			}
			for (size_t i = 0; i < M; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					if (board[i][j] == 'O')
					{
						board[i][j] = 'X';
					}
					if (board[i][j] == 'N')
					{
						board[i][j] = 'O';
					}
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution129 {
public:
	int sumNumbers(TreeNode* root) {
		vector<int> result;
		GetSum(result, root, 0);
		return accumulate(result.begin(), result.end(), 0);
	}
	void GetSum(vector<int>& result, TreeNode* root, int sum)
	{
		if (!root)
		{
			return;
		}
		if (!root->left&&!root->right)
		{
			result.push_back(sum * 10 + root->val);
		}
		if (root->left)
		{
			GetSum(result, root->left, sum * 10 + root->val);
		}
		if (root->right)
		{
			GetSum(result, root->right, sum * 10 + root->val);
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution127 {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if (start.size() != end.size())
			return 0;
		if (start.empty() || end.empty())
			return 1;
		if (dict.size() == 0)
			return 0;
		int distance = 1; //!!!  
		queue<string> queToPush, queToPop;
		queToPop.push(start);
		while (dict.size() > 0 && !queToPop.empty())
		{
			while (!queToPop.empty())
			{
				string str(queToPop.front()); //!!!how to initialize the str  
				queToPop.pop(); //!!! should pop after it is used up  
				for (int i = 0; i < str.size(); i++)
				{
					for (char j = 'a'; j <= 'z'; j++)
					{
						if (j == str[i])
							continue;
						char temp = str[i];
						str[i] = j;
						if (str == end)
							return distance + 1; //found it  
						if (dict.count(str) > 0) //exists in dict  
						{
							queToPush.push(str); //find all the element that is one edit away  
							dict.erase(str); //delete corresponding element in dict in case of loop  
						}
						str[i] = temp; //  
					}
				}
			}
			swap(queToPush, queToPop); //!!! how to use swap  
			distance++;
		} //end while  
		return 0; //all the dict words are used up and we do not find dest word  
	} //end function  
};
/*-------------------------------------------------------------------------------------*/
class Solution125 {
public:
	bool isPalindrome(string s) {
		int len = s.size();
		if (len > 0)
		{
			int L = 0;
			int R = len - 1;
			while (L < R)
			{
				while (L < len&&!isalnum(s[L]))L++;
				while (R >= 0 && !isalnum(s[R]))R--;
				if (L < R)
				{
					if (tolower(s[L]) != tolower(s[R]))
					{
						return false;
					}
				}
				else
				{
					break;
				}
				L++;
				R--;
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution124 {
public:
	int maxVal = INT_MIN;
	int maxPathSum(TreeNode* root) {
		GetMax(root);
		return maxVal;
	}

	int GetMax(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int lMax = GetMax(root->left);
		int rMax = GetMax(root->right);
		maxVal = max(lMax + rMax + root->val, maxVal);
		int ret = max(lMax, rMax) + root->val;
		return ret > 0 ? ret : 0;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution123 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1)
		{
			return 0;
		}
		vector<int> maxFromHead(len, 0);
		int minprice = prices[0], maxprofit = 0;
		for (int i = 1; i < len; i++)
		{
			minprice = min(prices[i - 1], minprice);
			if (prices[i] - minprice > maxprofit)
			{
				maxprofit = prices[i] - minprice;
			}
			maxFromHead[i] = maxprofit;
		}
		int maxprice = prices[len - 1];
		int res = maxFromHead[len - 1];
		maxprofit = 0;
		for (int i = len - 2; i >= 0; i--)
		{
			maxprice = max(maxprice, prices[i + 1]);
			if (maxprofit < maxprice - prices[i])
			{
				maxprofit = maxprice - prices[i];
			}
			if (res < maxFromHead[i] + maxprofit)
				res = maxFromHead[i] + maxprofit;
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution122 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int res = 0;
		if (len >= 2)
		{
			int index = 1;
			while (index < len)
			{
				int minIndex;
				int maxIndex;
				while (index < len&&prices[index] <= prices[index - 1])index++;
				minIndex = index - 1;
				while (index < len&&prices[index] >= prices[index - 1])index++;
				maxIndex = index - 1;
				res += (prices[maxIndex] - prices[minIndex]);
			}
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1)
		{
			return 0;
		}
		int minVal = prices[0];
		int result = prices[1] - minVal;
		for (size_t i = 2; i < len; i++)
		{
			minVal = min(minVal, prices[i - 1]);
			result = prices[i] - minVal > result ? prices[i] - minVal : result;
		}
		return result > 0 ? result : 0;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution120 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		for (int i = len - 2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution119 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1, 1);
		if (rowIndex >= 0)
		{
			for (int i = 2; i <= rowIndex + 1; i++)
			{
				for (int j = i - 2; j >= 1; j--)
				{
					result[j] = result[j] + result[j - 1];
				}
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution118 {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows > 0)
		{
			result.push_back(vector < int > {1});
			for (int i = 2; i <= numRows; i++)
			{
				int index = result.size() - 1;
				vector<int> vec(i, 1);
				for (int j = 0; j < i - 2; j++)
				{
					vec[j + 1] = result[index][j] + result[index][j + 1];
				}
				result.push_back(vec);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution117 {
public:
	void connect(TreeLinkNode *root) {
		if (root)
		{
			TreeLinkNode* p = root->next;
			while (p)
			{
				if (p->left)
				{
					p = p->left;
					break;
				}
				if (p->right)
				{
					p = p->right;
					break;
				}
				p = p->next;
			}
			if (root->right)
			{
				root->right->next = p;
			}
			if (root->left)
			{
				root->left->next = root->right ? root->right : p;
			}
			connect(root->right);
			connect(root->left);
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution116 {
public:
	void connect(TreeLinkNode *root) {
		if (root)
		{
			if (root->left&&root->right)
			{
				root->left->next = root->right;
				if (root->right&&root->next)
				{
					root->right->next = root->next->left;
				}
				connect(root->left);
				connect(root->right);
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution114 {
public:
	TreeNode* lastNode = NULL;
	void flatten(TreeNode* root) {
		if (!root)
		{
			return;
		}
		TreeNode* rightNode = root->right;
		if (lastNode)
		{
			lastNode->left = NULL;
			lastNode->right = root;
		}
		lastNode = root;
		flatten(root->left);
		flatten(rightNode);
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution113 {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> vec;
		if (root)
		{
			GetPath(result, vec, sum, root, 0);
		}
		return result;
	}

	void GetPath(vector<vector<int>>& result, vector<int>& vec, int target, TreeNode* root, int sum)
	{
		vec.push_back(root->val);
		if (sum + root->val == target&&!root->left&&!root->right)
		{
			result.push_back(vec);
		}
		else
		{
			if (root->left)
			{
				GetPath(result, vec, target, root->left, sum + root->val);
			}
			if (root->right)
			{
				GetPath(result, vec, target, root->right, sum + root->val);
			}
		}
		vec.pop_back();
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution112 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
		{
			return false;
		}
		return hasPathSum(root, sum, 0);
	}

	bool hasPathSum(TreeNode* root, int target, int sum) {
		if (!root&&sum == target)
		{
			return true;
		}
		else
		{
			if (!root)
			{
				return false;
			}
			else
			{
				if (!root->left)
				{
					return hasPathSum(root->right, target, sum + root->val);
				}
				if (!root->right)
				{
					return hasPathSum(root->left, target, sum + root->val);
				}
				return hasPathSum(root->left, target, sum + root->val) || hasPathSum(root->right, target, sum + root->val);
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution111 {
public:
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (!root->left)
		{
			return minDepth(root->right) + 1;
		}
		if (!root->right)
		{
			return minDepth(root->left) + 1;
		}
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution110 {
public:
	bool isBalanced(TreeNode* root) {
		//if (!root)
		//{
		//	return true;
		//}
		//if (abs(Depth(root->left) - Depth(root->right)) > 1)
		//{
		//	return false;
		//}
		//return isBalanced(root->left) && isBalanced(root->right);
		return maxDepth(root) != -1;
	}

	int maxDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int L = maxDepth(root->left);
		if (L == -1)
		{
			return -1;
		}
		int R = maxDepth(root->right);
		if (R == -1)
		{
			return -1;
		}
		return abs(R - L) <= 1 ? max(L, R) + 1 : -1;
	}

	int Depth(TreeNode* root)
	{
		if (!root)
		{
			return NULL;
		}
		return max(Depth(root->left), Depth(root->right)) + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution109 {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* pCur = head;
		while (pCur)
		{
			len++;
			pCur = pCur->next;
		}
		return BuildBST(head, 0, len - 1);
	}

	TreeNode* BuildBST(ListNode*& head, int L, int R)
	{
		if (L > R)
		{
			return NULL;
		}
		int M = L + ((R - L) >> 1);
		TreeNode* left = BuildBST(head, L, M - 1);
		TreeNode* root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		root->right = BuildBST(head, M + 1, R);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution108 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return BuildBST(nums, 0, nums.size() - 1);
	}
	TreeNode* BuildBST(vector<int>& nums, int L, int R)
	{
		if (L > R)
		{
			return NULL;
		}
		int M = L + ((R - L) >> 1);
		TreeNode* root = new TreeNode(nums[M]);
		root->left = BuildBST(nums, L, M - 1);
		root->right = BuildBST(nums, M + 1, R);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution107 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> qu;
		vector<vector<int>> result;
		if (root)
		{
			int curCnt = 1;
			int nextCnt = 0;
			qu.push(root);
			vector<int> levelNodes;
			while (!qu.empty())
			{
				TreeNode* pCur = qu.front();
				qu.pop();
				curCnt--;
				levelNodes.push_back(pCur->val);
				if (pCur->left)
				{
					qu.push(pCur->left);
					nextCnt++;
				}
				if (pCur->right)
				{
					qu.push(pCur->right);
					nextCnt++;
				}
				if (curCnt == 0)
				{
					result.push_back(levelNodes);
					curCnt = nextCnt;
					nextCnt = 0;
					levelNodes.clear();
				}
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution106 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return Build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int iS, int iE, int pS, int pE)
	{
		if (pS > pE)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[pE]);
		int index = -1;
		for (int i = iS; i <= iE; i++)
		{
			if (postorder[pE] == inorder[i])
			{
				index = i;
				break;
			}
		}
		root->left = Build(inorder, postorder, iS, index - 1, pS, index - 1 - iS + pS);
		root->right = Build(inorder, postorder, index + 1, iE, pE - iE + index, pE - 1);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution105 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return Build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int pS, int pE, int iS, int iE)
	{
		if (pS > pE)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[pS]);
		int index = -1;
		for (int i = iS; i <= iE; i++)
		{
			if (preorder[pS] == inorder[i])
			{
				index = i;
				break;
			}
		}
		root->left = Build(preorder, inorder, pS + 1, index - iS + pS, iS, index - 1);
		root->right = Build(preorder, inorder, pE - iE + index + 1, pE, index + 1, iE);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution104 {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution103 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> qu;
		if (root)
		{
			qu.push(root);
		}
		vector<vector<int>> result;
		vector<int> vec;
		int curCnt = 1;
		int nextCnt = 0;
		bool isReversed = false;
		while (!qu.empty())
		{
			TreeNode* pCur = qu.front();
			qu.pop();
			vec.push_back(pCur->val);
			curCnt--;
			if (pCur->left)
			{
				qu.push(pCur->left);
				nextCnt++;
			}
			if (pCur->right)
			{
				qu.push(pCur->right);
				nextCnt++;
			}
			if (!curCnt)
			{
				if (isReversed)
				{
					reverse(vec.begin(), vec.end());
				}
				isReversed = !isReversed;
				curCnt = nextCnt;
				nextCnt = 0;
				result.push_back(vec);
				vec.clear();
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution102 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> qu;
		if (root)
		{
			qu.push(root);
		}
		vector<vector<int>> result;
		vector<int> vec;
		int curCnt = 1;
		int nextCnt = 0;
		while (!qu.empty())
		{
			TreeNode* pCur = qu.front();
			qu.pop();
			vec.push_back(pCur->val);
			curCnt--;
			if (pCur->left)
			{
				qu.push(pCur->left);
				nextCnt++;
			}
			if (pCur->right)
			{
				qu.push(pCur->right);
				nextCnt++;
			}
			if (!curCnt)
			{
				curCnt = nextCnt;
				nextCnt = 0;
				result.push_back(vec);
				vec.clear();
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution101 {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		return CheckSymmetric(root->left, root->right);
	}
	bool CheckSymmetric(TreeNode* left, TreeNode* right)
	{
		if ((left&&!right) || (!left&&right))
		{
			return false;
		}
		if (!left&&!right)
		{
			return true;
		}
		return (left->val == right->val) && CheckSymmetric(left->left, right->right) && CheckSymmetric(left->right, right->left);
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution100 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p&&!q)
		{
			return true;
		}
		if ((p&&!q) || (!p&&q))
		{
			return false;
		}
		if (p->val != q->val)
		{
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution099 {
public:
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> result;
		InOrder(root, result);
		int L = 0;
		int R = result.size() - 1;
		while (result[L]->val < result[L + 1]->val)L++;
		while (result[R]->val > result[R - 1]->val)R--;
		swap(result[L]->val, result[R]->val);
	}

	void InOrder(TreeNode* root, vector<TreeNode*>& result)
	{
		stack<TreeNode*> st;
		TreeNode* pCur = root;
		while (!st.empty() || pCur)
		{
			if (pCur)
			{
				st.push(pCur);
				pCur = pCur->left;
			}
			else
			{
				pCur = st.top();
				st.pop();
				result.push_back(pCur);
				pCur = pCur->right;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution098 {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> seq;
		InOrder(root, seq);
		return is_sorted(seq.begin(), seq.end(), less_equal<int>());
	}

	void InOrder(TreeNode* root, vector<int>& seq)
	{
		TreeNode* pCur = root;
		stack<TreeNode*> st;
		while (!st.empty() || pCur)
		{
			if (pCur)
			{
				st.push(pCur);
				pCur = pCur->left;
			}
			else
			{
				seq.push_back(st.top()->val);
				pCur = st.top()->right;
				st.pop();
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution097 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size())
			return false;
		//create indicator
		vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		//initialization the first row and the first column
		match[0][0] = true;
		for (int l1 = 1; l1 <= s1.size(); ++l1) {
			char c1 = s1[l1 - 1];
			char c3 = s3[l1 - 1];
			if (c1 == c3) {
				match[l1][0] = true;
			}
			else
				break;
		}
		for (int l2 = 1; l2 <= s2.size(); ++l2) {
			char c2 = s2[l2 - 1];
			char c3 = s3[l2 - 1];
			if (c2 == c3) {
				match[0][l2] = true;
			}
			else
				break;
		}
		//work through the rest of matrix using the formula
		for (int l1 = 1; l1 <= s1.size(); ++l1) {
			char c1 = s1[l1 - 1];
			for (int l2 = 1; l2 <= s2.size(); ++l2) {
				char c2 = s2[l2 - 1];
				int l3 = l1 + l2;
				char c3 = s3[l3 - 1];
				if (c1 == c3) {
					match[l1][l2] = match[l1 - 1][l2] || match[l1][l2];
				}
				if (c2 == c3) {
					match[l1][l2] = match[l1][l2 - 1] || match[l1][l2];
				}
			}
		}
		//the last element is the result
		return match[s1.size()][s2.size()];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution096 {
public:
	int numTrees(int n) {
		vector<int> count(n + 1, 0);
		count[0] = 1;
		count[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				count[i] += count[j] * count[i - j - 1];
			}
		}
		return count[n];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution095 {
public:
	vector<TreeNode *> generateTrees(int n) {
		if (n == 0) return *generate(1, 0);
		return *generate(1, n);
	}
	vector<TreeNode *>* generate(int start, int end)
	{
		vector<TreeNode *> *subTree = new vector<TreeNode*>();
		if (start > end)
		{
			subTree->push_back(NULL);
			return subTree;
		}
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> *leftSubs = generate(start, i - 1);
			vector<TreeNode*> *rightSubs = generate(i + 1, end);
			for (int j = 0; j < leftSubs->size(); j++)
			{
				for (int k = 0; k < rightSubs->size(); k++)
				{
					TreeNode *node = new TreeNode(i);
					node->left = (*leftSubs)[j];
					node->right = (*rightSubs)[k];
					subTree->push_back(node);
				}
			}
		}
		return subTree;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution094 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		TreeNode* pCur = root;
		while (!st.empty() || pCur)
		{
			if (pCur)
			{
				st.push(pCur);
				pCur = pCur->left;
			}
			else
			{
				result.push_back(st.top()->val);
				pCur = st.top()->right;
				st.pop();
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution093 {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.size();
		vector<string> result;
		if (len >= 4)
		{
			GetIP(result, s, "", 0, 0);
		}
		for (size_t i = 0; i < result.size(); i++)
		{
			result[i].pop_back();
		}
		return result;
	}

	void GetIP(vector<string>& result, string& s, string curIP, int cnt, int index)
	{
		if (cnt == 4)
		{
			if (index == s.size())
			{
				result.push_back(curIP);
			}
		}
		else
		{
			for (int i = 1; i <= 3; i++)
			{
				if (index + i <= s.size())
				{
					string ip = s.substr(index, i);
					if (IsValidNum(ip))
					{
						GetIP(result, s, curIP + ip + ".", cnt + 1, index + i);
					}
				}
			}
		}
	}

	bool IsValidNum(string s)
	{
		if (s[0] == '0')
		{
			return s.size() == 1;
		}
		else
		{
			int num = stoi(s);
			if (num >= 1 && num <= 255)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution092 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		int dist = n - m + 1;
		ListNode* pCur = newHead;
		ListNode* pPre = newHead;
		while (m--)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		ListNode* pCurPre = pPre->next;
		pPre->next = NULL;
		ListNode* pNext = NULL;

		while (dist--)
		{
			pNext = pCur->next;
			pCur->next = pPre->next;
			pPre->next = pCur;
			pCur = pNext;
		}
		if (pCurPre)
		{
			pCurPre->next = pNext;
		}
		return newHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution091 {
public:
	int numDecodings(string s) {
		int len = s.size();
		if (len == 0)
		{
			return 0;
		}
		vector<int> dp(len + 1, 0);
		dp[0] = 1;
		if (CheckOne(s, 0))
		{
			dp[1] = 1;
		}
		if (len == 1)
		{
			return dp[1];
		}
		for (size_t i = 2; i <= len; i++)
		{
			if (CheckOne(s, i - 1))
			{
				if (CheckTwo(s, i - 1))
				{
					dp[i] = dp[i - 1] + dp[i - 2];
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
			else
			{
				if (CheckTwo(s, i - 1))
				{
					dp[i] = dp[i - 2];
				}
				else
				{
					dp[i] = 0;
				}
			}
		}
		return dp[len];
	}

	bool CheckOne(string& s, int index)
	{
		if (s[index] >= '1'&&s[index] <= '9')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CheckTwo(string& s, int index)
	{
		if (s[index - 1] == '1')
		{
			return s[index] >= '0'&&s[index] <= '9';
		}
		if (s[index - 1] == '2')
		{
			return s[index] >= '0'&&s[index] <= '6';
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution090 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> result;
		vector<int> vec;
		if (len > 0)
		{
			sort(nums.begin(), nums.end());
			GetSubsets(result, vec, nums, -1);
		}
		return result;
	}

	void GetSubsets(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums, int index)
	{
		if (vec.size() <= nums.size())
		{
			result.push_back(vec);
		}
		if (vec.size() < nums.size())
		{
			for (int i = index + 1; i < nums.size(); i++)
			{
				vec.push_back(nums[i]);
				GetSubsets(result, vec, nums, i);
				while (i + 1 < nums.size() && nums[i] == nums[i + 1])i++;
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution089 {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		result.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int highestBit = 1 << i;
			int len = result.size();
			for (int j = len - 1; j >= 0; j--)
			{
				result.push_back(highestBit + result[j]);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution088 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n - 1;
		int i = m - 1, j = n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] > nums2[j])
			{
				nums1[k--] = nums1[i--];
			}
			else
			{
				nums1[k--] = nums2[j--];
			}
		}
		while (i >= 0)
		{
			nums1[k--] = nums1[i--];
		}
		while (j >= 0)
		{
			nums1[k--] = nums2[j--];
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution086 {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* pLessHead = new ListNode(0);
		ListNode* pGreaterHead = new ListNode(0);
		ListNode* pLess = pLessHead;
		ListNode* pGreater = pGreaterHead;
		ListNode* pCur = head;
		while (pCur)
		{
			if (pCur->val < x)
			{
				pLess->next = pCur;
				pLess = pLess->next;
			}
			else
			{
				pGreater->next = pCur;
				pGreater = pGreater->next;
			}
			pCur = pCur->next;
		}
		if (!pLessHead->next)
		{
			return pGreaterHead->next;
		}
		pLess->next = pGreaterHead->next;
		pGreater->next = NULL;
		return pLessHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution083 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* fakeNode = new ListNode(0);
		int lastDigit = INT_MAX;
		int dup = 0;
		ListNode* pCur = head;
		ListNode* pPre = fakeNode;
		ListNode* pNewCur = fakeNode;
		while (pCur)
		{
			if (pCur->val == lastDigit)
			{
				dup++;
			}
			else
			{
				if (dup == 1)
				{
					pPre->next = NULL;
					pNewCur->next = pPre;
					pNewCur = pNewCur->next;
				}
				dup = 1;
				lastDigit = pCur->val;
			}
			pPre = pCur;
			pCur = pCur->next;
		}
		if (dup == 1)
		{
			pPre->next = NULL;
			pNewCur->next = pPre;
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution082 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		int lastDigit = INT_MAX;
		ListNode* pCur = fakeNode;
		while (pCur->next)
		{
			if (lastDigit == pCur->next->val)
			{
				pCur->next = pCur->next->next;
			}
			else
			{
				pCur = pCur->next;
				lastDigit = pCur->val;
			}
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution081 {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		int L = 0;
		int R = len - 1;
		while (L <= R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] == target)
			{
				return true;
			}
			if (nums[M] > nums[L])
			{
				if (target >= nums[L] && target < nums[M])
				{
					R = M - 1;
				}
				else
				{
					L = M + 1;
				}
			}
			else if (nums[M] < nums[L])
			{
				if (target > nums[M] && target <= nums[R])
				{
					L = M + 1;
				}
				else
				{
					R = M - 1;
				}
			}
			else
			{
				L++;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution080 {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int dpCnt = 0;
		int dup = 0;
		int lastDigit = INT_MAX;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == lastDigit)
			{
				dpCnt++;
				if (dpCnt > 2)
				{
					dup++;
				}
			}
			else
			{
				dpCnt = 1;
				lastDigit = nums[i];
			}
			nums[i - dup] = nums[i];
		}
		return len - dup;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution079 {
public:
	bool exist(vector<vector<char> > &board, string word) {
		int M = board.size();
		if (M == 0)
		{
			return false;
		}
		int N = board[0].size();
		if (N == 0)
		{
			return false;
		}
		if (word.size() == 0)
		{
			return false;
		}
		vector<vector<bool> > isVisited(M, vector<bool>(N, false));
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (DFS(board, word, isVisited, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool DFS(vector<vector<char> > &board, string &word, vector<vector<bool> > &isVisited, int i, int j, int index)
	{
		int M = board.size();
		int N = board[0].size();
		isVisited[i][j] = true;
		bool equal = word[index] == board[i][j];
		if (!equal)
		{
			isVisited[i][j] = false;
			return false;
		}
		if (index == word.size() - 1 && equal)
		{
			return true;
		}
		if (i - 1 >= 0 && !isVisited[i - 1][j])
		{
			if (DFS(board, word, isVisited, i - 1, j, index + 1))
			{
				return true;
			}
		}
		if (j - 1 >= 0 && !isVisited[i][j - 1])
		{
			if (DFS(board, word, isVisited, i, j - 1, index + 1))
			{
				return true;
			}
		}
		if (i + 1 < M && !isVisited[i + 1][j])
		{
			if (DFS(board, word, isVisited, i + 1, j, index + 1))
			{
				return true;
			}
		}
		if (j + 1 < N && !isVisited[i][j + 1])
		{
			if (DFS(board, word, isVisited, i, j + 1, index + 1))
			{
				return true;
			}
		}
		isVisited[i][j] = false;
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution078 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> result;
		vector<int> vec;
		if (len > 0)
		{
			sort(nums.begin(), nums.end());
			GetSubsets(result, vec, nums, -1);
		}
		return result;
	}

	void GetSubsets(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums, int index)
	{
		if (vec.size() <= nums.size())
		{
			result.push_back(vec);
		}
		if (vec.size() < nums.size())
		{
			for (int i = index + 1; i < nums.size(); i++)
			{
				vec.push_back(nums[i]);
				GetSubsets(result, vec, nums, i);
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution077 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (n > 0 && k > 0 && n >= k)
		{
			vector<int> vec;
			GetComb(result, vec, n, k, 0);
		}
		return result;
	}

	void GetComb(vector<vector<int>>& result, vector<int> &vec, int n, int k, int index)
	{
		if (vec.size() == k)
		{
			result.push_back(vec);
		}
		else
		{
			for (int i = index + 1; i <= n; i++)
			{
				vec.push_back(i);
				GetComb(result, vec, n, k, i);
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution075 {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int L = 0;
		int R = len - 1;
		int index = 0;
		while (index < R + 1)
		{
			if (nums[index] == 0)
			{
				swap(nums[L], nums[index]);
				index++;
				L++;
			}
			else if (nums[index] == 2)
			{
				swap(nums[R], nums[index]);
				R--;
			}
			else
			{
				index++;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution073 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int M = matrix.size();
		int N = 0;
		if (M)
		{
			N = matrix[0].size();
		}
		if (!M || !N)
		{
			return false;
		}
		int L = 0;
		int R = M*N - 1;
		while (L <= R)
		{
			int mid = L + ((R - L) >> 1);
			if (target > matrix[mid / N][mid%N])
			{
				L = mid + 1;
			}
			else if (target < matrix[mid / N][mid%N])
			{
				R = mid - 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution072 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int M = matrix.size();
		int N = 0;
		if (M)
		{
			N = matrix[0].size();
		}
		if (!M || !N)
		{
			return;
		}
		set<int> row;
		set<int> col;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (matrix[i][j] == 0)
				{
					row.insert(i);
					col.insert(j);
				}
			}
		}
		for (auto index : row)
		{
			matrix[index].assign(N, 0);
		}
		for (auto index : col)
		{
			for (size_t i = 0; i < M; i++)
			{
				matrix[i][index] = 0;
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution071 {
public:
	string simplifyPath(string path) {
		vector<string> pathes;
		string seg = "";
		for (int i = 0; i <= path.size(); ++i) {
			if (i == path.size() || path[i] == '/') {
				if (seg == "..") {
					if (pathes.size() > 0) {
						pathes.pop_back();
					}
				}
				else if (seg == ".") {
				}
				else if (seg.size() > 0) {
					pathes.push_back(seg);
				}
				seg = "";
			}
			else {
				seg += path[i];
			}
		}
		string ret = "/";
		for (int i = 0; i < pathes.size(); ++i) {
			if (i > 0) ret += "/";
			ret += pathes[i];
		}
		return ret;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution070 {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2)
		{
			return n;
		}
		int f1 = 1;
		int f2 = 2;
		int f3;
		for (size_t i = 3; i <= n; i++)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution069 {
public:
	int mySqrt(int x) {
		int L = 0;
		int R = (x >> 1) + 1;
		while (L <= R)
		{
			long long M = L + ((R - L) >> 1);
			long long val = M*M;
			if (val < x)
			{
				L = M + 1;
			}
			else if (val > x)
			{
				R = M - 1;
			}
			else
			{
				return M;
			}
		}
		return R;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution067 {
public:
	string addBinary(string a, string b) {
		int lenA = a.size();
		int lenB = b.size();
		if (lenA < lenB)
		{
			return addBinary(b, a);
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string res;
		int carry = 0;
		for (size_t i = 0; i < lenB; i++)
		{
			int tmp = (a[i] - '0') + (b[i] - '0') + carry;
			res += ((tmp % 2) + '0');
			carry = tmp / 2;
		}
		for (size_t i = lenB; i < lenA; i++)
		{
			int tmp = (a[i] - '0') + carry;
			res += ((tmp % 2) + '0');
			carry = tmp / 2;
		}
		if (carry)
		{
			res += (carry + '0');
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution066 {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result;
		int len = digits.size();
		int carry = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			int tmp = digits[i] + carry;
			result.push_back(tmp % 10);
			carry = tmp / 10;
		}
		if (carry)
		{
			result.push_back(carry);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution065 {
public:
	bool isNumber(string s) {
		int index = 0;
		int len = s.size();
		while (index < len&&isspace(s[index]))
		{
			index++;
		}
		if (s[index] == '+' || s[index] == '-')
		{
			index++;
		}
		bool isNum = false;
		while (index < len&&isdigit(s[index]))
		{
			index++;
			isNum = true;
		}
		if (index < len&&s[index] == '.')
		{
			index++;
			while (index < len&&isdigit(s[index]))
			{
				index++;
				isNum = true;
			}
		}
		if (isNum&&index < len&& tolower(s[index]) == 'e')
		{
			index++;
			if (index < len && (s[index] == '+' || s[index] == '-'))
			{
				index++;
			}
			isNum = false;
			while (index < len&&isdigit(s[index]))
			{
				index++;
				isNum = true;
			}
		}
		while (index < len&&isspace(s[index]))
		{
			index++;
		}
		return isNum&&index == len;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution064 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int M = grid.size();
		int N = 0;
		if (M)
		{
			N = grid[0].size();
		}
		if (!M || !N)
		{
			return 0;
		}
		vector<vector<int>> sum(M, vector<int>(N, 0));
		sum[0][0] = grid[0][0];
		for (size_t i = 1; i < M; i++)
		{
			sum[i][0] = sum[i - 1][0] + grid[i][0];
		}
		for (size_t i = 1; i < N; i++)
		{
			sum[0][i] = sum[0][i - 1] + grid[0][i];
		}
		for (size_t i = 1; i < M; i++)
		{
			for (size_t j = 1; j < N; j++)
			{
				sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
			}
		}
		return sum[M - 1][N - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution063 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int M = obstacleGrid.size();
		int N = 0;
		if (M)
		{
			N = obstacleGrid[0].size();
		}
		if (!M || !N)
		{
			return 0;
		}
		vector<vector<int>> paths(M, vector<int>(N, 0));
		paths[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (size_t i = 1; i < M; i++)
		{
			paths[i][0] = obstacleGrid[i][0] == 1 ? 0 : paths[i - 1][0];
		}
		for (size_t i = 1; i < N; i++)
		{
			paths[0][i] = obstacleGrid[0][i] == 1 ? 0 : paths[0][i - 1];
		}
		for (size_t i = 1; i < M; i++)
		{
			for (size_t j = 1; j < N; j++)
			{
				paths[i][j] = obstacleGrid[i][j] == 1 ? 0 : paths[i - 1][j] + paths[i][j - 1];
			}
		}
		return paths[M - 1][N - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution062 {
public:
	int uniquePaths(int m, int n) {
		if (m > 0 && n > 0)
		{
			vector<vector<int>> paths(m, vector<int>(n, 0));
			for (size_t i = 0; i < m; i++)
			{
				paths[i][0] = 1;
			}
			for (size_t i = 0; i < n; i++)
			{
				paths[0][i] = 1;
			}
			for (size_t i = 1; i < m; i++)
			{
				for (size_t j = 1; j < n; j++)
				{
					paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
				}
			}
			return paths[m - 1][n - 1];
		}
		else
		{
			return 0;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution061 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
		{
			return head;
		}
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		ListNode* pA = fakeNode;
		ListNode* pB = fakeNode;
		int len = 0;
		ListNode* pCur = head;
		while (pCur)
		{
			len++;
			pCur = pCur->next;
		}
		k %= len;
		while (k--)
		{
			pA = pA->next;
		}
		while (pA->next)
		{
			pA = pA->next;
			pB = pB->next;
		}
		pA->next = fakeNode->next;
		fakeNode->next = pB->next;
		pB->next = NULL;
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution060 {
public:
	string getPermutation(int n, int k) {
		int i, j, data[10], sign[10];
		data[1] = 1;
		for (i = 2; i <= n; ++i)data[i] = data[i - 1] * i;
		memset(sign, 0, sizeof(sign));
		string s = "";
		i -= 2;
		--k;
		while (i >= 0)
		{
			int temp = k / data[i];
			for (j = 1; j < 10; ++j)
			{
				if (sign[j] == 0)temp--;
				if (temp < 0)break;
			}
			sign[j] = 1;
			s += j + '0';
			k %= data[i];
			i--;
		}
		return s;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution059 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		if (n > 0)
		{
			int row = 0, col = -1;
			int M = n, N = n;
			int index = 1;
			while (true)
			{
				for (size_t i = 0; i < N; i++)
				{
					result[row][++col] = index++;
				}
				if (--M == 0)break;
				for (size_t i = 0; i < M; i++)
				{
					result[++row][col] = index++;
				}
				if (--N == 0)break;
				for (size_t i = 0; i < N; i++)
				{
					result[row][--col] = index++;
				}
				if (--M == 0)break;
				for (size_t i = 0; i < M; i++)
				{
					result[--row][col] = index++;
				}
				if (--N == 0)break;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution058 {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int index = len - 1;
		while (index >= 0)
		{
			if (isspace(s[index]))
			{
				index--;
			}
			else
			{
				break;
			}
		}
		int count = 0;
		while (index >= 0)
		{

			if (isalnum(s[index]))
			{
				index--;
				count++;
			}
			else
			{
				break;
			}
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution056 {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		int len = intervals.size();
		if (len > 0)
		{
			sort(intervals.begin(), intervals.end(), CompareInterval);
			int index = 0;
			while (index < len)
			{
				if (index + 1 < len)
				{
					while (index + 1 < len && intervals[index].end >= intervals[index + 1].start)
					{
						intervals[index + 1].start = intervals[index].start;
						intervals[index + 1].end = max(intervals[index + 1].end, intervals[index].end);
						index++;
					}
				}
				result.push_back(intervals[index]);
				index++;
			}
		}
		return result;
	}


	static bool CompareInterval(Interval I1, Interval I2)
	{
		return I1.start < I2.start;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution055 {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		int last = 0;
		last = max(0, nums[0]);
		for (size_t i = 1; i < len; i++)
		{
			if (last <= 0)
			{
				return false;
			}
			last = max(last - 1, nums[i]);
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution054 {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int M = matrix.size();
		int N;
		if (M)
		{
			N = matrix[0].size();
		}
		else
		{
			return result;
		}
		int row = 0;
		int col = -1;
		while (true)
		{
			for (size_t i = 0; i < N; i++)
			{
				result.push_back(matrix[row][++col]);
			}
			if (--M == 0)break;
			for (size_t i = 0; i < M; i++)
			{
				result.push_back(matrix[++row][col]);
			}
			if (--N == 0)break;
			for (size_t i = 0; i < N; i++)
			{
				result.push_back(matrix[row][--col]);
			}
			if (--M == 0)break;
			for (size_t i = 0; i < M; i++)
			{
				result.push_back(matrix[--row][col]);
			}
			if (--N == 0)break;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution053 {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		int maxSum = nums[0];
		int curSum = nums[0];
		for (size_t i = 1; i < len; i++)
		{
			curSum = max(nums[i], curSum + nums[i]);
			maxSum = max(maxSum, curSum);
		}
		return maxSum;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution050 {
public:
	double myPow(double x, int n) {
		if (n < 0)
		{
			return 1 / POW(x, -n);
		}
		return POW(x, n);
	}

	double POW(double x, int n)
	{
		if (x == 0 || x == 1)
		{
			return x;
		}
		if (n == 0)
		{
			return 1;
		}
		double p = POW(x, n / 2);
		if (n % 2 == 0)
		{
			return p*p;
		}
		else
		{
			return p*p*x;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution049 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string> > result;
		unordered_map<string, vector<string>> mp;
		for (size_t i = 0; i < strs.size(); i++)
		{
			string sortedStr = strs[i];
			sort(sortedStr.begin(), sortedStr.end());
			mp[sortedStr].push_back(strs[i]);
		}
		for (auto m : mp)
		{
			sort(m.second.begin(), m.second.end());
			result.push_back(m.second);
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution048 {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();
		if (N > 1)
		{
			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = i + 1; j < N; j++)
				{
					swap(matrix[i][j], matrix[j][i]);
				}
			}
			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < N / 2; j++)
				{
					swap(matrix[i][j], matrix[i][N - j - 1]);
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution047 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> vec;
		int len = nums.size();
		vector<bool> isVisited(len, false);
		if (len > 0)
		{
			sort(nums.begin(), nums.end());
			GetPert(result, nums, vec, isVisited);
		}
		return result;
	}
	void GetPert(vector<vector<int>>& result, vector<int>& nums, vector<int>& vec, vector<bool>& isVisited)
	{
		if (vec.size() == nums.size())
		{
			result.push_back(vec);
		}
		else
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (!isVisited[i])
				{
					isVisited[i] = true;
					vec.push_back(nums[i]);
					GetPert(result, nums, vec, isVisited);
					isVisited[i] = false;
					while (i + 1 < nums.size() && nums[i] == nums[i + 1])i++;
				}
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution046 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> vec;
		int len = nums.size();
		vector<bool> isVisited(len, false);
		if (len > 0)
		{
			GetPert(result, nums, vec, isVisited);
		}
		return result;
	}
	void GetPert(vector<vector<int>>& result, vector<int>& nums, vector<int>& vec, vector<bool>& isVisited)
	{
		if (vec.size() == nums.size())
		{
			result.push_back(vec);
		}
		else
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (!isVisited[i])
				{
					isVisited[i] = true;
					vec.push_back(nums[i]);
					GetPert(result, nums, vec, isVisited);
					isVisited[i] = false;
				}
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution042 {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		if (len1 == 0 || len2 == 0 || num1 == "0" || num2 == "0")
		{
			return "0";
		}
		if (len1 > len2)
		{
			return multiply(num2, num1);
		}
		vector<int> res(len1 + len2, 0);
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				res[i + j] += (num1[i] - '0')*(num2[j] - '0');
			}
		}
		string resStr;
		int carry = 0;
		for (int i = len1 + len2 - 2; i >= 0; i--)
		{
			resStr += ((res[i] + carry) % 10 + '0');
			carry = (res[i] + carry) / 10;
		}
		if (carry != 0)
		{
			resStr += ((carry) % 10 + '0');
		}
		reverse(resStr.begin(), resStr.end());
		return resStr;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution041 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i = 0;
		int len = nums.size();
		while (i < len)
		{
			if (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= len &&nums[i] != nums[nums[i] - 1])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
			else
			{
				i++;
			}
		}
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		return len + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution040 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> vec;
		if (candidates.size() > 0)
		{
			sort(candidates.begin(), candidates.end());
			GetComb(result, candidates, vec, 0, target, -1);
		}
		return result;
	}

	void GetComb(vector<vector<int>>& result, vector<int>& candidates, vector<int>& vec, int sum, int target, int index)
	{
		if (sum == target)
		{
			result.push_back(vec);
		}
		else if (sum < target)
		{
			for (int i = index + 1; i < candidates.size(); i++)
			{
				vec.push_back(candidates[i]);
				GetComb(result, candidates, vec, sum + candidates[i], target, i);
				while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])i++;
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution039 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> vec;
		if (candidates.size() > 0)
		{
			sort(candidates.begin(), candidates.end());
			GetComb(result, candidates, vec, 0, target, 0);
		}
		return result;
	}

	void GetComb(vector<vector<int>>& result, vector<int>& candidates, vector<int>& vec, int sum, int target, int index)
	{
		if (sum == target)
		{
			result.push_back(vec);
		}
		else if (sum < target)
		{
			for (int i = index; i < candidates.size(); i++)
			{
				vec.push_back(candidates[i]);
				GetComb(result, candidates, vec, sum + candidates[i], target, i);
				while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])i++;
			}
		}
		if (vec.size() > 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution038 {
public:
	string countAndSay(int n) {
		string str = "1";
		int cnt = 0;
		char lastCh = '1';
		for (size_t i = 1; i < n; i++)
		{
			string tmp;
			for (size_t i = 0; i <= str.size(); i++)
			{
				if (str[i] != lastCh || i == str.size())
				{
					tmp += (to_string(cnt) + lastCh);
					lastCh = str[i];
					cnt = 1;
				}
				else
				{
					cnt++;
				}
			}
			str = tmp;
			cnt = 0;
			lastCh = str[0];
		}
		return str;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution036 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		return CheckRow(board) && CheckCol(board) && CheckBoard(board);
	}

	bool CheckRow(vector<vector<char>>& board)
	{
		for (size_t i = 0; i < 9; i++)
		{
			vector<int> cnt(9, 0);
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				else
				{
					cnt[board[i][j] - '0' - 1]++;
				}
			}
			for (size_t j = 0; j < 9; j++)
			{
				if (cnt[j] > 1)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool CheckCol(vector<vector<char>>& board)
	{
		for (size_t i = 0; i < 9; i++)
		{
			vector<int> cnt(9, 0);
			for (size_t j = 0; j < 9; j++)
			{
				if (board[j][i] == '.')
				{
					continue;
				}
				else
				{
					cnt[board[j][i] - '0' - 1]++;
				}
			}
			for (size_t j = 0; j < 9; j++)
			{
				if (cnt[j] > 1)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool CheckBoard(vector<vector<char>>& board)
	{
		for (size_t i = 0; i < 9; i += 3)
		{
			for (size_t j = 0; j < 9; j += 3)
			{
				vector<int> cnt(9, 0);
				for (int m = 0; m < 3; m++)
				{
					for (int n = 0; n < 3; n++)
					{
						if (board[i + m][j + n] == '.')
						{
							continue;
						}
						else
						{
							cnt[board[i + m][j + n] - '0' - 1]++;
						}
					}
				}
				for (size_t j = 0; j < 9; j++)
				{
					if (cnt[j] > 1)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution035 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		int L = 0;
		int R = len - 1;
		if (target > nums[R])
		{
			return len;
		}
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
		return L;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution034 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//vector<int> result;
		//result.push_back(FindFirst(nums, target));
		//result.push_back(FindLast(nums, target));
		//return result;

		vector<int> result;
		auto par = equal_range(nums.begin(), nums.end(), target);
		if (par.first != par.second)
		{
			result.push_back(par.first - nums.begin());
			result.push_back(par.second - nums.begin() - 1);
		}
		else
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		return result;
	}

	int FindFirst(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = left + ((right - left) >> 1);
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return nums[left] == target ? left : -1;
	}

	int FindLast(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = left + ((right - left + 1) >> 1);
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid;
			}
		}
		return nums[right] == target ? right : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution033 {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int L = 0;
		int R = len - 1;
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] == target)
			{
				return M;
			}
			if (nums[M] >= nums[L])
			{
				if (target >= nums[L] && target < nums[M])
				{
					R = M - 1;
				}
				else
				{
					L = M + 1;
				}
			}
			else
			{
				if (target > nums[M] && target <= nums[R])
				{
					L = M + 1;
				}
				else
				{
					R = M - 1;
				}
			}
		}
		return nums[L] == target ? L : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution032 {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		stack<int> st;
		int index = -1;
		int maxLen = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				if (!st.empty())
				{
					st.pop();
					if (st.empty())
					{
						maxLen = max(maxLen, i - index);
					}
					else
					{
						maxLen = max(maxLen, i - st.top());
					}
				}
				else
				{
					index = i;
				}
			}
		}
		return maxLen;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution031 {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		for (int i = len - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				for (int j = len - 1; j > i; j--)
				{
					if (nums[i] < nums[j])
					{
						swap(nums[i], nums[j]);
						sort(nums.begin() + i + 1, nums.end());
						return;
					}
				}
			}
		}
		reverse(nums.begin(), nums.end());
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
		if (nLen > hLen)
		{
			return -1;
		}
		if (nLen == 0)
		{
			return 0;
		}
		int i = 0, j = 0;
		vector<int> nextArray(nLen, -1);
		GetNextArray(nextArray, needle);
		while (i < hLen&&j < nLen)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = nextArray[j];
			}
		}
		return j == nLen ? i - j : -1;
	}
	void GetNextArray(vector<int>& nextArray, string needle)
	{
		int nLen = needle.size();
		int j = 0, k = -1;
		while (j < nLen - 1)
		{
			if (k == -1 || needle[k] == needle[j])
			{
				k++;
				j++;
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
		int dup = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == val)
			{
				dup++;
			}
			else
			{
				nums[i - dup] = nums[i];
			}
		}
		return len - dup;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution026 {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int dup = 0;
		int lastNum = INT_MAX;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == lastNum)
			{
				dup++;
			}
			else
			{
				nums[i - dup] = nums[i];
				lastNum = nums[i];
			}
		}
		return len - dup;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution024 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;
		ListNode* pCur = head;
		ListNode* pPre = fakeNode;
		while (pCur&&pCur->next)
		{
			ListNode* pNext = pCur->next->next;
			pPre->next = pCur->next;
			pCur->next->next = pCur;
			pCur->next = pNext;
			pPre = pCur;
			pCur = pCur->next;
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution022 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0)
		{
			GenParent(result, 0, 0, n, "");
		}
		return result;
	}

	void GenParent(vector<string>& result, int leftNum, int rightNum, int totalNum, string pare)
	{
		if (pare.size() == 2 * totalNum)
		{
			result.push_back(pare);
			return;
		}
		if (leftNum < totalNum)
		{
			GenParent(result, leftNum + 1, rightNum, totalNum, pare + "(");
		}
		if (leftNum > rightNum)
		{
			GenParent(result, leftNum, rightNum + 1, totalNum, pare + ")");
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution021 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)
		{
			return l2;
		}
		if (!l2)
		{
			return l1;
		}
		ListNode* fakeNode = new ListNode(0);
		ListNode* pCur = fakeNode;
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
			pCur = pCur->next;
		}
		if (l1)
		{
			pCur->next = l1;
		}
		if (l2)
		{
			pCur->next = l2;
		}
		return fakeNode->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution020 {
public:
	bool isValid(string s) {
		unordered_map<char, char> chMap{ { '(', ')' }, { '[', ']' }, { '{', '}' } };
		stack<char> st;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (chMap.find(s[i]) == chMap.end())
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
				if (i > 0 && nums[i] == nums[i - 1])continue;
				for (int j = i + 1; j < len - 2; j++)
				{
					if (j > i + 1 && nums[j] == nums[j - 1])continue;
					for (int k = j + 1; k < len - 1; k++)
					{
						if (k > j + 1 && nums[k] == nums[k - 1])continue;
						int searchTarget = target - nums[i] - nums[j] - nums[k];
						if (searchTarget < nums[k + 1])continue;
						int m = BinarySearch(nums, k + 1, len - 1, searchTarget);
						if (m != -1)
						{
							result.push_back(vector < int > {nums[i], nums[j], nums[k], nums[m]});
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
		if (len > 2)
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
			if (i > 0 && cur > pre)
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
