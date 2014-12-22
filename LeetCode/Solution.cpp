#include "stdafx.h"
#include "DataStructure.h"
/*-------------------------------------------------------------------------------------*/
/*Excel Sheet Column Title*/
class Solution19 {
public:
	string convertToTitle(int n) {
		string result;
		if (n>0)
		{
			while (n!=0)
			{
				result.push_back('A'+(n-1)%26);
				n = (n-1)/26;
			}
			reverse(result.begin(), result.end());
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Majority Element*/
class Solution18 {
public:
	int majorityElement(vector<int> &num) {
		map<int, int> mp;
		int length = num.size();
		int result=0;
		for (int i = 0; i < length; i++)
		{
			mp[num[i]]++;
		}
		int lenghtMP = mp.size();
		for (auto& m:mp)
		{
			if (m.second > length / 2)
			{
				result = m.first;
				break;

			}
		}
		return result;
	}
};
/*
vector<int> num = { 1 };
Solution18 SU18;
SU18.majorityElement(num);
*/
/*-------------------------------------------------------------------------------------*/
/*Regular Expression Matching*/
class Solution17 {
public:
	bool isMatch(const char *s, const char *p) {
		regex pattern(p);
		return regex_match(s, pattern);
	}
};
/*
Solution17 SU17;
bool result = SU17.isMatch("aa", "a");
result=SU17.isMatch("aa", "aa");
result=SU17.isMatch("aaa", "aa");
result=SU17.isMatch("aa", "a*");
result=SU17.isMatch("aa", ".*");
result=SU17.isMatch("ab", ".*");
result=SU17.isMatch("aab", "c*a*b");
*/
/*-------------------------------------------------------------------------------------*/
/*Unique Paths */
class Solution16 {
public:
	int uniquePaths(int m, int n) {
		int num = 0;
		if (m==1||n==1)
		{
			num = 1;
		}
		if (m>1&&n>1)
		{
			vector<vector<int> > vecResult;
			for (int i = 0; i < n; i++)
			{
				vecResult.push_back(vector<int>(m,1));
			}
			GetPaths(n, m, vecResult);
			num = vecResult[n-1][m - 1];
		}
		return num;
	}
	void GetPaths(int n, int m, vector<vector<int> >& vecResult)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				vecResult[i][j] = vecResult[i][j-1] + vecResult[i-1][j];
			}
		}
	}
};
/*
Solution16 SU16;
SU16.uniquePaths(3, 7);
*/
/*-------------------------------------------------------------------------------------*/
/*Pascal's Triangle*/
class Solution15 {
public:
	vector<vector<int> > result;
	vector<vector<int> > generate(int numRows) {
		if (numRows > 0)
		{
			if (numRows>=1)
			{
				result.push_back(vector<int>(1, 1));
			}
			if (numRows >= 2)
			{
				result.push_back(vector<int>(2, 1));
			}
			if (numRows >= 3)
			{
				for (int j = 3; j <= numRows; j++)
				{
					vector<int> tmp;
					tmp.push_back(1);
					vector<int> resultLast = result.back();
					int resultLastVecSize = resultLast.size();
					for (int i = 0; i < resultLastVecSize - 1; i++)
					{
						tmp.push_back(resultLast[i] + resultLast[i + 1]);
					}
					tmp.push_back(1);
					result.push_back(tmp);
				}
			}
		}
		return result;
	}
};
/*
Solution15 SU15;
SU15.generate(10);
*/
/*-------------------------------------------------------------------------------------*/
class Solution14 {
public:
	vector<vector<int> > result;
	vector<vector<int> > generateMatrix(int n) {
		if (n > 0)
		{
			for (size_t i = 0; i < n; i++)
			{
				result.push_back(vector<int>(n, 0));
			}
		}
		int index = 1;
		int indexIJ = 0;
		int lenght = n;
		while (index<=n*n)
		{
			Fill(indexIJ, lenght, index);
			lenght -= 2;
			indexIJ++;
		}
		return result;
	}

	void Fill(int indexIJ, int n, int &index)
	{
		if (n==1)
		{
			result[indexIJ][indexIJ] = index;
			index++;
			return;
		}
		for (int i = 0; i < n - 1; i++)
		{
			result[indexIJ][indexIJ + i] = index;
			index++;
		}
		for (int i = 0; i < n - 1; i++)
		{
			result[indexIJ + i][indexIJ + n - 1] = index;
			index++;
		}
		for (int i = 0; i < n - 1; i++)
		{
			result[indexIJ + n - 1][indexIJ + n - 1 - i] = index;
			index++;
		}
		for (int i = 0; i < n - 1; i++)
		{
			result[indexIJ + n - 1 - i][indexIJ] = index;
			index++;
		}
	}

};
/*	
Solution14 SU14;
SU14.generateMatrix(5);
*/
/*-------------------------------------------------------------------------------------*/
class Solution13 {
public:
	void sortColors(int A[], int n) {
		if (n != 0)
		{
			int colorArray[3] = { 0 };
			for (int i = 0; i < n; i++)
			{
				colorArray[A[i]]++;
			}
			int index = 0;
			for (int i = 0; i < 3; i++)
			{
				while (colorArray[i] != 0)
				{
					A[index] = i;
					index++;
					colorArray[i]--;
				}
			}
		}
	}
};
/*
int A[10] = { 0, 0, 0, 1, 0, 1, 1, 0, 2, 1 };
Solution13 SU13;
SU13.sortColors(A, 10);
*/
/*-------------------------------------------------------------------------------------*/
class Solution12 {
public:
	bool isBalanced(TreeNode *root) {
		if (root == NULL)
		{
			return true;
		}
		if (abs(Depth(root->left) - Depth(root->right)) > 1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int Depth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return 1 + max(Depth(root->left), Depth(root->right));
	}
};
/*
TreeNode* root = new TreeNode(1);
TreeNode* left = new TreeNode(2);
TreeNode* right = new TreeNode(2);
root->left = left;
left->left = right;
Solution12 SU;
SU.isBalanced(root);
*/
/*-------------------------------------------------------------------------------------*/
class Solution11 {
public:
	int max = INT_MIN;
	int maxPathSum(TreeNode *root) {
		if (root == NULL)
		{
			return 0;
		}
		GetMax(root);
		return max;
	}
	int GetMax(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int lMax = 0, rMax = 0;
		int value = root->val;
		if (root->left != NULL)
		{
			lMax = GetMax(root->left);
			if (lMax > 0)
			{
				value += lMax;
			}
		}
		if (root->right != NULL)
		{
			rMax = GetMax(root->right);
			if (rMax > 0)
			{
				value += rMax;
			}
		}
		if (value > max)
		{
			max = value;
		}
		return Max(root->val, Max(root->val + lMax, root->val + rMax));
	}

	int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};
/*
TreeNode* root = new TreeNode(1);
TreeNode* left = new TreeNode(2);
root->left = left;
root->right = NULL;
Solution11 SU;
SU.maxPathSum(root);
*/
/*-------------------------------------------------------------------------------------*/
class Solution10 {
public:
	bool search(int A[], int n, int target) {
		for (int i = 0; i < n; i++)
		{
			if (A[i] == target)
			{
				return true;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution9 {
public:
	int search(int A[], int n, int target) {
		for (int i = 0; i < n; i++)
		{
			if (A[i] == target)
			{
				return i;
			}
		}
		return -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution8 {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL)
		{
			return head;
		}
		ListNode* pCur = head;
		ListNode* pNewHead = NULL;
		ListNode* pNewCur = NULL;
		map<int, int> mpRep;
		while (pCur != NULL)
		{
			mpRep[pCur->val]++;
			pCur = pCur->next;
		}
		int flagFirst = true;
		pCur = head;
		while (pCur != NULL)
		{
			if (mpRep[pCur->val] == 1)
			{
				if (flagFirst)
				{
					pNewCur = pCur;
					pNewHead = pNewCur;
					flagFirst = false;
				}
				else
				{
					pNewCur->next = pCur;
					pNewCur = pNewCur->next;
				}
			}
			pCur = pCur->next;
		}
		if (pNewCur != NULL)
		{
			pNewCur->next = NULL;
		}
		return pNewHead;
	}
};
/*
ListNode* head=new	ListNode(0);
ListNode* tmp = head;
for (size_t i = 0; i < 5; i++)
{
ListNode* p = new ListNode(i);
tmp->next = p;
tmp = tmp->next;
}
Solution8 SU8;
SU8.deleteDuplicates(head);
*/
/*-------------------------------------------------------------------------------------*/
class Solution7 {
public:
	int reverse(int x) {
		long long sum = 0;
		while (x != 0)
		{
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		if (sum > INT_MAX || sum < INT_MIN)
		{
			sum = 0;
		}
		return sum;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution6 {
public:
	int firstMissingPositive(int A[], int n) {
		if (n == 0)
		{
			return 1;
		}
		if (n == 1)
		{
			if (A[0] == 1)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		int i = 0;
		while (i < n)
		{
			while ((A[i] - 1 != i) && (A[i] > 0) && (A[i] < n + 1) && (A[i] != A[A[i] - 1]))
			{
				swap(A[i], A[A[i] - 1]);
			}
			i++;
		}
		i = 0;
		while (i < n)
		{
			if (A[i] != i + 1)
			{
				return i + 1;
			}
			i++;
		}
		return i + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution5 {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > result;
		vector<int> solution;
		int sum = 0;
		std::sort(num.begin(), num.end());
		GetCombinations(num, sum, 0, target, solution, result);
		return result;
	}
	void GetCombinations(
		vector<int>& candidates,
		int& sum,
		int level,
		int target,
		vector<int>& solution,
		vector<vector<int> >& result)
	{
		if (sum > target) return;
		if (sum == target)
		{
			result.push_back(solution);
			return;
		}
		for (int i = level; i < candidates.size(); i++)
		{
			sum += candidates[i];
			solution.push_back(candidates[i]);
			GetCombinations(candidates, sum, i + 1, target, solution, result);
			solution.pop_back();
			sum -= candidates[i];
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution4 {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int strCount = strs.size();
		if (strCount == 1)
		{
			return strs[0];
		}
		int minSize = INT_MAX;
		for (size_t i = 0; i < strCount; i++)
		{
			int curSize = strs[i].size();
			if (curSize < minSize)
			{
				minSize = curSize;
			}
		}
		string strComm;
		int index = 0;
		while (index < minSize)
		{
			bool flag = false;
			for (int i = 1; i < strCount; i++)
			{
				if (strs[i][index] == strs[i - 1][index])
				{
					if (i == (strCount - 1))
					{
						strComm.push_back(strs[i][index]);
						index++;
						flag = true;
						break;
					}
					continue;
				}
				break;
			}
			if (flag == false)
			{
				break;
			}
		}
		return strComm;
	}
};
/*
vector<string> vecStr;
vecStr.push_back("ab");
vecStr.push_back("ab");
vecStr.push_back("abc");
vecStr.push_back("abcd");
Solution4 SU4;
SU4.longestCommonPrefix(vecStr);
*/
/*-------------------------------------------------------------------------------------*/
class Solution3 {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > result;
		if (root)
		{
			vector<int> tmp;
			queue<TreeNode*> qTN;
			int count = 0;
			stack<vector<int> > stResult;
			qTN.push(root);
			tmp.push_back(root->val);
			stResult.push(tmp);
			while (!qTN.empty())
			{
				tmp.clear();
				int count = stResult.top().size();
				for (size_t i = 0; i < count; i++)
				{
					TreeNode* tmpTN = qTN.front();
					qTN.pop();
					if (tmpTN->left != NULL)
					{
						tmp.push_back(tmpTN->left->val);
						qTN.push(tmpTN->left);
					}
					if (tmpTN->right != NULL)
					{
						tmp.push_back(tmpTN->right->val);
						qTN.push(tmpTN->right);
					}
				}
				if (tmp.size() != 0)
				{
					stResult.push(tmp);
				}
			}
			while (!stResult.empty())
			{
				result.push_back(stResult.top());
				stResult.pop();
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution2 {
public:
	stack<ListNode*> st;
	void reorderList(ListNode *head) {
		if (head)
		{
			int length = 0;
			ListNode* p = head;
			while (p != NULL)
			{
				p = p->next;
				length++;
			}
			int remain = (length % 2 == 0) ? (length / 2) : (length / 2 + 1);
			p = head;
			ListNode* q = head;
			while (remain != 0)
			{
				q = p;
				p = p->next;
				remain--;
			}
			q->next = NULL;
			while (p != NULL)
			{
				st.push(p);
				p = p->next;
			}
			q = head;
			ListNode* r = q;
			while (!st.empty())
			{
				r = q->next;
				st.top()->next = r;
				q->next = st.top();
				st.pop();
				q = r;
			}
		}
	}
};
/*
ListNode* head=new ListNode(0);
ListNode* r = head;
for (size_t i = 1; i <= 5; i++)
{
ListNode* p = new ListNode(i);
r->next = p;
r = p;
}
Solution2 SU2;
SU2.reorderList(head);
r = head;
while (r!=NULL)
{
cout << r->val << " ";
r = r->next;
}
*/

/*-------------------------------------------------------------------------------------*/

class Solution1 {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		int R = matrix.size();
		int C = matrix[0].size();
		set<int> vecR, vecC;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (matrix[i][j] == 0)
				{
					vecR.insert(i);
					vecC.insert(j);
				}
			}
		}
		for (auto &m : vecR)
		{
			for (int j = 0; j < C; j++)
			{
				matrix[m][j] = 0;
			}
		}
		for (auto &m : vecC)
		{
			for (int j = 0; j < R; j++)
			{
				matrix[j][m] = 0;
			}
		}
	}
};
/*
vector<vector<int>> matrix;
vector<int> tmp;
for (size_t i = 0; i < 3; i++)
{
matrix.push_back(tmp);
for (size_t j = 0; j < 5; j++)
{
matrix[i].push_back(1);
}
}
matrix[0][1] = 0;
matrix[2][1] = 0;
Solution1 S1;
S1.setZeroes(matrix);
*/

/*-------------------------------------------------------------------------------------*/
