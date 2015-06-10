#include "stdafx.h"
#include "DataStructure.h"


/*-------------------------------------------------------------------------------------*/
class Solution145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root)
		{
			st.push(root);
			while (!st.empty())
			{
				TreeNode* curNode = st.top();
				st.pop();
				result.push_back(curNode->val);
				if (curNode->left)
				{
					st.push(curNode->left);
				}
				if (curNode->right)
				{
					st.push(curNode->right);
				}
			}
			reverse(result.begin(),result.end());
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution144 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root)
		{
			st.push(root);
			while (!st.empty())
			{
				TreeNode* curNode = st.top();
				st.pop();
				result.push_back(curNode->val);
				if (curNode->right)
				{
					st.push(curNode->right);
				}
				if (curNode->left)
				{
					st.push(curNode->left);
				}
			}
		}
		return result;
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
		ListNode* fakeNode = new ListNode(1);
		fakeNode->next = head;
		ListNode* pSlow = fakeNode;
		ListNode* pFast = fakeNode;
		while (pFast->next&&pFast->next->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pSlow == pFast)
			{
				break;
			}
		}
		if (!pFast->next || !pFast->next->next)
		{
			return NULL;
		}
		pFast = fakeNode;
		while (pFast!=pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pFast;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution141 {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fakeNode = new ListNode(1);
		fakeNode->next = head;
		ListNode* pSlow = fakeNode;
		ListNode* pFast = fakeNode;
		while (pFast->next&&pFast->next->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pSlow==pFast)
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
		vector<bool> isOK(len,false);
		isOK[0] = true;
		for (size_t i = 1; i < len; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				isOK[i] = isOK[j] && (wordDict.find(s.substr(j+1,i-j))!=wordDict.end());
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
		for (auto m:mp)
		{
			if (m.second==1)
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
		if (len>0)
		{
			res = nums[0];
			for (size_t i = 1; i < len; i++)
			{
				res ^= nums[i];
			}
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
		std::for_each(candy.begin(), candy.end(), [&](int n){
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
		if (len <= 0)
		{
			return -1;
		}
		vector<int> vec(len, 0);
		for (size_t i = 0; i < len; i++)
		{
			vec[i] = gas[i] - cost[i];
		}
		int leftGas = 0;
		int sum = 0;
		int index = 0;
		for (size_t i = 0; i < len; i++)
		{
			sum += vec[i];
			leftGas += vec[i];
			if (sum < 0)
			{
				sum = 0;
				index = i + 1;
			}
		}
		return leftGas < 0 ? -1 : index;
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
		UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
		qu.push(node);
		mp[node] = nodeCopy;
		while (!qu.empty())
		{
			UndirectedGraphNode* curNode = qu.front();
			qu.pop();
			for (size_t i = 0; i < curNode->neighbors.size(); i++)
			{
				if (mp.find(curNode->neighbors[i]) == mp.end())
				{
					UndirectedGraphNode* neighbourNode = new UndirectedGraphNode(curNode->neighbors[i]->label);
					mp[curNode->neighbors[i]] = neighbourNode;
					mp[curNode]->neighbors.push_back(neighbourNode);
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
		for (int i = len - 1; i >= 0; i--){
			for (int j = i; j < len; j++){
				if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1])){
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
		vector<string> paList;
		if (s.size() > 0)
		{
			GetPa(result, paList, s, 0);
		}
		return result;
	}

	void GetPa(vector<vector<string>>& result, vector<string>& paList, string& s, int index)
	{
		if (index == s.size())
		{
			result.push_back(paList);
		}
		else
		{
			for (size_t i = 0; i + index < s.size(); i++)
			{
				if (IsPa(s, index, i + index))
				{
					paList.push_back(s.substr(index, i + 1));
					GetPa(result, paList, s, i + index + 1);
				}
			}
		}
		if (paList.size() > 0)
		{
			paList.pop_back();
		}
	}

	bool IsPa(string &s, int L, int R)
	{
		while (L < R)
		{
			if (s[L] != s[R])
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
		vector<int> nums;
		SumToLeaf(root, nums, 0);
		return accumulate(nums.begin(), nums.end(), 0);
	}

	void SumToLeaf(TreeNode* root, vector<int> &nums, int curSum)
	{
		if (!root)
		{
			nums.push_back(curSum);
			return;
		}
		if (!root->left&&!root->right)
		{
			nums.push_back(curSum * 10 + root->val);
			return;
		}
		if (root->left)
		{
			SumToLeaf(root->left, nums, curSum * 10 + root->val);
		}
		if (root->right)
		{
			SumToLeaf(root->right, nums, curSum * 10 + root->val);
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
		if (len == 0)
		{
			return true;
		}
		int L = 0;
		int R = len - 1;
		while (L < R)
		{
			while (L < len&&!isalnum(s[L]))L++;
			while (R >= 0 && !isalnum(s[R]))R--;
			if (L < R)
			{
				if (tolower(s[L]) == tolower(s[R]))
				{
					L++;
					R--;
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				break;
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution124 {
public:
	int maxValue = INT_MIN;
	int maxPathSum(TreeNode* root) {
		GetMax(root);
		return maxValue;
	}

	int GetMax(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int lMax = GetMax(root->left);
		int rMax = GetMax(root->right);
		maxValue = max(maxValue, lMax + rMax + root->val);
		int retValue = max(lMax, rMax) + root->val;
		return retValue > 0 ? retValue : 0;
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
		int result = 0;
		if (len >= 2)
		{
			int index = 1;
			while (index < len)
			{
				int minIndex;
				int maxIndex;
				while (index < len&&prices[index] <= prices[index - 1])index++;
				minIndex = index - 1;
				while (index<len&&prices[index] > prices[index - 1])index++;
				maxIndex = index - 1;
				result += (prices[maxIndex] - prices[minIndex]);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int result = 0;
		if (len >= 2)
		{
			int minValue = prices[0];
			result = prices[1] - minValue;
			for (size_t i = 2; i < len; i++)
			{
				minValue = min(prices[i - 1], minValue);
				result = prices[i] - minValue > result ? prices[i] - minValue : result;
			}
			result = result < 0 ? 0 : result;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution120 {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		for (int i = len - 2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
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
		if (rowIndex > 0)
		{
			for (int i = 1; i <= rowIndex; i++)
			{
				for (int j = i - 1; j > 0; j--)
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
		if (numRows >= 1)
		{
			result.push_back(vector < int > {1});
			for (int i = 1; i < numRows; i++)
			{
				vector<int> vec;
				vec.push_back(1);
				for (int j = 0; j < result[i - 1].size() - 1; j++)
				{
					vec.push_back(result[i - 1][j] + result[i - 1][j + 1]);
				}
				vec.push_back(1);
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
		if (root == NULL) return;
		TreeLinkNode* p = root->next;
		while (p != NULL)
		{
			if (p->left != NULL)
			{
				p = p->left;
				break;
			}
			if (p->right != NULL)
			{
				p = p->right;
				break;
			}
			p = p->next;
		}
		if (root->right != NULL)
		{
			root->right->next = p;
		}
		if (root->left != NULL)
		{
			root->left->next = root->right ? root->right : p;
		}
		connect(root->right);
		connect(root->left);
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution116 {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
		{
			return;
		}
		if (root->left)
		{
			root->left->next = root->right;
		}
		if (root->next&&root->right)
		{
			root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
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
		vector<int> nums;
		GetPath(result, nums, root, sum, 0);
		return result;
	}

	void GetPath(vector<vector<int>> &result, vector<int> &nums, TreeNode* root, int target, int sum) {
		if (!root)
		{
			return;
		}
		else
		{
			nums.push_back(root->val);
			if (!root->left&&!root->right)
			{
				if (target == sum + root->val)
				{
					result.push_back(nums);
				}
			}
			if (root->left)
			{
				GetPath(result, nums, root->left, target, sum + root->val);
			}
			if (root->right)
			{
				GetPath(result, nums, root->right, target, sum + root->val);
			}
			nums.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution112 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		return CheckSum(root, sum, 0);
	}

	bool CheckSum(TreeNode* root, int target, int sum) {
		if (!root)
		{
			return false;
		}
		else
		{
			if (!root->left&&!root->right)
			{
				return target == sum + root->val;
			}
			if (root->left)
			{
				if (CheckSum(root->left, target, sum + root->val))
				{
					return true;
				}
			}
			if (root->right)
			{
				if (CheckSum(root->right, target, sum + root->val))
				{
					return true;
				}
			}
			return false;
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
		if (!root->left&&!root->right)
		{
			return 1;
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
		if (!root)
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
			pCur = pCur->next;
			len++;
		}
		return Build(head, 0, len - 1);
	}

	TreeNode* Build(ListNode*& head, int L, int R)
	{
		if (L > R)
		{
			return NULL;
		}
		int M = L + ((R - L) >> 1);
		TreeNode* leftChild = Build(head, L, M - 1);
		TreeNode* root = new TreeNode(head->val);
		root->left = leftChild;
		head = head->next;
		root->right = Build(head, M + 1, R);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution108 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return Build(nums, 0, nums.size() - 1);
	}

	TreeNode* Build(vector<int>& nums, int L, int R)
	{
		if (L > R)
		{
			return NULL;
		}
		int M = L + ((R - L) >> 1);
		TreeNode* root = new TreeNode(nums[M]);
		root->left = Build(nums, L, M - 1);
		root->right = Build(nums, M + 1, R);
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

	TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int postS, int postE)
	{
		if (inS > inE)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[postE]);
		int inRoot;
		for (int i = inS; i <= inE; i++)
		{
			if (postorder[postE] == inorder[i])
			{
				inRoot = i;
				break;
			}
		}
		root->left = Build(inorder, postorder, inS, inRoot - 1, postS, inRoot - 1 - inS + postS);
		root->right = Build(inorder, postorder, inRoot + 1, inE, postE - inE + inRoot, postE - 1);
		return root;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution105 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return Build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE)
	{
		if (preS > preE)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[preS]);
		int inRoot;
		for (int i = inS; i <= inE; i++)
		{
			if (preorder[preS] == inorder[i])
			{
				inRoot = i;
				break;
			}
		}
		root->left = Build(preorder, inorder, preS + 1, inRoot - inS + preS, inS, inRoot - 1);
		root->right = Build(preorder, inorder, preE - inE + inRoot + 1, preE, inRoot + 1, inE);
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
		else
		{
			return max(maxDepth(root->left), maxDepth(root->right)) + 1;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution103{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> qu;
		vector<vector<int>> result;
		if (root)
		{
			int curCnt = 1;
			int nextCnt = 0;
			qu.push(root);
			vector<int> levelNodes;
			bool isReversed = false;
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
					if (isReversed)
					{
						reverse(levelNodes.begin(), levelNodes.end());
					}
					result.push_back(levelNodes);
					curCnt = nextCnt;
					nextCnt = 0;
					isReversed = !isReversed;
					levelNodes.clear();
				}
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
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution101 {
public:
	bool isSymmetric(TreeNode* root) {
		return Check(root);
	}

	bool Check(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		if (!root->left&&!root->right)
		{
			return true;
		}
		else if (root->left&&root->right)
		{
			return CheckSymmetric(root->left, root->right);
		}
		else
		{
			return false;
		}
	}
	bool CheckSymmetric(TreeNode* p, TreeNode* q)
	{
		if (!p&&!q)
		{
			return true;
		}
		else if (p&&q)
		{
			return p->val == q->val&&CheckSymmetric(p->left, q->right) && CheckSymmetric(p->right, q->left);
		}
		else
		{
			return false;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution100 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return PreOrderCheck(p, q);
	}

	bool PreOrderCheck(TreeNode* p, TreeNode* q)
	{
		if (!p&&!q)
		{
			return true;
		}
		if (p&&q)
		{
			return p->val == q->val&&PreOrderCheck(p->left, q->left) && PreOrderCheck(p->right, q->right);
		}
		else
		{
			return false;
		}
		return true;
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
		vector<int> result;
		InOrder(root, result);
		if (result.size() > 1)
		{
			for (size_t i = 1; i < result.size(); i++)
			{
				if (result[i] <= result[i - 1])
				{
					return false;
				}
			}
		}
		return true;
	}

	void InOrder(TreeNode* root, vector<int>& result)
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
				result.push_back(pCur->val);
				pCur = pCur->right;
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
		TreeNode* p = root;
		while (!st.empty() || p)
		{
			if (p)
			{
				st.push(p);
				p = p->left;
			}
			else
			{
				result.push_back(st.top()->val);
				p = st.top()->right;
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
		vector<string> result;
		if (s.size() >= 4)
		{
			GetIP(result, s, 0, 0, "");
		}
		for (int i = 0; i < result.size(); i++)
		{
			result[i].pop_back();
		}
		return result;
	}

	void GetIP(vector<string>& result, string &s, int index, int cnt, string curIP)
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
				if (index + i - 1 < s.size())
				{
					string strIPPart = s.substr(index, i);
					if (IsValidNum(strIPPart))
					{
						GetIP(result, s, index + i, cnt + 1, curIP + strIPPart + ".");
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
			return num >= 1 && num <= 255;
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
		if (s.size() > 0)
		{
			vector<int> dp(s.size(), 0);
			if (CheckOne(s, 0))
			{
				dp[0] = 1;
				if (CheckOne(s, 1))
				{
					if (CheckTwo(s, 1))
					{
						dp[1] = 2;
					}
					else
					{
						dp[1] = 1;
					}
				}
				else
				{
					if (CheckTwo(s, 1))
					{
						dp[1] = 1;
					}
					else
					{
						dp[1] = 0;
					}
				}
			}
			else
			{
				dp[0] = 0;
				dp[1] = 0;
			}
			for (size_t i = 2; i < s.size(); i++)
			{
				if (CheckOne(s, i))
				{
					if (CheckTwo(s, i))
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
					if (CheckTwo(s, i))
					{
						dp[i] = dp[i - 2];
					}
					else
					{
						dp[i] = 0;
					}
				}
			}
			return dp[s.size() - 1];
		}
		else
		{
			return 0;
		}
	}
	bool CheckOne(string &s, int index)
	{
		return s[index] >= '1'&&s[index] <= '9';
	}
	bool CheckTwo(string &s, int index)
	{
		return s[index - 1] == '1' || (s[index - 1] == '2'&&s[index] >= '0'&&s[index] <= '6');
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution090 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> vec;
		sort(nums.begin(), nums.end());
		GetComb(result, vec, nums, -1);
		return result;
	}

	void GetComb(vector<vector<int>> &result, vector<int> &vec, vector<int>& nums, int index)
	{
		if (vec.size() <= nums.size())
		{
			result.push_back(vec);
			if (vec.size() < nums.size())
			{
				for (size_t i = index + 1; i < nums.size(); i++)
				{
					vec.push_back(nums[i]);
					GetComb(result, vec, nums, i);
					while (index + 1 < nums.size() && nums[i] == nums[i + 1])i++;
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
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
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
		ListNode* newHead = new ListNode(INT_MAX);
		newHead->next = head;
		ListNode* pCur = newHead;
		int preVal;
		while (pCur->next)
		{
			if (pCur->val == pCur->next->val)
			{
				pCur->next = pCur->next->next;
			}
			else
			{
				pCur = pCur->next;
			}
		}
		return newHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution082 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* newHead = new ListNode(INT_MAX);
		newHead->next = head;
		ListNode* pCur = head;
		ListNode* pPre = newHead;
		while (pCur)
		{
			while (pCur->next && (pCur->next->val == pPre->val || pCur->next->val == pCur->val))
			{
				pCur = pCur->next;
			}
			if (pPre->next == pCur)
			{
				pPre = pPre->next;
			}
			else
			{
				pPre->next = pCur->next;
			}
			pCur = pCur->next;
		}
		return newHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution081 {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len > 0)
		{
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
				else if (nums[M]<nums[L])
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
					L = L + 1;
				}
			}
			return false;
		}
		else
		{
			return false;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution080 {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return 0;
		int occur = 1;
		int index = 0;
		for (int i = 1; i < len; i++)
		{
			if (nums[index] == nums[i])
			{
				if (occur == 2)
				{
					continue;
				}
				occur++;
			}
			else
			{
				occur = 1;
			}
			nums[++index] = nums[i];
		}
		return index + 1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution079 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int M = board.size();
		int N = 0;
		if (M)
		{
			N = board[0].size();
		}
		if (M&&N)
		{
			vector<vector<bool>> isVisited(M, vector<bool>(N, false));
			for (size_t i = 0; i < M; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					if (DFS(board, word, isVisited, 0, i, j))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	bool DFS(vector<vector<char>>& board, string &word, vector<vector<bool>> &isVisited, int index, int row, int col)
	{
		if (word[index] != board[row][col])
		{
			return false;
		}
		if (index == word.size() - 1)
		{
			return true;
		}
		else
		{
			isVisited[row][col] = true;
			if (row - 1 >= 0 && !isVisited[row - 1][col] && DFS(board, word, isVisited, index + 1, row - 1, col))
			{
				return true;
			}
			if (col - 1 >= 0 && !isVisited[row][col - 1] && DFS(board, word, isVisited, index + 1, row, col - 1))
			{
				return true;
			}
			if (row + 1 < board.size() && !isVisited[row + 1][col] && DFS(board, word, isVisited, index + 1, row + 1, col))
			{
				return true;
			}
			if (col + 1 < board[0].size() && !isVisited[row][col + 1] && DFS(board, word, isVisited, index + 1, row, col + 1))
			{
				return true;
			}
			isVisited[row][col] = false;
			return false;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution078 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> vec;
		sort(nums.begin(), nums.end());
		GetComb(result, vec, nums, -1);
		return result;
	}

	void GetComb(vector<vector<int>> &result, vector<int> &vec, vector<int>& nums, int index)
	{
		if (vec.size() <= nums.size())
		{
			result.push_back(vec);
			if (vec.size() < nums.size())
			{
				for (size_t i = index + 1; i < nums.size(); i++)
				{
					vec.push_back(nums[i]);
					GetComb(result, vec, nums, i);
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
class Solution077 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> vec;
		vector<bool> isVisited(n, false);
		if (k <= n)
		{
			GetComb(result, vec, isVisited, n, k);
		}
		return result;
	}

	void GetComb(vector<vector<int>> &result, vector<int> &vec, vector<bool> &isVisited, int n, int k)
	{
		if (vec.size() == k)
		{
			result.push_back(vec);
		}
		else
		{
			for (size_t i = vec.size() == 0 ? 1 : vec[vec.size() - 1] + 1; i <= n; i++)
			{
				if (!isVisited[i - 1])
				{
					isVisited[i - 1] = true;
					vec.push_back(i);
					GetComb(result, vec, isVisited, n, k);
					isVisited[i - 1] = false;
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
class Solution074 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		return BinarySearch(matrix, target);
	}

	bool BinarySearch(vector<vector<int>>& matrix, int target)
	{
		int M = matrix.size();
		int N = 0;
		if (M)
		{
			N = matrix[0].size();
		}
		int L = 0;
		int R = M*N - 1;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (matrix[mid / N][mid%N] < target)
			{
				L = mid + 1;
			}
			else
			{
				R = mid;
			}
		}
		return matrix[L / N][L%N] == target ? true : false;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution073 {
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
		vector<bool> row(M, false);
		vector<bool> col(N, false);
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = true;
					col[j] = true;
				}
			}
		}
		for (size_t i = 0; i < M; i++)
		{
			if (row[i])
			{
				matrix[i].assign(N, 0);
			}
		}
		for (size_t i = 0; i < N; i++)
		{
			if (col[i])
			{
				for (size_t j = 0; j < M; j++)
				{
					matrix[j][i] = 0;
				}
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
		while (L <= R)
		{
			long long mid = L + ((R - L) >> 1);
			long long res = mid*mid;
			if (res < x)
			{
				L = mid + 1;
			}
			else if (res > x)
			{
				R = mid - 1;
			}
			else
			{
				return mid;
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
		string result;
		int carry = 0;
		for (int i = 0; i < lenB; i++)
		{
			int res = (a[i] - '0') + (b[i] - '0') + carry;
			carry = res / 2;
			result.push_back((res % 2) + '0');
		}
		for (int i = lenB; i < lenA; i++)
		{
			int res = (a[i] - '0') + carry;
			carry = res / 2;
			result.push_back((res % 2) + '0');
		}
		if (carry == 1)
		{
			result.push_back('1');
		}
		reverse(result.begin(), result.end());
		return result;
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
			if (carry == 1 && digits[i] == 9)
			{
				result.push_back(0);
			}
			else
			{
				result.push_back(carry + digits[i]);
				carry = 0;
			}
		}
		if (carry == 1)
		{
			result.push_back(1);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution065 {
public:
	bool isNumber(string s) {
		int len = s.size();
		int index = 0;
		while (index < len&&isspace(s[index]))index++;
		if (index < len && (s[index] == '+' || s[index] == '-'))
		{
			index++;
		}
		bool isNum = false;
		while (index < len&&isdigit(s[index]))
		{
			index++;
			isNum = true;
		}
		if (index < len && s[index] == '.')
		{
			index++;
			while (index < len&&isdigit(s[index]))
			{
				index++;
				isNum = true;
			}
		}
		if (isNum && index < len && (s[index] == 'E' || s[index] == 'e'))
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
		int m = grid.size();
		int n = 0;
		if (m)
		{
			n = grid[0].size();
		}
		if (m > 0 && n > 0)
		{
			vector<vector<int>> paths(m, vector<int>(n, 0));
			paths[0][0] = grid[0][0];
			for (size_t i = 1; i < m; i++)
			{
				paths[i][0] = grid[i][0] + paths[i - 1][0];
			}
			for (size_t i = 1; i < n; i++)
			{
				paths[0][i] = grid[0][i] + paths[0][i - 1];
			}
			for (size_t i = 1; i < m; i++)
			{
				for (size_t j = 1; j < n; j++)
				{
					paths[i][j] = grid[i][j] + min(paths[i - 1][j], paths[i][j - 1]);
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
class Solution063 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = 0;
		if (m)
		{
			n = obstacleGrid[0].size();
		}
		if (m > 0 && n > 0)
		{
			vector<vector<int>> paths(m, vector<int>(n, 0));
			paths[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
			for (size_t i = 1; i < m; i++)
			{
				paths[i][0] = obstacleGrid[i][0] == 1 ? 0 : paths[i - 1][0];
			}
			for (size_t i = 1; i < n; i++)
			{
				paths[0][i] = obstacleGrid[0][i] == 1 ? 0 : paths[0][i - 1];
			}
			for (size_t i = 1; i < m; i++)
			{
				for (size_t j = 1; j < n; j++)
				{
					paths[i][j] = obstacleGrid[i][j] == 1 ? 0 : paths[i - 1][j] + paths[i][j - 1];
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
			return NULL;
		}
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode* p1 = newHead;
		ListNode* p2 = newHead;
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
			p2 = p2->next;
		}
		while (p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = newHead->next;
		newHead->next = p1->next;
		p1->next = NULL;
		return newHead->next;
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
			int index = 1;
			int row = 0;
			int col = -1;
			int M = n;
			int N = n;
			while (true)
			{
				for (size_t i = 0; i < N; i++)
				{
					result[row][++col] = index;
					index++;
				}
				if (--M == 0)break;
				for (size_t i = 0; i < M; i++)
				{
					result[++row][col] = index;
					index++;
				}
				if (--N == 0)break;
				for (size_t i = 0; i < N; i++)
				{
					result[row][--col] = index;
					index++;
				}
				if (--M == 0)break;
				for (size_t i = 0; i < M; i++)
				{
					result[--row][col] = index;
					index++;
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

	Interval Merge(Interval I1, Interval I2)
	{

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
		vector<int> reaminStep(len, 0);
		if (len == 0)
		{
			return false;
		}
		else
		{
			reaminStep[0] = nums[0];
			for (size_t i = 1; i < len; i++)
			{
				if (reaminStep[i - 1] <= 0)
				{
					return false;
				}
				reaminStep[i] = max(reaminStep[i - 1] - 1, nums[i]);
			}
			return reaminStep[len - 1] >= 0;
		}
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
		int maxSum = 0;
		if (len > 0)
		{
			int curSum = nums[0];
			maxSum = nums[0];
			for (size_t i = 1; i < len; i++)
			{
				curSum = max(curSum + nums[i], nums[i]);
				maxSum = max(curSum, maxSum);
			}
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
			return 1.0 / Pow(x, -n);
		}
		else
		{
			return Pow(x, n);
		}
	}
	double Pow(double x, int n)
	{
		if (n == 0)
			return 1;

		double v = pow(x, n / 2);
		if (n % 2 == 0)
		{
			return v*v;
		}
		else
		{
			return v*v*x;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution049 {
public:
	vector<string> anagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> ump;
		for (size_t i = 0; i < strs.size(); i++)
		{
			string sortedStr = strs[i];
			sort(sortedStr.begin(), sortedStr.end());
			ump[sortedStr].push_back(strs[i]);
		}
		vector<string> result;
		for (auto um : ump)
		{
			if (um.second.size() > 1)
			{
				for (size_t i = 0; i < um.second.size(); i++)
				{
					result.push_back(um.second[i]);
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
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N / 2; j++)
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
		vector<bool> isVisited(nums.size(), false);
		vector<int> vec;
		if (nums.size() > 0)
		{
			sort(nums.begin(), nums.end());
			GetPerm(result, isVisited, nums, vec);
		}
		return result;
	}

	void GetPerm(vector<vector<int>>& result, vector<bool>& isVisited, vector<int>& nums, vector<int>& vec)
	{
		if (vec.size() == nums.size())
		{
			result.push_back(vec);
		}
		else
		{
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (!isVisited[i])
				{
					isVisited[i] = true;
					vec.push_back(nums[i]);
					GetPerm(result, isVisited, nums, vec);
					isVisited[i] = false;
					while (i < nums.size() - 1 && nums[i] == nums[i + 1])
					{
						i++;
					}
				}
			}
		}
		if (!vec.empty())
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
		vector<bool> isVisited(nums.size(), false);
		vector<int> vec;
		if (nums.size() > 0)
		{
			GetPerm(result, isVisited, nums, vec);
		}
		return result;
	}

	void GetPerm(vector<vector<int>>& result, vector<bool>& isVisited, vector<int>& nums, vector<int>& vec)
	{
		if (vec.size() == nums.size())
		{
			result.push_back(vec);
		}
		else
		{
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (!isVisited[i])
				{
					isVisited[i] = true;
					vec.push_back(nums[i]);
					GetPerm(result, isVisited, nums, vec);
					isVisited[i] = false;
				}
			}
		}
		if (!vec.empty())
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution043 {
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
		sort(candidates.begin(), candidates.end());
		if (candidates.size() > 0)
		{
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
			for (int i = vec.size() == 0 ? 0 : index + 1; i < candidates.size(); i++)
			{
				if (sum + candidates[i] <= target)
				{
					vec.push_back(candidates[i]);
					GetComb(result, candidates, vec, sum + candidates[i], target, i);
					while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
				}

			}
		}
		if (vec.size() != 0)
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
		sort(candidates.begin(), candidates.end());
		if (candidates.size() > 0)
		{
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
			for (size_t i = index; i < candidates.size(); i++)
			{
				vec.push_back(candidates[i]);
				GetComb(result, candidates, vec, sum + candidates[i], target, i);
				while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
			}
		}
		if (vec.size() != 0)
		{
			vec.pop_back();
		}
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution038 {
public:
	string countAndSay(int n) {
		if (n <= 0)
		{
			return "";
		}
		string str = "1";
		for (int i = 1; i < n; i++)
		{
			string tmp;
			int len = str.size();
			int index = 0;
			char ch = str[0];
			int cnt = 0;
			while (index < len)
			{
				while (index < len&&str[index] == ch)
				{
					cnt++;
					index++;
				}
				tmp += (cnt + '0');
				tmp += ch;
				if (index == len)
				{
					str = tmp;
					break;
				}
				else
				{
					ch = str[index];
					cnt = 0;
				}
			}
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
		if (len == 0)
		{
			return 0;
		}
		if (target > nums[len - 1])
		{
			return len;
		}
		int L = 0;
		int R = len - 1;
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
		return nums[L] < target ? L + 1 : L;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution034 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		int First = FindFirst(nums, target);
		result.push_back(First);
		if (First != -1)
		{
			result.push_back(FindLast(nums, target));
		}
		else
		{
			result.push_back(-1);
		}
		return result;

	}

	int FindFirst(vector<int>& nums, int target)
	{
		int L = 0;
		int R = nums.size() - 1;
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
	int FindLast(vector<int>& nums, int target)
	{
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int M = L + ((R - L + 1) >> 1);
			if (nums[M] > target)
			{
				R = M - 1;
			}
			else
			{
				L = M;
			}
		}
		return nums[R] == target ? R : -1;
	}
};
/*-------------------------------------------------------------------------------------*/
class Solution033 {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int L = 0;
		int R = len - 1;
		if (len == 0)
		{
			return -1;
		}
		while (L < R)
		{
			int M = L + ((R - L) >> 1);
			if (nums[M] == target)
			{
				return M;
			}
			if (nums[M] >= nums[L])
			{
				if (target < nums[M] && target >= nums[L])
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
				if (target <= nums[R] && target > nums[M])
				{
					L = M + 1;
				}
				else
				{
					R = M - 1;
				}
			}
		}
		return nums[R] == target ? R : -1;
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
		vector<int> nextArray(nLen, -1);
		GetNextArray(needle, nextArray);
		int i = 0, j = 0;
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
		if (j == nLen)
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
			if (nums[i] == val)
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
		int pre = INT_MIN;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] == pre)
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
		ListNode* pPre = fakeHead;
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
		if (n >= 0)
		{
			GenPar(result, n, 0, 0, "");
		}
		return result;
	}

	void GenPar(vector<string>& result, int n, int leftCnt, int rightCnt, string patern)
	{
		int len = patern.size();
		if (len == 2 * n)
		{
			result.push_back(patern);
			return;
		}
		if (leftCnt < n)
		{
			GenPar(result, n, leftCnt + 1, rightCnt, patern + "(");
		}
		if (leftCnt > rightCnt)
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
