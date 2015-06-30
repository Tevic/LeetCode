#include "stdafx.h"
#include "DataStructure.h"












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
			if (nums[i]==lastDigit)
			{
				dpCnt++;
				if (dpCnt>2)
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
		if (len>0)
		{
			sort(nums.begin(),nums.end());
			GetSubsets(result, vec, nums, -1);
		}
		return result;
	}

	void GetSubsets(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums,int index)
	{
		if (vec.size()<=nums.size())
		{
			result.push_back(vec);
		}
		if (vec.size()<nums.size())
		{
			for (int i = index + 1; i < nums.size(); i++)
			{
				vec.push_back(nums[i]);
				GetSubsets(result, vec, nums, i);
			}
		}
		if (vec.size()>0)
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
		if (n>0&&k>0&&n>=k)
		{
			vector<int> vec;
			GetComb(result, vec, n, k,0);
		}
		return result;
	}

	void GetComb(vector<vector<int>>& result, vector<int> &vec,int n,int k,int index)
	{
		if (vec.size()==k)
		{
			result.push_back(vec);
		}
		else
		{
			for (int i = index+1; i <= n; i++)
			{
				vec.push_back(i);
				GetComb(result, vec, n, k,i);
			}
		}
		if (vec.size()>0)
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
		while (index<R+1)
		{
			if (nums[index]==0)
			{
				swap(nums[L],nums[index]);
				index++;
				L++;
			}
			else if (nums[index]==2)
			{
				swap(nums[R],nums[index]);
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
		while (L<=R)
		{
			int mid = L + ((R - L) >> 1);
			if (target>matrix[mid/N][mid%N])
			{
				L = mid + 1;
			}
			else if (target<matrix[mid / N][mid%N])
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
				if (matrix[i][j]==0)
				{
					row.insert(i);
					col.insert(j);
				}
			}
		}
		for (auto index:row)
		{
			matrix[index].assign(N,0);
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
			if (i>0) ret += "/";
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
		while (L<=R)
		{
			long long M = L + ((R - L) >> 1);
			long long val = M*M;
			if (val<x)
			{
				L = M + 1;
			}
			else if (val>x)
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
		if (lenA<lenB)
		{
			return addBinary(b,a);
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
		reverse(res.begin(),res.end());
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
		for (int i = len-1; i >=0 ; i--)
		{
			int tmp = digits[i] + carry;
			result.push_back(tmp%10);
			carry = tmp / 10;
		}
		if (carry)
		{
			result.push_back(carry);
		}
		reverse(result.begin(),result.end());
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
		if (s[index] == '+' || s[index]=='-')
		{
			index++;
		}
		bool isNum = false;
		while (index<len&&isdigit(s[index]))
		{
			index++;
			isNum = true;
		}
		if (index<len&&s[index]=='.')
		{
			index++;
			while (index<len&&isdigit(s[index]))
			{
				index++;
				isNum = true;
			}
		}
		if (isNum&&index<len&& tolower(s[index]) == 'e')
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
			sum[i][0] = sum[i - 1][0]+grid[i][0];
		}
		for (size_t i = 1; i < N; i++)
		{
			sum[0][i] = sum[0][i-1] + grid[0][i];
		}
		for (size_t i = 1; i < M; i++)
		{
			for (size_t j = 1; j < N; j++)
			{
				sum[i][j] = min(sum[i - 1][j] , sum[i][j - 1])+grid[i][j];
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
		paths[0][0]=obstacleGrid[0][0] == 1 ? 0 : 1;
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
		return paths[M-1][N-1];
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution062 {
public:
	int uniquePaths(int m, int n) {
		if (m>0 && n>0)
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
	vector<string> anagrams(vector<string>& strs) {
		vector<string> result;
		unordered_map<string, vector<int>> mp;
		for (size_t i = 0; i < strs.size(); i++)
		{
			string sortedStr = strs[i];
			sort(sortedStr.begin(), sortedStr.end());
			mp[sortedStr].push_back(i);
		}
		for (auto m : mp)
		{
			if (m.second.size() > 1)
			{
				for (size_t i = 0; i < m.second.size(); i++)
				{
					result.push_back(strs[m.second[i]]);
				}
			}
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
		if (vec.size()>0)
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
		if (candidates.size()>0)
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
				if (cnt[j]>1)
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
				if (cnt[j]>1)
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
					if (cnt[j]>1)
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
		vector<int> result;
		result.push_back(FindFirst(nums, target));
		result.push_back(FindLast(nums, target));
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
				if (target >= nums[L] && target<nums[M])
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
				if (target>nums[M] && target <= nums[R])
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
					if (j>i + 1 && nums[j] == nums[j - 1])continue;
					for (int k = j + 1; k < len - 1; k++)
					{
						if (k>j + 1 && nums[k] == nums[k - 1])continue;
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
