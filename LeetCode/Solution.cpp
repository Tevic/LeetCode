#include "stdafx.h"
#include "DataStructure.h"

/*-------------------------------------------------------------------------------------*/
class Solution12 {
public:
	bool isBalanced(TreeNode *root) {
		if (root==NULL)
		{
			return true;
		}
		if (abs(Depth(root->left)-Depth(root->right))>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int Depth(TreeNode* root)
	{
		if (root==NULL)
		{
			return 0;
		}
		return 1 + max(Depth(root->left), Depth(root->right));
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution11 {
public:
	int max=INT_MIN;
	int maxPathSum(TreeNode *root) {
		if (root==NULL)
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
		int lMax=0, rMax = 0;
		int value = root->val;
		if (root->left!=NULL)
		{
			lMax=GetMax(root->left);
			if (lMax>0)
			{
				value += lMax;
			}
		}
		if (root->right != NULL)
		{
			rMax=GetMax(root->right);
			if (rMax>0)
			{
				value += rMax;
			}
		}
		if (value>max)
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
			if (A[i]==target)
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
		if (head==NULL)
		{
			return head;
		}
		ListNode* pCur = head;
		ListNode* pNewHead = NULL;
		ListNode* pNewCur = NULL;
		map<int, int> mpRep;
		while (pCur!=NULL)
		{	
			mpRep[pCur->val]++;
			pCur = pCur->next;
		}
		int flagFirst = true;
		pCur = head;
		while (pCur != NULL)
		{
			if (mpRep[pCur->val]==1)
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
		if (pNewCur!=NULL)
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
		while (x!=0)
		{
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		if (sum>INT_MAX||sum<INT_MIN)
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
		if (n==0)
		{
			return 1;
		}
		if (n==1)
		{
			if (A[0]==1)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		int i = 0;
		while (i<n)
		{
			while ((A[i] - 1 != i) && (A[i]>0) && (A[i]<n+1) && (A[i] != A[A[i] - 1]))
			{
				swap(A[i], A[A[i] - 1]);
			}
			i++;
		}
		i = 0;
		while (i<n)
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
