#include "stdafx.h"
#include "DataStructure.h"
/*-------------------------------------------------------------------------------------*/
/*House Robber II */
class Solution131 {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		if (len == 1)
		{
			return nums[0];
		}
		vector<int> dp(len, 0);
		dp[0] = nums[0];
		dp[1] = nums[0];
		int max;
		for (size_t i = 2; i < len - 1; i++)
		{
			dp[i] = dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
		}
		max = dp[len - 2];
		dp[0] = 0;
		dp[1] = nums[1];
		for (size_t i = 2; i < len; i++)
		{
			dp[i] = dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
		}
		return max > dp[len - 1] ? max : dp[len - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
/*Reverse Linked List II */
class Solution130 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || m == n)
		{
			return head;
		}
		int len = n - m + 1;
		ListNode* newHead = new ListNode(-1);
		newHead->next = head;
		int index = 0;
		ListNode* pCur = newHead;
		ListNode* pDiscNext = nullptr;
		ListNode* pNext = nullptr;
		ListNode* pDisc = nullptr;
		while (m--)
		{
			pDisc = pCur;
			pCur = pCur->next;
			pDiscNext = pCur;
		}
		pNext = pCur->next;
		while (len--)
		{
			pCur->next = pDisc->next;
			pDisc->next = pCur;
			pCur = pNext;
			if (pNext)
			{
				pNext = pCur->next;
			}
		}
		pDiscNext->next = pCur;
		return newHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Repeated DNA Sequences */
class Solution129 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_set<int> resultAdded;
		if (s.size() < 10)
		{
			return result;
		}
		unordered_map<int, int> ump;
		for (int i = 0; i <= s.size() - 10; i++)
		{
			string str = s.substr(i, 10);
			int key = str2int(str);
			ump[key]++;
			if (ump[key] > 1 && resultAdded.find(key) == resultAdded.end())
			{
				result.push_back(str);
				resultAdded.insert(key);
			}
		}
		return result;
	}

	int str2int(string str)
	{
		int result = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			switch (str[i])
			{
			case 'A':result += result * 4 + 1; break;
			case 'C':result += result * 4 + 2; break;
			case 'T':result += result * 4 + 3; break;
			case 'G':result += result * 4 + 4; break;
			default:
				break;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Restore IP Addresses */
class Solution128 {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		int len = s.size();
		if (len > 0)
		{
			GetIP(result, s, "", 1);
		}
		return result;
	}

	void GetIP(vector<string> &result, string remainIP, string curIP, int index)
	{
		if (index == 4)
		{
			if (IsValid(remainIP))
			{
				curIP += remainIP;
				result.push_back(curIP);
			}
			return;
		}
		else
		{
			if (remainIP.size() == 0)
			{
				return;
			}
			for (size_t i = 1; i < 4 && i < remainIP.size(); i++)
			{
				string addStr = remainIP.substr(0, i);
				if (!IsValid(addStr))
				{
					continue;
				}
				string newReamin = remainIP.substr(i);
				GetIP(result, newReamin, curIP + addStr + ".", index + 1);
			}
		}
	}

	bool IsValid(string str)
	{
		int len = str.size();
		if (str.size() <= 0 || str.size() > 3)
		{
			return false;
		}
		if (str[0] == '0'&&len != 1)
		{
			return false;
		}
		if (len == 3 && stoi(str) > 255)
		{
			return false;
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Container With Most Water*/
class Solution127 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		if (len == 0)
		{
			return 0;
		}
		int start = 0;
		int end = len - 1;
		int maxArea = 0;
		while (start < end)
		{
			int area = min(height[start], height[end])*(end - start);
			maxArea = max(maxArea, area);
			if (height[start] < height[end])
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		return maxArea;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Insertion Sort List*/
class Solution126 {
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
/*Divide Two Integers*/
class Solution125 {
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
/*Partition List */
class Solution124 {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
		{
			return NULL;
		}
		vector<ListNode*> lessList;
		vector<ListNode*> greaterList;
		ListNode* pCur = head;
		while (pCur)
		{
			if (pCur->val < x)
			{
				lessList.push_back(pCur);
			}
			else
			{
				greaterList.push_back(pCur);
			}
			pCur = pCur->next;
		}
		ListNode* newHead = NULL;
		pCur = NULL;
		if (lessList.size() > 0)
		{
			newHead = lessList[0];
			pCur = newHead;
			for (size_t i = 1; i < lessList.size(); i++)
			{
				pCur->next = lessList[i];
				pCur = lessList[i];
			}
			for (size_t i = 0; i < greaterList.size(); i++)
			{
				pCur->next = greaterList[i];
				pCur = greaterList[i];
			}
			pCur->next = NULL;
			return newHead;
		}
		else
		{
			newHead = greaterList[0];
			pCur = newHead;
			for (size_t i = 1; i < greaterList.size(); i++)
			{
				pCur->next = greaterList[i];
				pCur = greaterList[i];
			}
			pCur->next = NULL;
			return newHead;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Subsets */
class Solution123 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > result;
		int len = nums.size();
		int cnt = 1 << len;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < cnt; i++)
		{
			vector<int> vec;
			int num = i;
			for (size_t j = 0; j < len; j++)
			{
				int iSelect = num & 1;
				if (iSelect == 1)
				{
					vec.push_back(nums[j]);
				}
				num >>= 1;
			}
			result.push_back(vec);
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Subsets II */
class Solution122 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > result;
		int len = nums.size();
		int cnt = 1 << len;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < cnt; i++)
		{
			vector<int> vec;
			int num = i;
			for (size_t j = 0; j < len; j++)
			{
				int iSelect = num & 1;
				if (iSelect == 1)
				{
					vec.push_back(nums[j]);
				}
				num >>= 1;
			}
			result.push_back(vec);
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Decode Ways */
class Solution121 {
public:
	int numDecodings(string s) {
		int len = s.size();
		vector<int> dp(len, 0);
		if (len == 0)
		{
			return 0;
		}
		dp[0] = s[0] == '0' ? 0 : 1;
		if (dp[0] == 0)
		{
			return 0;
		}
		if (len > 1)
		{
			if (s[1] == '0')
			{
				if (s[0] == '0' || s[0] > '2')
				{
					return 0;
				}
				dp[1] = 1;
			}
			else
			{
				int num = (s[0] - '0') * 10 + (s[1] - '0');
				if (num >= 1 && num <= 26)
				{
					dp[1] = 2;
				}
				else
				{
					dp[1] = 1;
				}

			}
			for (size_t i = 2; i < len; i++)
			{
				if (s[i] == '0')
				{
					if (s[i - 1] == '0' || s[i - 1] > '2')
					{
						return 0;
					}
					dp[i] = dp[i - 2];
				}
				else
				{
					if (s[i - 1] == '0' || s[i - 1] > '2')
					{
						dp[i] = dp[i - 1];
					}
					else
					{
						int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
						if (num >= 1 && num <= 26)
						{
							dp[i] = dp[i - 2] + dp[i - 1];
						}
						else
						{
							dp[i] = dp[i - 1];
						}
					}

				}
			}
		}
		return dp[len - 1];
	}
};

/*-------------------------------------------------------------------------------------*/
/*Generate Parentheses */
class Solution120 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0)
		{
			string str;
			Gen(result, str, 0, 0, n, 0);
		}
		return result;
	}


	void Gen(vector<string>& result, string str, int leftCnt, int rightCnt, int n, int curCnt)
	{
		if (rightCnt > leftCnt)
		{
			return;
		}
		if (leftCnt == n&&rightCnt == n)
		{
			result.push_back(str);
			return;
		}
		if (leftCnt < n)
		{
			Gen(result, str + '(', leftCnt + 1, rightCnt, n, curCnt + 1);
		}
		if (rightCnt < leftCnt)
		{
			Gen(result, str + ')', leftCnt, rightCnt + 1, n, curCnt + 1);
		}
	}

	//void Gen(vector<string>& result, string &str, int leftCnt, int rightCnt, int n, int curCnt)
	//{
	//	if (curCnt == 2 * n)
	//	{
	//		result.push_back(str);
	//		return;
	//	}
	//	if (leftCnt < n)
	//	{
	//		str += '(';
	//		Gen(result, str, leftCnt + 1, rightCnt, n, curCnt + 1);
	//		str.resize(str.size() - 1);
	//	}
	//	if (rightCnt < leftCnt)
	//	{
	//		str += ')';
	//		Gen(result, str, leftCnt, rightCnt + 1, n, curCnt + 1);
	//		str.resize(str.size() - 1);
	//	}
	//}
};
/*-------------------------------------------------------------------------------------*/
/*Add and Search Word - Data structure design*/
class WordDictionary {
public:

	class TrieNode {
	public:
		TrieNode() {
			for (size_t i = 0; i < 26; i++)
			{
				nextNodes[i] = NULL;
			}
			isWord = false;
		}
		bool isWord;
		TrieNode* nextNodes[26];
	};

	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		void insert(string s) {
			TrieNode* pCur = root;
			for (size_t i = 0; i < s.size(); i++)
			{
				if (!pCur->nextNodes[s[i] - 'a'])
				{
					pCur->nextNodes[s[i] - 'a'] = new TrieNode();
				}
				pCur = pCur->nextNodes[s[i] - 'a'];
			}
			pCur->isWord = true;
		}

		bool search(string key, TrieNode* startRoot) {
			TrieNode* pCur = startRoot;
			for (size_t i = 0; i < key.size(); i++)
			{
				if (key[i] == '.')
				{
					for (size_t j = 0; j < 26; j++)
					{
						TrieNode* pTemp = pCur->nextNodes[j];
						if (pTemp && search(key.substr(i + 1, key.size() - i), pTemp))
						{
							return true;
						}
					}
					return false;
				}
				else
				{
					pCur = pCur->nextNodes[key[i] - 'a'];
					if (!pCur)
					{
						return false;
					}
				}
			}
			return pCur->isWord;
		}

		bool startsWith(string prefix) {
			TrieNode* pCur = root;
			for (size_t i = 0; i < prefix.size(); i++)
			{
				pCur = pCur->nextNodes[prefix[i] - 'a'];
				if (!pCur)
				{
					return false;
				}
			}
			return true;
		}
		TrieNode* root;
	};

	Trie mTrie;


	// Adds a word into the data structure.
	void addWord(string word) {
		mTrie.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return mTrie.search(word, mTrie.root);
	}
};
/*-------------------------------------------------------------------------------------*/
/*Swap Nodes in Pairs */
class Solution119 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* pA = head;
		ListNode* pB = head->next;
		ListNode* nextNode = pB->next;
		ListNode* preNode = new ListNode(-1);
		preNode->next = pA;
		ListNode* newHead = preNode;
		while (pA&&pB)
		{

			pA->next = nextNode;
			pB->next = pA;
			preNode->next = pB;
			preNode = pA;
			pA = preNode->next;
			if (pA)
			{
				pB = pA->next;
			}
			else
			{
				break;
			}
			if (pB)
			{
				nextNode = pB->next;
			}
			else
			{
				break;
			}
		}
		return newHead->next;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Postorder Traversal */
class Solution118 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root)
		{
			st.push(root);
		}
		TreeNode* pCur;
		while (!st.empty())
		{
			pCur = st.top();
			st.pop();
			result.push_back(pCur->val);
			if (pCur->left)
			{
				st.push(pCur->left);
			}
			if (pCur->right)
			{
				st.push(pCur->right);
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Inorder Traversal*/
class Solution117 {
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
				pCur = st.top();
				st.pop();
				result.push_back(pCur->val);
				pCur = pCur->right;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Preorder Traversal*/
class Solution116 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root)
		{
			st.push(root);
		}
		while (!st.empty())
		{
			TreeNode* pCur = st.top();
			st.pop();
			result.push_back(pCur->val);
			if (pCur->right)
			{
				st.push(pCur->right);
			}
			if (pCur->left)
			{
				st.push(pCur->left);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Implement Trie (Prefix Tree) */
class TrieNode {
public:
	TrieNode() {
		for (size_t i = 0; i < 26; i++)
		{
			nextNodes[i] = NULL;
		}
		isWord = false;
	}
	bool isWord;
	TrieNode* nextNodes[26];
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string s) {
		TrieNode* pCur = root;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (!pCur->nextNodes[s[i] - 'a'])
			{
				pCur->nextNodes[s[i] - 'a'] = new TrieNode();
			}
			pCur = pCur->nextNodes[s[i] - 'a'];
		}
		pCur->isWord = true;
	}

	bool search(string key) {
		TrieNode* pCur = root;
		for (size_t i = 0; i < key.size(); i++)
		{
			pCur = pCur->nextNodes[key[i] - 'a'];
			if (!pCur)
			{
				return false;
			}
		}
		return pCur->isWord;
	}

	bool startsWith(string prefix) {
		TrieNode* pCur = root;
		for (size_t i = 0; i < prefix.size(); i++)
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
/*-------------------------------------------------------------------------------------*/
/*Course Schedule II*/
class Solution115 {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result;
		if (numCourses > 0)
		{
			vector<int> inDegree(numCourses, 0);
			vector<int> isVisited(numCourses, false);
			for (size_t i = 0; i < prerequisites.size(); i++)
			{
				inDegree[prerequisites[i].first]++;
			}
			while (true)
			{
				if (accumulate(isVisited.begin(), isVisited.end(), 0) == numCourses)
				{
					return result;
				}
				bool findOne = false;
				for (size_t i = 0; i < numCourses; i++)
				{
					if (inDegree[i] == 0 && !isVisited[i])
					{
						findOne = true;
						isVisited[i] = true;
						result.push_back(i);
						for (size_t j = 0; j < prerequisites.size(); j++)
						{
							if (prerequisites[j].second == i)
							{
								inDegree[prerequisites[j].first]--;
							}
						}
						break;
					}
				}
				if (!findOne)
				{
					result.clear();
					return result;
				}
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Course Schedule*/
class Solution114 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		bool can = true;
		if (numCourses > 1)
		{
			vector<int> inDegree(numCourses, 0);
			vector<int> isVisited(numCourses, false);
			for (size_t i = 0; i < prerequisites.size(); i++)
			{
				inDegree[prerequisites[i].first]++;
			}
			while (true)
			{
				if (accumulate(inDegree.begin(), inDegree.end(), 0) == 0)
				{
					return true;
				}
				bool findOne = false;
				for (size_t i = 0; i < numCourses; i++)
				{
					if (!isVisited[i] && inDegree[i] == 0)
					{
						findOne = true;
						isVisited[i] = true;
						for (size_t j = 0; j < prerequisites.size(); j++)
						{
							if (prerequisites[j].second == i)
							{
								inDegree[prerequisites[j].first]--;
							}
						}
						break;
					}
				}
				if (!findOne)
				{
					return false;
				}
			}
		}
		return can;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Minimum Size Subarray Sum */
class Solution113 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		int start = 0;
		int end = -1;
		int sum = 0;
		int minLen = len + 1;
		while (end < len)
		{
			while (end < len && sum < s)
			{
				end++;
				sum += nums[end];
			}
			if (sum >= s)
			{
				minLen = end - start + 1 < minLen ? end - start + 1 : minLen;
				sum -= nums[start];
				start++;
			}
		}
		return minLen > len ? 0 : minLen;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Zigzag Level Order Traversal*/
class Solution112 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root)
		{
			queue<TreeNode*> qu;
			qu.push(root);
			vector<int> layer;
			int iCurLayerCnt = 1;
			int iNextLayerCnt = 0;
			int visitedCnt = 0;
			bool isReversed = true;
			while (!qu.empty())
			{
				TreeNode* curNode = qu.front();
				qu.pop();
				layer.push_back(curNode->val);
				visitedCnt++;
				if (curNode->left)
				{
					qu.push(curNode->left);
					iNextLayerCnt++;
				}
				if (curNode->right)
				{
					qu.push(curNode->right);
					iNextLayerCnt++;
				}
				if (visitedCnt == iCurLayerCnt)
				{
					result.push_back(layer);
					layer.clear();
					visitedCnt = 0;
					iCurLayerCnt = iNextLayerCnt;
					iNextLayerCnt = 0;
				}
			}
			for (size_t i = 1; i < result.size(); i += 2)
			{
				reverse(result[i].begin(), result[i].end());
			}
		}
		return result;
	}
};

/*
vector<TreeNode*> levelNode;
vector<int> layer;
int curLayer = 0;
int index = 0;
queue<TreeNode*> qu;
qu.push(root);
levelNode.push_back(root);
layer.push_back(curLayer);
while (!qu.empty())
{
TreeNode* curNode = qu.front();
qu.pop();
curLayer = layer[index];
if (curNode->left)
{
qu.push(curNode->left);
levelNode.push_back(curNode->left);
layer.push_back(curLayer + 1);
}
if (curNode->right)
{
qu.push(curNode->right);
levelNode.push_back(curNode->right);
layer.push_back(curLayer + 1);
}
index++;
}
for (size_t i = 0; i < levelNode.size(); )
{
vector<int> vec;
for (size_t j = i; j < levelNode.size(); j++)
{
if (layer[i] == layer[j])
{
vec.push_back(levelNode[j]->val);
if (levelNode.size()-1==j)
{
i = levelNode.size();
break;
}
}
else
{
i = j;
break;
}
}
result.push_back(vec);
}
for (size_t i = 1; i < result.size(); i+=2)
{
reverse(result[i].begin(),result[i].end());
}
*/
/*-------------------------------------------------------------------------------------*/
/*Binary Search Tree Iterator */
class BSTIterator {
public:
	stack<TreeNode *> st;
	void ReverseInOrderTraverse(TreeNode *root)
	{

		if (root)
		{
			if (root->right)
			{
				ReverseInOrderTraverse(root->right);
			}
			st.push(root);
			if (root->left)
			{
				ReverseInOrderTraverse(root->left);
			}
		}
	}
	BSTIterator(TreeNode *root) {
		ReverseInOrderTraverse(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		if (!st.empty())
		{
			int result = st.top()->val;
			st.pop();
			return result;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Construct Binary Tree from Inorder and Postorder Traversal */
class Solution111 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return Build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd)
	{
		if (postStart > postEnd || inStart > inEnd)
		{
			return NULL;
		}
		TreeNode* parent = new TreeNode(postorder[postEnd]);
		int index = inStart;
		for (; index <= inEnd; index++)
		{
			if (postorder[postEnd] == inorder[index])
			{
				break;
			}
		}
		parent->left = Build(inorder, postorder, inStart, index - 1, postStart, postEnd - inEnd + index - 1);
		parent->right = Build(inorder, postorder, index + 1, inEnd, postEnd - inEnd + index, postEnd - 1);
		return parent;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Construct Binary Tree from Preorder and Inorder Traversal*/
class Solution110 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		return Build(preorder, inorder, 0, len - 1, 0, len - 1);
	}

	TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd)
	{
		if (preStart > preEnd || inStart > inEnd)
		{
			return NULL;
		}
		TreeNode* parent = new TreeNode(preorder[preStart]);
		int index = inStart;
		for (; index <= inEnd; index++)
		{
			if (preorder[preStart] == inorder[index])
			{
				break;
			}
		}
		parent->left = Build(preorder, inorder, preStart + 1, preStart + index - inStart, inStart, index - 1);
		parent->right = Build(preorder, inorder, preStart + index - inStart + 1, preEnd, index + 1, inEnd);
		return parent;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Convert Sorted Array to Binary Search Tree */
class Solution109 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return BuildBST(nums, 0, nums.size() - 1);
	}

	TreeNode* BuildBST(vector<int> &num, int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}
		if (start == end)
		{
			return new TreeNode(num[start]);
		}
		int mid = start + (end - start) / 2;
		TreeNode* parent = new TreeNode(num[mid]);
		parent->left = BuildBST(num, start, mid - 1);
		parent->right = BuildBST(num, mid + 1, end);
		return parent;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Convert Sorted List to Binary Search Tree */
class Solution108 {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		int len = 0;
		ListNode *p = head;
		while (p)
		{
			len++;
			p = p->next;
		}
		return BuildBST(head, 0, len - 1);
	}
	TreeNode* BuildBST(ListNode*& list, int start, int end)
	{
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode *leftChild = BuildBST(list, start, mid - 1);
		TreeNode *parent = new TreeNode(list->val);
		parent->left = leftChild;
		list = list->next;
		parent->right = BuildBST(list, mid + 1, end);
		return parent;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Path Sum II*/
class Solution107 {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> solution;
		if (root)
		{
			GetPath(result, solution, root, 0, sum);
		}
		return result;
	}

	void GetPath(vector<vector<int>> &result, vector<int>& solution, TreeNode* root, int sum, int target)
	{
		solution.push_back(root->val);
		if (root->left == NULL&&root->right == NULL)
		{
			if (root->val + sum == target)
			{
				result.push_back(solution);
			}
		}
		if (root->left)
		{
			GetPath(result, solution, root->left, sum + root->val, target);
		}
		if (root->right)
		{
			GetPath(result, solution, root->right, sum + root->val, target);
		}
		solution.erase(solution.end() - 1);
	}
};
/*
TreeNode* T1 = new TreeNode(5);
TreeNode* T2 = new TreeNode(4);
TreeNode* T3 = new TreeNode(8);
TreeNode* T4 = new TreeNode(11);
TreeNode* T5 = new TreeNode(13);
TreeNode* T6 = new TreeNode(4);
TreeNode* T7 = new TreeNode(7);
TreeNode* T8 = new TreeNode(2);
TreeNode* T9 = new TreeNode(5);
TreeNode* T10 = new TreeNode(1);
T1->left = T2;
T1->right = T3;
T2->left = T4;
T3->left = T5;
T3->right = T6;
T4->left = T7;
T4->right = T8;
T6->left = T9;
T6->right = T10;
Solution107 SU107;
SU107.pathSum(T1,22);
*/
/*-------------------------------------------------------------------------------------*/
/*Flatten Binary Tree to Linked List */
class Solution106 {
public:
	void flatten(TreeNode* root) {
		vector<TreeNode*> vecList;
		if (root)
		{
			PreOrderTraverse(root, vecList);
			for (size_t i = 0; i < vecList.size() - 1; i++)
			{
				vecList[i]->left = NULL;
				vecList[i]->right = vecList[i + 1];
			}
			vecList[vecList.size() - 1]->right = NULL;
		}
	}

	void PreOrderTraverse(TreeNode* root, vector<TreeNode*> &vecList)
	{
		vecList.push_back(root);
		if (root->left)
		{
			PreOrderTraverse(root->left, vecList);
		}
		if (root->right)
		{
			PreOrderTraverse(root->right, vecList);
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Clone Graph*/
class Solution105 {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
		queue<UndirectedGraphNode *> visit;
		visit.push(node);
		UndirectedGraphNode * nodeCopy = new UndirectedGraphNode(node->label);
		nodeMap[node] = nodeCopy;
		while (visit.size() > 0)
		{
			UndirectedGraphNode * cur = visit.front();
			visit.pop();
			for (int i = 0; i < cur->neighbors.size(); ++i)
			{
				UndirectedGraphNode * neighb = cur->neighbors[i];
				if (nodeMap.find(neighb) == nodeMap.end())
				{
					// no copy of neighbor node yet. create one and associate with the copy of cur
					UndirectedGraphNode* neighbCopy = new UndirectedGraphNode(neighb->label);
					nodeMap[cur]->neighbors.push_back(neighbCopy);
					nodeMap[neighb] = neighbCopy;
					visit.push(neighb);
				}
				else
				{
					// already a copy there. Associate it with the copy of cur
					nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
				}
			}
		}

		return nodeCopy;
	}
	//UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	//	set<UndirectedGraphNode*> all;
	//	return Clone(node, NULL,all);
	//}

	//UndirectedGraphNode* Clone(UndirectedGraphNode *node, UndirectedGraphNode *newNode, set<UndirectedGraphNode*> &all)
	//{
	//	if (node)
	//	{
	//		if (newNode==NULL)
	//		{
	//			newNode = new UndirectedGraphNode(node->label);
	//			all.insert(newNode);
	//		}
	//		for (size_t i = 0; i < node->neighbors.size(); i++)
	//		{
	//			auto result = all.find(node->neighbors[i]);
	//			if (result == all.end())
	//			{
	//				UndirectedGraphNode *newNeighbour = new UndirectedGraphNode(node->neighbors[i]->label);
	//				all.insert(newNeighbour);
	//				newNode->neighbors.push_back(newNeighbour);
	//				Clone(node->neighbors[i], newNeighbour,all);
	//			}
	//			else
	//			{
	//				newNode->neighbors.push_back(*result);
	//				continue;
	//			}
	//		}
	//		return newNode;
	//	}
	//	else
	//	{
	//		return NULL;
	//	}
	//}
};
/*-------------------------------------------------------------------------------------*/
/*Unique Binary Search Trees*/
class Solution104 {
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
/*Reverse Integer*/
class Solution103 {
public:
	int reverse(int x) {
		int sign = 1;
		if (x < 0)
		{
			sign = -1;
			x = -x;
		}
		long sum = 0;
		while (x)
		{
			sum *= 10;
			sum += (x % 10);
			x = x / 10;
		}
		sum = sum*sign;
		if (sum > INT_MAX || sum < INT_MIN)
		{
			sum = 0;
		}
		return sum;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Maximum Subarray */
class Solution102 {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len != 0)
		{
			int MaxSum = nums[0];
			int sum = 0;
			for (size_t i = 0; i < len; i++)
			{
				if (sum >= 0)
				{
					sum += nums[i];
				}
				else
				{
					sum = nums[i];
				}
				if (sum > MaxSum)
				{
					MaxSum = sum;
				}
			}
			return MaxSum;
		}
		else
		{
			return 0;
		}
	}
};
/*
vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
Solution102 SU102;
SU102.maxSubArray(vec);
*/
/*-------------------------------------------------------------------------------------*/
/*Populating Next Right Pointers in Each Node*/
class Solution101 {
public:
	void connect(TreeLinkNode *root) {
		ConnectNode(root);
	}
	void ConnectNode(TreeLinkNode *root)
	{
		if (root != NULL)
		{
			if (root->left != NULL&&root->right != NULL)
			{
				root->left->next = root->right;
			}
			else
			{
				return;
			}
			if (root->left->left != NULL)
			{
				ConnectLeftRight(root->left, root->right);
				ConnectNode(root->left);
				ConnectNode(root->right);
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	void ConnectLeftRight(TreeLinkNode *pLeft, TreeLinkNode *pRight)
	{
		while (pLeft->right&&pRight->left)
		{
			pLeft = pLeft->right;
			pRight = pRight->left;
			pLeft->next = pRight;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Reverse Linked List*/
class Solution100 {
public:
	ListNode* reverseList(ListNode* head) {
		stack<ListNode*> stList;
		ListNode* pCur = head;
		ListNode* pNewHead = NULL;
		while (pCur)
		{
			stList.push(pCur);
			pCur = pCur->next;
		}
		if (!stList.empty())
		{
			pNewHead = stList.top();
			pCur = pNewHead;
			stList.pop();
			while (!stList.empty())
			{
				pCur->next = stList.top();
				pCur = stList.top();
				stList.pop();
			}
			pCur->next = NULL;
		}
		return pNewHead;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Permutations */
class Solution99 {
public:

	vector<vector<int> > permute(vector<int>& nums) {
		int N = nums.size();
		vector<int> solution;
		vector<vector<int> > result;
		vector<bool> isVisited(N, false);
		for (size_t i = 0; i < N; i++)
		{
			GetPremu(result, nums, solution, isVisited, i);
		}
		return result;
		//vector<vector<int> > result;
		//sort(nums.begin(),nums.end());
		//result.push_back(nums);
		//while (next_permutation(nums.begin(),nums.end()))
		//{
		//	result.push_back(nums);
		//}
		//return result;
	}

	void GetPremu(vector<vector<int> > &result, vector<int>& nums, vector<int> &solution, vector<bool> &isVisited, int index)
	{
		isVisited[index] = true;
		solution.push_back(nums[index]);
		if (solution.size() == nums.size())
		{
			result.push_back(solution);
			isVisited[index] = false;
			solution.erase(solution.end() - 1);
			return;
		}
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (!isVisited[i])
			{
				GetPremu(result, nums, solution, isVisited, i);
			}
		}
		isVisited[index] = false;
		solution.erase(solution.end() - 1);
	}
};
/*
Solution99 SU99;
vector<int> vec = { 0,-1,1 };
SU99.permute(vec);
*/
/*-------------------------------------------------------------------------------------*/
/*Rotate Image*/
class Solution98 {
public:
	void rotate(vector<vector<int> > &matrix) {
		int N = matrix.size();
		if (N > 0)
		{
			vector<vector<int> > tmp(N, vector<int>(N, 0));
			for (size_t i = 0; i < N; i++)
			{
				int k = N - i - 1;
				for (size_t j = 0; j < N; j++)
				{
					tmp[j][k] = matrix[i][j];
				}
			}

			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					matrix[i][j] = tmp[i][j];
				}
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Pow(x, n) */
class Solution97 {
public:
	double myPow(double x, int n) {
		if (n < 0) {
			return 1.0 / pow(x, -n);
		}
		else {
			return pow(x, n);
		}
	}
	double pow(double x, int n) {
		if (n == 0)
			return 1;

		double v = pow(x, n / 2);

		if (n % 2 == 0) {
			return v * v;
		}
		else {
			return v * v * x;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Best Time to Buy and Sell Stock III*/
class Solution96 {
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
/*Best Time to Buy and Sell Stock II*/
class Solution95 {
public:
	int maxProfit(vector<int> &prices) {
		int len = prices.size();
		if (len <= 1)return 0;
		int i = 0;
		int res = 0;
		while (i < len - 1)
		{
			int buy, sell;
			while (i + 1 < len && prices[i + 1] < prices[i])i++;
			buy = i;
			while (i + 1 < len && prices[i + 1] >= prices[i])i++;
			sell = i;
			res += prices[sell] - prices[buy];
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Best Time to Buy and Sell Stock */
class Solution94 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int profit;
		if (len > 0)
		{
			int minValue = prices[0];
			int result = prices[1] - prices[0];
			for (size_t i = 2; i < len; i++)
			{
				minValue = min(prices[i - 1], minValue);
				if (prices[i] - minValue > result)
				{
					result = prices[i] - minValue;
				}
			}
			if (result < 0)
			{
				return 0;
			}
			return result;
		}
		return 0;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Fraction to Recurring Decimal */
class Solution93 {
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
/*
Solution93 SU93;
SU93.fractionToDecimal(INT_MIN, 1);
*/
/*-------------------------------------------------------------------------------------*/
/*Isomorphic Strings */
class Solution92 {
public:
	bool isIsomorphic(string s, string t) {
		int len1 = s.size();
		int len2 = t.size();
		if (len1 != len2)
		{
			return false;
		}
		map<char, char> table;
		for (size_t i = 0; i < len1; i++)
		{
			if (table.find(s[i]) == table.end())
			{
				table[s[i]] = t[i];
			}
			else
			{
				if (table[s[i]] != t[i])
				{
					return false;
				}
			}
		}
		table.clear();
		for (size_t i = 0; i < len1; i++)
		{
			if (table.find(t[i]) == table.end())
			{
				table[t[i]] = s[i];
			}
			else
			{
				if (table[t[i]] != s[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};
/*
Solution92 SU92;
bool res;
res=SU92.isIsomorphic("egg", "add");
res=SU92.isIsomorphic("foo", "bar");
res = SU92.isIsomorphic("paper", "title");
res = SU92.isIsomorphic("ab", "aa");
*/
/*-------------------------------------------------------------------------------------*/
/*Rotate List*/
class Solution91 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
		{
			return NULL;
		}
		int len = 0;
		ListNode* pCur = head;
		ListNode* pNewHead = head;
		while (pCur)
		{
			len++;
			pCur = pCur->next;
		}
		pCur = head;
		k %= len;
		if (k == 0)
		{
			return head;
		}
		while (k--)
		{
			pCur = pCur->next;
		}
		while (pCur->next)
		{
			pNewHead = pNewHead->next;
			pCur = pCur->next;
		}
		ListNode* res = pNewHead->next;
		pNewHead->next = NULL;
		pCur->next = head;
		return res;
	}
};
/*
Solution91 SU88;
ListNode* head = new ListNode(1);
ListNode* L2 = new ListNode(2);
//ListNode* L3 = new ListNode(3);
//ListNode* L4 = new ListNode(4);
//ListNode* L5 = new ListNode(5);
head->next = L2;
//L2->next = L3;
//L3->next = L4;
//L4->next = L5;
SU88.rotateRight(head,1);
*/
/*-------------------------------------------------------------------------------------*/
/*SQRT*/
class Solution90 {
public:
	int mySqrt(int x) {
		long long i = 0;
		long long j = x / 2 + 1;
		while (i <= j)
		{
			long long mid = (i + j) / 2;
			long long sq = mid * mid;
			if (sq == x) return mid;
			else if (sq < x) i = mid + 1;
			else j = mid - 1;
		}
		return j;
	}
};
/*-------------------------------------------------------------------------------------*/
/*4Sum*/
class Solution89 {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4)
			return result;

		sort(num.begin(), num.end());
		int lastVi = num[0] - 1;
		for (int i = 0; i < num.size() - 3; ++i)
		{
			int vi = num[i];
			if (vi == lastVi)
				continue;
			lastVi = vi;

			int lastVj = num[i + 1] - 1;
			for (int j = i + 1; j < num.size() - 2; ++j)
			{
				int vj = num[j];
				if (vj == lastVj)
					continue;
				lastVj = vj;

				int lastVk = num[j + 1] - 1;
				for (int k = j + 1; k < num.size() - 1; ++k)
				{
					int vk = num[k];
					if (vk == lastVk)
						continue;
					lastVk = vk;

					int sum3 = vi + vj + vk;
					int tarVl = target - sum3;//find this for last num
					int si = k + 1, ei = num.size() - 1;
					//没有这个判断的话会超时
					if (num[si] > tarVl || num[ei] < tarVl)
						continue;
					while (si <= ei)
					{
						int mi = (si + ei) / 2;
						int vl = num[mi];
						if (vl == tarVl)
						{
							vector<int> quad;
							quad.push_back(vi);
							quad.push_back(vj);
							quad.push_back(vk);
							quad.push_back(vl);
							result.push_back(quad);
							break;
						}
						else if (vl > tarVl)
						{
							ei = mi - 1;
						}
						else
						{
							si = mi + 1;
						}
					}

				}//end k
			}//end j
		}//end i
		return result;

	}//end function
};
/*-------------------------------------------------------------------------------------*/
/*Largest Number */
class Solution88 {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.size() > 0)
		{
			vector<string> vec;
			for (size_t i = 0; i < nums.size(); i++)
			{
				vec.push_back(to_string(nums[i]));
			}
			sort(vec.begin(), vec.end(), MyCmp);
			string result = "";
			for (int i = 0; i < vec.size(); i++)
			{
				result += vec[i];
			}
			if (result[0] == '0'&&result.size() > 0)
			{
				result = "0";
			}
			return result;
		}
		return "0";
	}
	static bool MyCmp(string s1, string s2)
	{
		return s1 + s2 > s2 + s1;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Bitwise AND of Numbers Range */
class Solution87 {
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
/*Word Search*/
class Solution86 {
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
		if (!(word[index] == board[i][j]))
		{
			isVisited[i][j] = false;
			return false;
		}
		if (index == word.size() - 1)
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
/*
Solution86 SU86;
vector<vector<char> > vec = { vector<char>{'A', 'B', 'C', 'E'}, vector<char>{'S', 'F', 'C', 'S'}, vector<char>{'A','D','E','E'}};
string str1 = "ABCCED";
string str2 = "SEE";
string str3 = "ABCB";
bool result;
result=SU86.exist(vec, str1);
result=SU86.exist(vec, str2);
result=SU86.exist(vec, str3);
*/
/*-------------------------------------------------------------------------------------*/
/*Reverse Words in a String*/
class Solution85 {
public:
	void reverseWords(string &s) {
		vector<string> vecStr;
		istringstream ss(s);
		string str;
		while (ss >> str)
		{
			vecStr.push_back(str);
		}
		s = "";
		reverse(vecStr.begin(), vecStr.end());
		int len = vecStr.size();
		for (int i = 0; i < len - 1; i++)
		{
			s += vecStr[i] + " ";
		}
		if (len != 0)
		{
			s += vecStr[vecStr.size() - 1];
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Happy Number */
class Solution84 {
public:
	bool isHappy(int n) {
		if (n <= 0)
		{
			return false;
		}
		set<int> allSum;
		int squareSum = GetSquareSum(n);
		while (squareSum != 1)
		{
			if (allSum.find(squareSum) != allSum.end())
			{
				return false;
			}
			allSum.insert(squareSum);
			squareSum = GetSquareSum(squareSum);
		}
		return true;
	}

	int GetSquareSum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		return sum;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Linked List Elements */
class Solution83 {
public:
	ListNode* removeElements(ListNode* head, int val) {
		vector<ListNode*> newList;
		if (head != NULL)
		{
			ListNode* pCur = head;
			while (pCur != NULL)
			{
				if (pCur->val != val)
				{
					newList.push_back(pCur);
				}
				pCur = pCur->next;
			}
			if (newList.size() == 0)
			{
				return NULL;
			}
			newList[newList.size() - 1]->next = NULL;
			head = newList[0];
			pCur = head;
			for (size_t i = 1; i < newList.size(); i++)
			{
				pCur->next = newList[i];
				pCur = newList[i];
			}
		}
		return head;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Count Primes*/
class Solution82 {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n + 1, true);
		isPrime[0] = false;
		isPrime[1] = false;
		int dSqrt = sqrt(n);
		for (size_t index = 2; index <= dSqrt; index++)
		{
			if (isPrime[index])
			{
				for (size_t j = index + index; j <= n; j += index)
				{
					isPrime[j] = false;
				}
			}
		}
		int nCount = 0;
		for (size_t i = 0; i <= n; i++)
		{
			nCount += isPrime[i];
		}
		return nCount;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Linked List Cycle II*/
class Solution81 {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* pFast = head;
		ListNode* pSlow = head;
		while (pFast&&pFast->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pFast == pSlow)
			{
				break;
			}
		}
		if (pFast == NULL || pFast->next == NULL)
		{
			return NULL;
		}
		pFast = head;
		while (pFast != pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Linked List Cycle*/
class Solution80 {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
		{
			return false;
		}
		ListNode* pFast = head;
		ListNode* pSlow = head;
		while (pFast&&pFast->next)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pFast == pSlow)
			{
				return true;
			}
		}
		return false;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Word Break*/
class Solution79 {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		s = '#' + s;
		int len = s.size();
		vector<bool> isOK(len, false);
		isOK[0] = true;
		for (size_t i = 1; i < len; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				isOK[i] = isOK[j] && (wordDict.find(s.substr(j + 1, i - j)) != wordDict.end());
				if (isOK[i])
				{
					break;
				}
			}
		}
		return isOK[len - 1];
	}
};
/*
Solution79 SU79;
SU79.wordBreak("bb", unordered_set < string > {"a", "b", "bbb", "bbbb"});
*/
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Right Side View*/
class Solution78 {
public:
	struct MyTreeNode
	{
		int level;
		TreeNode* node;
	};
	vector<int> rightSideView(TreeNode *root) {
		vector<int> result;
		vector<MyTreeNode*> visitSeq;
		queue<MyTreeNode*> qT;
		if (root == NULL)
		{
			return result;
		}
		MyTreeNode* mtn = new MyTreeNode();
		mtn->level = 1;
		mtn->node = root;
		qT.push(mtn);
		while (!qT.empty())
		{
			visitSeq.push_back(qT.front());
			if (qT.front()->node->left != NULL)
			{
				MyTreeNode* mtnLeft = new MyTreeNode();
				mtnLeft->level = qT.front()->level + 1;
				mtnLeft->node = qT.front()->node->left;
				qT.push(mtnLeft);
			}
			if (qT.front()->node->right != NULL)
			{
				MyTreeNode* mtnRight = new MyTreeNode();
				mtnRight->level = qT.front()->level + 1;
				mtnRight->node = qT.front()->node->right;
				qT.push(mtnRight);
			}
			qT.pop();
		}
		result.push_back(visitSeq[0]->node->val);
		for (size_t i = 1; i < visitSeq.size(); i++)
		{
			if (visitSeq[i]->level != visitSeq[i - 1]->level)
			{
				result.push_back(visitSeq[i]->node->val);
			}
			else
			{
				result[result.size() - 1] = visitSeq[i]->node->val;
			}
		}
		return result;
	}
};
/*
TreeNode* root = new TreeNode(1);
TreeNode* T1 = new TreeNode(2);
TreeNode* T2 = new TreeNode(3);
TreeNode* T3 = new TreeNode(4);
TreeNode* T4 = new TreeNode(5);
root->left = T1;
root->right = T2;
T1->right = T3;
T2->right = T4;
Solution78 SU78;
SU78.rightSideView(root);
*/
/*-------------------------------------------------------------------------------------*/
/*Number of Islands */
class Solution77 {
public:
	int count = 0;
	int numIslands(vector<vector<char>> &grid) {
		int M = grid.size();
		if (M == 0)
		{
			return 0;
		}
		int N = grid[0].size();
		if (N == 0)
		{
			return 0;
		}
		vector<vector<int> > visited(M, vector<int>(N, 0));
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (grid[i][j] == '1'&&visited[i][j] == 0)
				{
					dfs(grid, visited, i, j);
					count++;
				}
			}
		}
		return count;
	}
	void dfs(vector<vector<char>> &grid, vector<vector<int> > &visited, int x, int y)
	{
		visited[x][y] = 1;
		if (y - 1 >= 0 && grid[x][y - 1] == '1'&&visited[x][y - 1] == 0)
		{
			dfs(grid, visited, x, y - 1);
		}
		if (y + 1 < grid[0].size() && grid[x][y + 1] == '1'&&visited[x][y + 1] == 0)
		{
			dfs(grid, visited, x, y + 1);
		}
		if (x - 1 >= 0 && grid[x - 1][y] == '1'&&visited[x - 1][y] == 0)
		{
			dfs(grid, visited, x - 1, y);
		}
		if (x + 1 < grid.size() && grid[x + 1][y] == '1'&&visited[x + 1][y] == 0)
		{
			dfs(grid, visited, x + 1, y);
		}
	}
};
/*
Solution77 SU77;
SU77.numIslands(vector < vector<char> > {
vector < char > {'1', '1', '0', '0', '0'},
vector < char > {'1', '1', '0', '0', '0'},
vector < char > {'0', '0', '1', '0', '0'},
vector < char > {'0', '0', '0', '1', '1'}
});
*/
/*-------------------------------------------------------------------------------------*/
/*House Robber */
class Solution76 {
public:
	int rob(vector<int> &num) {
		int length = num.size();
		if (length <= 0)
		{
			return 0;
		}
		if (length == 1)
		{
			return num[0];
		}
		vector<int> dpRob(length, 0);
		dpRob[0] = num[0];
		dpRob[1] = num[0] > num[1] ? num[0] : num[1];
		for (int i = 2; i < length; i++)
		{
			dpRob[i] = dpRob[i - 2] + num[i] > dpRob[i - 1] ? dpRob[i - 2] + num[i] : dpRob[i - 1];
		}
		return dpRob[length - 1];
	}
};
/*-------------------------------------------------------------------------------------*/
/*Triangle*/
class Solution75 {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		if (row == 0) return 0;
		vector<int> minV(triangle[row - 1].size());
		for (int i = row - 1; i >= 0; i--)
		{
			int col = triangle[i].size();
			for (int j = 0; j < col; j++)
			{
				if (i == row - 1)
				{
					minV[j] = triangle[i][j];
					continue;
				}
				minV[j] = min(minV[j], minV[j + 1]) + triangle[i][j];
			}
		}
		return minV[0];
	}
	/*
	int minResult=INT_MAX;
	int minimumTotal(vector<vector<int> > &triangle) {
	int len = triangle.size();
	GetSum(triangle, 0, 0, 0);
	return minResult;
	}
	void GetSum(vector<vector<int> > &triangle, int level, int index,int partSum)
	{
	if (level == triangle.size()-1)
	{
	if (partSum + triangle[level][index]<minResult)
	{
	minResult = partSum + triangle[level][index];
	}
	if (index + 1 < triangle[level].size())
	{
	if (partSum + triangle[level][index+1]<minResult)
	{
	minResult = partSum + triangle[level][index+1];
	}
	}
	return;
	}
	GetSum(triangle, level + 1, index, partSum + triangle[level][index]);
	if (index + 1<triangle[level].size())
	{
	GetSum(triangle, level + 1, index + 1, partSum + triangle[level][index + 1]);
	}
	}
	*/
	/*
	Solution75 SU75;
	vector<vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	int result=SU75.minimumTotal(triangle);
	*/
};
/*-------------------------------------------------------------------------------------*/
/*Word Ladder */
class Solution74 {
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
/*Palindrome Partitioning */
class Solution73 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> output;
		DFS(s, 0, output, result);
		return result;
	}
	void DFS(string &s, int start, vector<string>& output, vector<vector<string>> &result)
	{
		if (start == s.size())
		{
			result.push_back(output);
			return;
		}
		for (int i = start; i < s.size(); i++)
		{
			if (isPalindrome(s, start, i))
			{
				output.push_back(s.substr(start, i - start + 1));
				DFS(s, i + 1, output, result);
				output.pop_back();
			}
		}
	}
	bool isPalindrome(string &s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			start++; end--;
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Duplicates from Sorted Array II */
class Solution72 {
public:
	int removeDuplicates(int A[], int n) {
		int curNum = A[0];
		int curCount = 1;
		for (size_t i = 1; i < n; i++)
		{
			if (curCount == 2)
			{
				if (curNum == A[i])
				{
					A[i] = INT_MAX;
				}
				else
				{
					curNum = A[i];
					curCount = 1;
				}
			}
			else
			{
				if (curNum == A[i])
				{
					curCount++;
				}
				else
				{
					curNum = A[i];
					curCount = 1;
				}
			}
		}
		int index = 0;
		int count = n;
		for (size_t i = 0; i < n; i++)
		{
			if (A[i] != INT_MAX)
			{
				A[index] = A[i];
				index++;
			}
			else
			{
				count--;
			}
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Longest Substring Without Repeating Characters*/
class Solution71 {
public:
	int lengthOfLongestSubstring(string s) {
		int hash[256];
		for (int i = 0; i < 256; i++) hash[i] = -1;
		int start = 0, ans = 0;
		int i;
		for (i = 0; i < s.size(); i++){
			if (-1 != hash[s[i]]){
				if (ans < i - start) ans = i - start;
				for (int j = start; j<hash[s[i]]; j++) hash[j] = -1;
				if (hash[s[i]] + 1  > start)
					start = hash[s[i]] + 1;
			}
			hash[s[i]] = i;
		}
		if (ans < i - start) ans = i - start;
		return ans;
	}
};


/*-------------------------------------------------------------------------------------*/
/*Surrounded Regions */
class Solution70 {
public:
	vector<int> xIndex;
	vector<int> yIndex;
	void solve(vector<vector<char>> &board) {
		int row = board.size();
		if (row == 0) return;
		int col = board[0].size();
		xIndex.clear();
		yIndex.clear();
		for (int i = 0; i < row; i++)
		{
			if (board[i][0] == 'O')
			{
				xIndex.push_back(i);
				yIndex.push_back(0);
			}
			if (board[i][col - 1] == 'O')
			{
				xIndex.push_back(i);
				yIndex.push_back(col - 1);
			}
		}
		for (int i = 0; i < col; i++)
		{
			if (board[0][i] == 'O')
			{
				xIndex.push_back(0);
				yIndex.push_back(i);
			}
			if (board[row - 1][i] == 'O')
			{
				xIndex.push_back(row - 1);
				yIndex.push_back(i);
			}
		}
		int k = 0;
		while (k < xIndex.size())
		{
			int x = xIndex[k];
			int y = yIndex[k];
			board[x][y] = 'Y';
			if (x > 0 && board[x - 1][y] == 'O') { xIndex.push_back(x - 1); yIndex.push_back(y); }
			if (x < row - 1 && board[x + 1][y] == 'O') { xIndex.push_back(x + 1); yIndex.push_back(y); }
			if (y > 0 && board[x][y - 1] == 'O') { xIndex.push_back(x); yIndex.push_back(y - 1); }
			if (y < col - 1 && board[x][y + 1] == 'O') { xIndex.push_back(x); yIndex.push_back(y + 1); }
			k++;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == 'Y') board[i][j] = 'O';
			}
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*3Sum Closest*/
class Solution69 {
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
/*Gas Station*/
class Solution68 {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int len = gas.size();
		vector<int> vec;
		for (int i = 0; i < len; i++)
		{
			vec.push_back(gas[i] - cost[i]);
		}
		int sum = 0;
		int leftGas = 0;
		int start = 0;
		for (int i = 0; i < len; i++)
		{
			leftGas += vec[i];
			sum += vec[i];
			if (sum < 0)
			{
				sum = 0;
				start = i + 1;
			}
		}
		if (leftGas < 0)
		{
			return -1;
		}
		else
		{
			return start;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*3Sum*/
class Solution67 {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		if (num.size() < 3) return ret;

		sort(num.begin(), num.end());

		for (int i = 0; i < num.size() - 2; ++i) {
			if (i > 0 && num[i] == num[i - 1]) continue;
			for (int j = i + 1; j < num.size() - 1; ++j) {
				if (j > i + 1 && num[j] == num[j - 1]) continue;
				int target = -(num[i] + num[j]);
				int ks = j + 1;
				int ke = num.size() - 1;
				if (target < num[ks] || target > num[ke]) continue;
				while (ks <= ke) {
					int km = (ks + ke) / 2;
					if (num[km] == target) {
						//found an triplet
						vector<int> tri(3, target);
						tri[0] = num[i];
						tri[1] = num[j];
						ret.push_back(tri);
						break;
					}
					else if (num[km] > target) {
						ke = km - 1;
					}
					else {
						ks = km + 1;
					}
				}
			}
		}

		return ret;
	}
};
/*
vector<int> num{ -1 ,0 ,1 ,2 ,-1, -4 };
Solution67 SU67;
SU67.threeSum(num);
*/
/*
class Solution67 {
public:
vector<vector<int> > threeSum(vector<int> &num) {
int length = num.size();
vector<vector<int> > result;
sort(num.begin(), num.end());
if (length>=3)
{
for (int i = 0; i < length; i++)
{
for (int j = i + 1; j < length; j++)
{
int k = j + 1;
int target = 0 - num[i] - num[j];
int left = k;
int right = length - 1;
int mid;
while (left<=right)
{
mid = (left + right) / 2;
if (num[mid]==target)
{
result.push_back(vector < int > {num[i] , num[j],target});
break;
}
else if (num[mid]<target)
{
left = mid+1;
}
else
{
right = mid - 1;
}
}
}
}
sort(result.begin(), result.end());
result.erase(unique(result.begin(),result.end()),result.end());
return result;
}
}
};
*/
/*-------------------------------------------------------------------------------------*/
/*Single Number */
class Solution66 {
public:
	int singleNumber(int A[], int n) {
		sort(A, A + n);

	}
};
/*-------------------------------------------------------------------------------------*/
/*Single Number II */
class Solution65 {
public:
	int singleNumber(int A[], int n) {
		map<int, bool> ump_ii;
		for (int i = 0; i < n; i++)
		{
			if (!ump_ii.count(A[i])) ump_ii[A[i]] = true;
			else ump_ii.erase(A[i]);
		}
		return ump_ii.begin()->first;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Reverse Bits*/
class Solution64 {
public:
	uint32_t reverseBits(uint32_t n) {
		bitset<32> bs(n);
		for (size_t i = 0; i < 16; i++)
		{
			int tmp = bs[i];
			bs[i] = bs[32 - i - 1];
			bs[32 - i - 1] = tmp;
		}
		return bs.to_ulong();
	}
};
/*
Solution64 SU64;
uint32_t tt = SU64.reverseBits(43261596);
*/
/*-------------------------------------------------------------------------------------*/
/*Rotate Array*/
class Solution63 {
public:
	void rotate(int nums[], int n, int k) {
		k = k%n;
		if (k > 0)
		{
			RotateAll(nums, 0, n - k - 1);
			RotateAll(nums, n - k, n - 1);
			RotateAll(nums, 0, n - 1);
		}
	}

	void RotateAll(int nums[], int start, int end)
	{
		int mid = (end + start) / 2;
		for (int i = start; i <= mid; i++)
		{
			int tmp = nums[i];
			nums[i] = nums[end - i + start];
			nums[end - i + start] = tmp;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Number of 1 Bits*/
class Solution62 {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n > 0)
		{
			if (n & 1 == 1)
			{
				count++;
			}
			n >>= 1;
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Letter Combinations of a Phone Number */
class Solution61 {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> strArray = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res(1, "");
		for (int i = 0; i < digits.size(); i++)
		{
			vector<string> tmp;
			for (int j = 0; j < res.size(); j++)
			{
				for (int k = 0; k < strArray[digits[i] - '0'].size(); k++)
				{
					tmp.push_back(res[j] + strArray[digits[i] - '0'][k]);
				}
			}
			res = tmp;
		}
		return res;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Longest Palindromic Substring */
class Solution60 {
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

			//寻找以i为中心的奇数长度的回文
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
};
/*-------------------------------------------------------------------------------------*/
/*Sum Root to Leaf Numbers*/
class Solution59 {
public:
	int allSum = 0;
	int sumNumbers(TreeNode *root) {
		SumToRoot(root, 0);
		return allSum;
	}
	int SumToRoot(TreeNode* root, int sum)
	{
		if (root)
		{
			if (root->left == NULL&&root->right == NULL)
			{
				sum = sum + root->val;
				allSum += sum;
				return sum;
			}
			int lSum = 0;
			int rSum = 0;
			if (root->left)
			{
				lSum = SumToRoot(root->left, (sum + root->val) * 10);
			}
			if (root->right)
			{
				rSum = SumToRoot(root->right, (sum + root->val) * 10);
			}
			return lSum + rSum;
		}
		else
		{
			return 0;
		}
	}
};
/*
TreeNode* root = new TreeNode(1);
TreeNode* t1 = new TreeNode(2);
TreeNode* t2 = new TreeNode(3);
TreeNode* t3 = new TreeNode(4);
TreeNode* t4 = new TreeNode(5);
TreeNode* t5 = new TreeNode(6);
TreeNode* t6 = new TreeNode(7);
root->left = t1;
root->right = t2;
t1->left = t3;
t1->right = t4;
//t2->left = t5;
//t2->right = t6;
Solution59 SU59;
int result=SU59.sumNumbers(root);
*/
/*-------------------------------------------------------------------------------------*/
/*Add Two Numbers*/
class Solution58 {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int carry = 0;
		ListNode* head = p1;
		ListNode* p = head;
		while (p1&&p2)
		{
			int tmp = p1->val + p2->val + carry;
			p1->val = tmp % 10;
			carry = tmp / 10;
			p = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1&&carry)
		{
			int tmp = p1->val + carry;
			p1->val = tmp % 10;
			carry = tmp / 10;
			p = p1;
			p1 = p1->next;
		}
		while (p2)
		{
			if (carry != 0)
			{
				int tmp = p2->val + carry;
				p2->val = tmp % 10;
				carry = tmp / 10;
				p->next = p2;
				p = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p2;
				break;
			}

		}
		if (carry != 0)
		{
			ListNode* last = new ListNode(carry);
			p->next = last;
		}
		return head;
	}
};
/*
ListNode* l1 = new ListNode(0);
ListNode* l2 = new ListNode(7);
l2->next = new ListNode(3);
Solution58 SU58;
SU58.addTwoNumbers(l1, l2);
*/
/*-------------------------------------------------------------------------------------*/
/*Length of Last Word*/
class Solution57 {
public:
	int lengthOfLastWord(const char *s) {
		int len = strlen(s);
		if (len == 0)
		{
			return 0;
		}
		int end = len;
		int start = len;
		int index = len - 1;
		if (s[index] == ' ')
		{
			while (s[index] == ' '&&index >= 0)
			{
				end = index;
				index--;
			}
		}
		if (index < 0)
		{
			return 0;
		}
		while (s[index] != ' '&&index >= 0)
		{
			start = index;
			index--;
		}
		return  end - start;
	}
};
/*
Solution57 SU57;
int result=SU57.lengthOfLastWord("11");
*/
/*-------------------------------------------------------------------------------------*/
/*Merge Two Sorted Lists*/
class Solution56 {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode* head;
		ListNode* p;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		if (p1->val < p2->val)
		{
			head = p1;
			p1 = p1->next;
		}
		else
		{
			head = p2;
			p2 = p2->next;
		}
		p = head;
		while (p1&&p2)
		{
			if (p1->val < p2->val)
			{
				p->next = p1;
				p = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				p = p2;
				p2 = p2->next;
			}
		}
		if (p1)
		{
			p->next = p1;
		}
		if (p2)
		{
			p->next = p2;
		}
		return head;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Add Binary*/
class Solution55 {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int lenA = a.size();
		int lenB = b.size();
		int len = lenA;
		if (lenA > lenB)
		{
			len = lenA;
			for (int i = lenB; i < lenA; i++)
			{
				b.push_back('0');
			}
		}
		if (lenA < lenB)
		{
			len = lenB;
			for (int i = lenA; i < lenB; i++)
			{
				a.push_back('0');
			}
		}
		int carry = 0;
		string result;
		for (int i = 0; i < len; i++)
		{
			int tmp = (a[i] - '0') + (b[i] - '0') + carry;
			carry = tmp / 2;
			result.push_back(tmp % 2 + '0');
		}
		if (carry != 0)
		{
			result.push_back('0' + carry);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Plus One */
class Solution54 {
public:
	vector<int> plusOne(vector<int> &digits) {
		reverse(digits.begin(), digits.end());
		int len = digits.size();
		if (len > 0)
		{
			vector<int> result;
			result.push_back((digits[0] + 1) % 10);
			int carry = (digits[0] + 1) / 10;
			for (int i = 1; i < len; i++)
			{
				int tmp = digits[i] + carry;
				result.push_back(tmp % 10);
				carry = tmp / 10;
				if (carry == 0)
				{
					for (int j = i + 1; j < len; j++)
					{
						result.push_back(digits[j]);
					}
					break;
				}
			}
			if (carry != 0)
			{
				result.push_back(carry);
			}
			reverse(result.begin(), result.end());
			return result;
		}
	}
};
/*
Solution54 SU54;
vector<int> digits = {9,9};
SU54.plusOne(digits);
*/
/*-------------------------------------------------------------------------------------*/
/*Climbing Stairs */
class Solution53 {
public:
	int climbStairs(int n) {
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		vector<int> stair(n + 1, 0);
		stair[1] = 1;
		stair[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			stair[i] = stair[i - 2] + stair[i - 1];
		}
		return stair[n];
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Duplicates from Sorted List*/
class Solution52 {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head != NULL)
		{
			ListNode* p = head;
			int preNum = p->val;;
			ListNode* q = p->next;
			while (q)
			{
				while (q&&q->val == preNum)
				{
					q = q->next;
				}
				p->next = q;
				p = q;
				if (q != NULL)
				{
					preNum = q->val;
					q = q->next;
				}
			}
		}
		return head;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Element*/
class Solution51 {
public:
	int removeElement(int A[], int n, int elem) {
		int count = 0;
		if (n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (A[i] != elem)
				{
					A[count] = A[i];
					count++;
				}
			}
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Duplicates from Sorted Array */
class Solution50 {
public:
	int removeDuplicates(int A[], int n) {
		int count = 0;
		if (n > 0)
		{
			int preNum = INT_MAX;
			int index = -1;
			for (int i = 0; i < n; i++)
			{
				if (A[i] == preNum)
				{
					continue;
				}
				else
				{
					if (index == -1)
					{
						index = i;
					}
					A[index] = A[i];
					preNum = A[i];
					count++;
					index++;
				}
			}
		}
		return count;
	}
};
/*
int A[20] = {0,2,4,4,4,5,5,7,8};
Solution50 SU50;
SU50.removeDuplicates(A, 9);
*/
/*-------------------------------------------------------------------------------------*/
/*Merge Sorted Array*/
class Solution49 {
public:
	void merge(int A[], int m, int B[], int n) {
		int index = m + n - 1;
		if (m == 0)
		{
			while (n - 1 >= 0)
			{
				A[index] = B[n - 1];
				n--;
				index--;
			}
		}
		while (m - 1 >= 0 && n - 1 >= 0)
		{
			if (A[m - 1] > B[n - 1])
			{
				A[index] = A[m - 1];
				m--;
			}
			else
			{
				A[index] = B[n - 1];
				n--;
			}
			index--;
		}
		while (n - 1 >= 0)
		{
			A[index] = B[n - 1];
			n--;
			index--;
		}
	}
};
/*
int A[20] = {0,2,4,5,7,8};
int B[4] = {1,3,5,7};
Solution49 SU49;
SU49.merge(A, 6, B, 4);
*/
/*-------------------------------------------------------------------------------------*/
/*Same Tree*/
class Solution48 {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		return isSame(p, q);
	}
	bool isSame(TreeNode* r1, TreeNode* r2)
	{
		if (r1 == NULL&&r2 == NULL)
		{
			return true;
		}
		else if (r1 == NULL&&r2 != NULL || r1 != NULL&&r2 == NULL)
		{
			return false;
		}
		else
		{
			return (r1->val == r2->val)&isSame(r1->left, r2->left)&isSame(r1->right, r2->right);
		}
	}
};

/*-------------------------------------------------------------------------------------*/
/*Symmetric Tree*/
class Solution47 {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		return isSym(root->left, root->right);
	}
	bool isSym(TreeNode *left, TreeNode *right)
	{
		if (left == NULL)
			return right == NULL;
		if (right == NULL)
			return left == NULL;
		if (left->val != right->val)
			return false;
		if (!isSym(left->left, right->right))
			return false;
		if (!isSym(left->right, right->left))
			return false;
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Valid Parentheses*/
class Solution46 {
public:
	bool isValid(string s) {
		int len = s.size();
		if (len > 0)
		{
			stack<char> st;
			for (int i = 0; i < len; i++)
			{
				if (st.empty())
				{
					st.push(s[i]);
				}
				else
				{
					switch (st.top())
					{
					case '(':
					{
						if (s[i] == ')')
						{
							st.pop();
						}
						else
						{
							st.push(s[i]);
						}
						break;
					}
					case '{':
					{
						if (s[i] == '}')
						{
							st.pop();
						}
						else
						{
							st.push(s[i]);
						}
						break;
					}
					case '[':
					{
						if (s[i] == ']')
						{
							st.pop();
						}
						else
						{
							st.push(s[i]);
						}
						break;
					}
					default:
						st.push(s[i]);
						break;
					}
				}
			}
			return st.empty();
		}
		else
		{
			return true;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Nth Node From End of List*/
class Solution45 {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (!head)
		{
			return head;
		}
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p1->next&&n != 0)
		{
			p1 = p1->next;
			n--;
		}
		if (n == 1)
		{
			return head->next;
		}
		if (n > 1)
		{
			return head;
		}
		while (p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = p2->next->next;
		return head;
	}
};
/*
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
Solution45 SU45;
SU45.removeNthFromEnd(head, 1);
*/
/*-------------------------------------------------------------------------------------*/
/*Roman to Integer*/
class Solution44 {
public:
	inline int c2n(char c) {
		switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}

	int romanToInt(string s) {
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i>0 && c2n(s[i]) > c2n(s[i - 1]))
			{
				result += (c2n(s[i]) - 2 * c2n(s[i - 1]));
			}
			else
			{
				result += c2n(s[i]);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*isPalindrome*/
class Solution43 {
public:
	bool isPalindrome(int x) {
		if (x < 0)
		{
			return false;
		}
		int count = 0;
		int tmp = x;
		while (tmp != 0)
		{
			count++;
			tmp /= 10;
		}
		for (int i = count - 1; i > 0; i -= 2)
		{
			int left = x / pow(10, i);
			int right = x % 10;
			if (left != right)
			{
				return false;
			}
			x = x % (int)pow(10, i) / 10;
		}
		return true;
	}
};
/*
Solution43 SU43;
SU43.isPalindrome(1221);
*/
/*-------------------------------------------------------------------------------------*/
/*String to Integer (atoi) */
class Solution42 {
public:
	int atoi(const char *str) {
		long long tmpL = atoll(str);
		if (tmpL > INT_MAX)
		{
			return INT_MAX;
		}
		if (tmpL < INT_MIN)
		{
			return INT_MIN;
		}
		return tmpL;
		//return atoi(str);
	}
};
/*-------------------------------------------------------------------------------------*/
/*Binary Tree Level Order Traversal */
class Solution41 {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > result;
		if (root != NULL)
		{
			queue<TreeNode*> qu;
			qu.push(root);
			int count = 0;
			while (!qu.empty())
			{
				count = qu.size();
				vector<int> tmpVec;
				for (int i = 0; i < count; i++)
				{
					TreeNode* tmp = qu.front();
					tmpVec.push_back(tmp->val);
					qu.pop();
					if (tmp->left != NULL)
					{
						qu.push(tmp->left);
					}
					if (tmp->right != NULL)
					{
						qu.push(tmp->right);
					}
				}
				result.push_back(tmpVec);
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Minimum Depth of Binary Tree*/
class Solution40 {
public:
	int minDepth(TreeNode *root) {
		if (root != NULL)
		{
			queue<TreeNode*> qu;
			qu.push(root);
			int count = 0;
			int level = 0;
			while (!qu.empty())
			{
				count = qu.size();
				level++;
				for (int i = 0; i < count; i++)
				{
					TreeNode* tmp = qu.front();
					qu.pop();
					if (tmp->left != NULL)
					{
						qu.push(tmp->left);
					}
					if (tmp->right != NULL)
					{
						qu.push(tmp->right);
					}
					if (tmp->left == NULL&&tmp->right == NULL)
					{
						return level;
					}
				}
			}

		}
		else
		{
			return 0;
		}
	}
};
/*
TreeNode *root = new TreeNode(5);
TreeNode *c1 = new TreeNode(4);
TreeNode *c2 = new TreeNode(8);
TreeNode *c3 = new TreeNode(11);
TreeNode *c4 = new TreeNode(13);
TreeNode *c5 = new TreeNode(4);
TreeNode *c6 = new TreeNode(7);
TreeNode *c7 = new TreeNode(2);
TreeNode *c8 = new TreeNode(1);
root->left = c1;
root->right = c2;
c1->left = c3;
//c2->left = c4;
//c2->right = c5;
c3->left = c6;
c3->right = c7;
c4->right = c8;
Solution40 SU40;
SU40.minDepth(root);
*/
/*-------------------------------------------------------------------------------------*/
/*Path Sum*/
class Solution39 {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (root != NULL)
		{
			return equalSum(root, 0, sum);
		}
		else
		{
			return false;
		}
	}
	bool equalSum(TreeNode *root, int sum, int target)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			if (target == root->val + sum)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool lHasPath = false;
		if (root->left != NULL)
		{
			lHasPath = equalSum(root->left, root->val + sum, target);
		}
		if (lHasPath)
		{
			return true;
		}
		bool rHasPath = false;
		if (root->right != NULL)
		{
			rHasPath = equalSum(root->right, root->val + sum, target);
		}
		return rHasPath;
	}
};
/*
Solution39 SU39;
bool result=SU39.hasPathSum(root, 17);
*/
/*-------------------------------------------------------------------------------------*/
/*Pascal's Triangle II*/
class Solution38 {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex >= 0)
		{
			vector<int> result(rowIndex + 1, 0);
			result[0] = 1;
			int index = 0;
			while (index < rowIndex)
			{
				result[index + 1] = 1;
				for (int i = index; i >= 1; i--)
				{
					result[i] = result[i] + result[i - 1];
				}
				index++;
			}
			return result;
		}
	}
};
/*
Solution38 SU38;
SU38.getRow(3);
*/
/*-------------------------------------------------------------------------------------*/
/*Excel Sheet Column Number */
class Solution37 {
public:
	int titleToNumber(string s) {
		reverse(s.begin(), s.end());
		int len = s.size();
		int times = 1;
		int result = 0;
		for (int i = 0; i < len; i++)
		{
			result = result + (s[i] - 'A' + 1)*times;
			times *= 26;
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Factorial Trailing Zeroes */
class Solution36 {
public:
	int trailingZeroes(int n) {
		int count = 0;
		if (n >= 0)
		{
			for (int i = 5; i <= n; i += 5)
			{
				int j = i;
				int tmp = j % 5;
				while (tmp == 0)
				{
					count++;
					j /= 5;
					tmp = j % 5;
				}
			}
		}
		return count;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Min Stack*/
class MinStack {
public:
	void push(int x) {
		elements.push(x);
		if (mins.empty() || x <= mins.top())
			mins.push(x);
	}

	void pop() {
		if (elements.empty()) return;
		if (elements.top() == mins.top())
			mins.pop();
		elements.pop();
	}

	int top() {
		return elements.top();
	}

	int getMin() {
		return mins.top();
	}
private:
	stack<int> elements;
	stack<int> mins;
};
/*-------------------------------------------------------------------------------------*/
/*Count and Say*/
class Solution35 {
public:
	string countAndSay(int n) {
		string result;
		string tmp;
		if (n > 0)
		{
			int index = 1;
			while (index < n + 1)
			{
				if (index == 1)
				{
					tmp = "1";
					result = tmp + '#';
					tmp.clear();
				}
				else
				{
					int len = result.size();
					char cur = '#';
					int num = 0;
					for (int i = 0; i < len; i++)
					{
						if (cur == result[i])
						{
							num++;
							continue;
						}
						else
						{
							if (i == 0)
							{
								cur = result[i];
								num++;
								continue;
							}
							else
							{
								char n = '0' + num;
								tmp = tmp + n + cur;
								cur = result[i];
								num = 1;
							}
						}
					}
					result = tmp + '#';
					tmp.clear();
				}
				index++;
			}
		}
		result.replace(result.size() - 1, result.size() - 1, "");
		return result;
	}
};
/*
Solution35 SU35;
string res=SU35.countAndSay(6);
*/
/*-------------------------------------------------------------------------------------*/
/*Valid Sudoku */
class Solution34 {
public:
	int validArray[10];
	bool isValidSudoku(vector<vector<char> > &board) {
		return validRow(board)&validCol(board)&validBlock(board);
	}

	bool validBlock(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i += 3)
		{
			for (int j = 0; j < 9; j += 3)
			{
				memset(validArray, 0, sizeof(int) * 10);
				for (int m = i; m < i + 3; m++)
				{
					for (int n = j; n < j + 3; n++)
					{
						if (board[m][n] >= '1'&&board[m][n] <= '9')
						{
							validArray[board[m][n] - '0']++;
						}
					}
					for (int i = 1; i < 10; i++)
					{
						if (validArray[i]>1)
						{
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	bool validRow(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i++)
		{
			memset(validArray, 0, sizeof(int) * 10);
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] >= '1'&&board[i][j] <= '9')
				{
					validArray[board[i][j] - '0']++;
				}
			}
			for (int j = 1; j < 10; j++)
			{
				if (validArray[j]>1)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool validCol(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i++)
		{
			memset(validArray, 0, sizeof(int) * 10);
			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] >= '1'&&board[j][i] <= '9')
				{
					validArray[board[j][i] - '0']++;
				}
			}
			for (int j = 1; j < 10; j++)
			{
				if (validArray[j]>1)
				{
					return false;
				}
			}
		}
		return true;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Valid Palindrome*/
class Solution33 {
public:
	bool isPalindrome(string s) {
		string str;
		int len = s.size();
		if (len == 0)
		{
			return true;
		}
		for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				str.push_back(tolower(s[i]));
			}
			if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9'))
			{
				str.push_back(s[i]);
			}
		}
		string strReverse = str;
		reverse(strReverse.begin(), strReverse.end());
		if (str == strReverse)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
/*
Solution33 SU33;
bool result = SU33.isPalindrome("A man, a plan, a canal: Panama");
result = SU33.isPalindrome("race a car");
*/
/*-------------------------------------------------------------------------------------*/
/*Longest Valid Parentheses*/
class Solution32 {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int len = s.size();
		int maxLength = 0;
		int index = -1;
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
						maxLength = max(i - index, maxLength);
					}
					else
					{
						maxLength = max(i - st.top(), maxLength);
					}
				}
				else
				{
					index = i;
				}

			}
		}
		return maxLength;
	}
};
/*
Solution32 SU32;
int result = SU32.longestValidParentheses(")(()())()");
result = SU32.longestValidParentheses("()(()");
result = SU32.longestValidParentheses("()(())");
*/
/*-------------------------------------------------------------------------------------*/
/*Median of Two Sorted Arrays*/
class Solution31 {
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
/*ZigZag Conversion */
class Solution30 {
public:
	string convert(string s, int nRows) {
		if (nRows == 1)
		{
			return s;
		}
		int len = s.size();
		if (len <= nRows)
		{
			return s;
		}
		vector <string> vecStr(nRows);
		int index = -1;
		while (index + 1 < len)
		{
			if (index + nRows < len)
			{
				for (int i = 0; i < nRows; i++)
				{
					vecStr[i] += s[index + i + 1];
				}
				index = index + nRows;
				int dist = len - index - 1;
				if (dist >= nRows - 2)
				{
					dist = nRows - 2;
				}
				for (int i = 0; i < dist; i++)
				{
					vecStr[nRows - i - 2] += s[index + 1 + i];
				}
				index = index + dist;
			}
			else
			{
				for (int i = 0; i < len - index - 1; i++)
				{
					vecStr[i] += s[index + 1 + i];
				}
				index = len;
			}
		}
		string result;
		for (int i = 0; i < nRows; i++)
		{
			result += vecStr[i];
		}
		return result;
	}
};
/*
Solution30 SU30;
string result = SU30.convert("PAYPALISHIRING", 3);//"PAHNAPLSIIGYIR"
result = SU30.convert("ABC", 2);//"ACB"
result = SU30.convert("A", 2);//"A"
result = SU30.convert("ABCDE", 4);//"ABCED"
*/
/*-------------------------------------------------------------------------------------*/
/*Intersection of Two Linked Lists*/
class Solution29 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0;
		int lenB = 0;
		if (headA == NULL || headB == NULL)
		{
			return NULL;
		}
		ListNode *pA = headA;
		ListNode *pB = headB;
		while (pA != NULL)
		{
			pA = pA->next;
			lenA++;
		}
		while (pB != NULL)
		{
			pB = pB->next;
			lenB++;
		}
		pA = headA;
		pB = headB;
		if (lenA > lenB)
		{
			for (int i = 0; i < lenA - lenB; i++)
			{
				pA = pA->next;
			}
		}
		else
		{
			for (int i = 0; i < lenB - lenA; i++)
			{
				pB = pB->next;
			}
		}
		while (pA&&pB)
		{
			if (pA == pB)
			{
				return pA;
			}
			pA = pA->next;
			pB = pB->next;
		}
		return NULL;
	}
};
/*-------------------------------------------------------------------------------------*/
/*Multiply Strings*/
class Solution28 {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		string index = "0";
		string result = "0";
		int len1 = num1.size();
		int len2 = num2.size();
		vector<string> tmpVec;
		if (len1 < len2)
		{
			for (int i = len1 - 1; i >= 0; i--)
			{
				string tmp = multi(num2, num1[i] - '0');
				if (tmp != "0")
				{
					for (int j = 0; j < len1 - 1 - i; j++)
					{
						tmp += "0";
					}
					tmpVec.push_back(tmp);
				}
			}
			for (auto& m : tmpVec)
			{
				result = add(result, m);
			}
		}
		else
		{
			for (int i = len2 - 1; i >= 0; i--)
			{
				string tmp = multi(num1, num2[i] - '0');
				if (tmp != "0")
				{
					for (int j = 0; j < len2 - 1 - i; j++)
					{
						tmp += "0";
					}
					tmpVec.push_back(tmp);
				}
			}
			for (auto& m : tmpVec)
			{
				result = add(result, m);
			}
		}
		return result;
	}

	string multi(string str, int num)
	{
		if (num == 0)
		{
			return "0";
		}
		int len = str.size();
		string result;
		int carry = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			int tmp = (str[i] - '0')*num + carry;
			carry = tmp / 10;
			result.push_back(tmp % 10 + '0');
		}
		if (carry != 0)
		{
			result.push_back(carry + '0');
		}
		reverse(result.begin(), result.end());
		return result;
	}

	string add(string num1, string num2)
	{
		int len1 = num1.size();
		int len2 = num2.size();
		string result;
		int carry = 0;
		if (len1 < len2)
		{
			for (int i = len1 - 1; i >= 0; i--)
			{
				int tmp = (num1[i] - '0') + (num2[len2 - len1 + i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
			for (int i = len2 - len1 - 1; i >= 0; i--)
			{
				int tmp = (num2[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}

		}
		else if (len1 > len2)
		{
			for (int i = len2 - 1; i >= 0; i--)
			{
				int tmp = (num1[len1 - len2 + i] - '0') + (num2[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
			for (int i = len1 - len2 - 1; i >= 0; i--)
			{
				int tmp = (num1[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
		}
		else
		{
			for (int i = len1 - 1; i >= 0; i--)
			{
				int tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
		}
		if (carry != 0)
		{
			result.push_back(carry + '0');
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
/*
Solution28 SU28;
string result = SU28.add("92", "19");
result = SU28.multiply("508591", "41609063");
*/
/*-------------------------------------------------------------------------------------*/
/*Interleaving String*/
class Solution27 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size())
			return false;
		vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));
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
		return match[s1.size()][s2.size()];
	}
};
/*
Solution27 SU27;
bool result = SU27.isInterleave("aabcc", "dbbca", "aadbbcbcac");//true
result = SU27.isInterleave("aabcc", "dbbca", "aadbcbbcac");//true
result = SU27.isInterleave("aabcc", "dbbca", "aadbbbaccc");//false
result = SU27.isInterleave("aa", "ab", "aaba");//true
result = SU27.isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb", "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc", "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc");
*/
/*
class Solution27 {
public:
string str1;
string str2;
string str3;
bool isInterleave(string s1, string s2, string s3) {
int len1 = s1.size();
int len2 = s2.size();
int len3 = s3.size();
if (len1 == 0 || len2 == 0)
{
if (s1 + s2 == s3)
{
return true;
}
else
{
return false;
}
}
if (len1 + len2 == len3)
{
str1 = s1;
str2 = s2;
str3 = s3;
return IsInter(0, len1 - 1, 0, len2 - 1, 0, len3 - 1);
}
else
{
return false;
}
}

bool IsInter(int s1, int e1, int s2, int e2, int s3, int e3)
{
if (s1>e1)
{
string ss1;
string ss2;
for (int i = s2; i <= e2; i++)
{
ss1.push_back(str2[i]);
}
for (int i = s3; i <= e3; i++)
{
ss2.push_back(str3[i]);
}
if (ss1 == ss2)
{
return true;
}
else
{
return false;
}
}
if (s2>e2)
{
string ss1;
string ss2;
for (int i = s1; i <= e1; i++)
{
ss1.push_back(str1[i]);
}
for (int i = s3; i <= e3; i++)
{
ss2.push_back(str3[i]);
}
if (ss1 == ss2)
{
return true;
}
else
{
return false;
}
}
if (str1[s1] == str3[s3] && str2[s2] == str3[s3])
{
return IsInter(s1 + 1, e1, s2, e2, s3 + 1, e3) | IsInter(s1, e1, s2 + 1, e2, s3 + 1, e3);
}
else if (str1[s1] == str3[s3])
{
return IsInter(s1 + 1, e1, s2, e2, s3 + 1, e3);
}
else if (str2[s2] == str3[s3])
{
return IsInter(s1, e1, s2 + 1, e2, s3 + 1, e3);
}
else
{
return false;
}
}
};
*/
/*-------------------------------------------------------------------------------------*/
/*Find Peak Element */
class Solution26 {
public:
	int findPeakElement(const vector<int> &num) {
		int result = -1;
		int length = num.size();
		if (length > 0)
		{
			if (length == 1)
			{
				return 0;
			}
			if (length == 2)
			{
				if (num[0] > num[1])
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			for (int i = 0; i < length; i++)
			{
				if (i == 0)
				{
					if (num[i]>num[i + 1])
					{
						return 0;
					}
					continue;
				}
				if (i == length - 1)
				{
					if (num[i] > num[i - 1])
					{
						return i;
					}
					continue;
				}
				if (num[i] > num[i - 1] && num[i] > num[i + 1])
				{
					return i;
				}
			}
		}
		return result;
	}
};
/*
vector<int> num;
num.push_back(1);
num.push_back(2);
num.push_back(3);
Solution26 SU26;
int result=SU26.findPeakElement(num);
*/
/*-------------------------------------------------------------------------------------*/
/*Validate Binary Search Tree*/
class Solution25 {
public:
	vector<int> inOrderVec;
	bool isValidBST(TreeNode *root) {
		bool isBST = true;
		if (root != NULL)
		{
			InOrder(root);
			isBST = IsSorted(inOrderVec);
		}
		return isBST;
	}
	void InOrder(TreeNode *root)
	{
		if (root != NULL)
		{
			if (root->left != NULL)
			{
				InOrder(root->left);
			}
			inOrderVec.push_back(root->val);
			if (root->right != NULL)
			{
				InOrder(root->right);
			}
		}
	}
	bool IsSorted(vector<int>& vec)
	{
		int length = vec.size();
		if (length == 1)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < length - 1; i++)
			{
				if (vec[i] >= vec[i + 1])
				{
					return false;
				}
			}
			return true;
		}
	}
};
/*
TreeNode* root = new TreeNode(0);
TreeNode* node1 = new TreeNode(-1);
TreeNode* node2 = new TreeNode(3);
TreeNode* node3 = new TreeNode(4);
TreeNode* node4 = new TreeNode(5);
TreeNode* node5 = new TreeNode(6);
root->left = node1;
//root->right = node2;
//node1->left = node3;
//node3->right = node4;
//node4->left = node5;
Solution25 SU25;
SU25.isValidBST(root);
*/
/*-------------------------------------------------------------------------------------*/
/*Compare Version Numbers*/
class Solution24 {
public:
	int compareVersion(string version1, string version2) {
		vector<string> strVer1 = Split(version1, ".");
		vector<string> strVer2 = Split(version2, ".");
		int countVer1 = strVer1.size();
		int countVer2 = strVer2.size();
		int countVer = countVer1;
		if (countVer1 < countVer2)
		{
			countVer = countVer2;
			for (size_t i = countVer1; i < countVer2; i++)
			{
				strVer1.push_back("0");
			}
		}
		if (countVer1 > countVer2)
		{
			countVer = countVer1;
			for (size_t i = countVer2; i < countVer1; i++)
			{
				strVer2.push_back("0");
			}
		}
		int index = 0;
		while (index < countVer)
		{
			int ver1 = StringToInt(strVer1[index]);
			int ver2 = StringToInt(strVer2[index]);
			if (ver1 < ver2)
			{
				return -1;
			}
			else if (ver1 > ver2)
			{
				return 1;
			}
			else
			{
				index++;
			}
		}
		return 0;
	}

	int StringToInt(string str)
	{
		stringstream ss;
		ss << str;
		int result;
		ss >> result;
		return result;
	}

	vector<string> Split(string str, string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str += pattern;
		int size = str.size();

		for (int i = 0; i < size; i++)
		{
			pos = str.find(pattern, i);
			if (pos < size)
			{
				std::string s = str.substr(i, pos - i);
				result.push_back(s);
				i = pos + pattern.size() - 1;
			}
		}
		return result;
	}
};
/*-------------------------------------------------------------------------------------*/
/*strStr*/
class Solution23 {
public:
	int strStr(char *haystack, char *needle) {
		string str1(haystack);
		string str2(needle);
		size_t pos = str1.find(str2);
		if (pos != string::npos)
		{
			return (int)pos;
		}
		else
		{
			return -1;
		}
	}
};
/*-------------------------------------------------------------------------------------*/
/*Distinct Subsequences */
class Solution22 {
public:
	int numDistinct(string S, string T) {

	}
};
/*-------------------------------------------------------------------------------------*/
/*Maximum Depth of Binary Tree*/
class Solution21 {
public:
	int MaxDepth = 0;
	int maxDepth(TreeNode *root) {
		if (root != NULL)
		{
			GetMaxDepth(root, 1);
		}
		return MaxDepth;
	}
	int GetMaxDepth(TreeNode *root, int depth)
	{
		if (root == NULL)
		{
			return 0;
		}
		int lMax = 0;
		int rMax = 0;
		if (root->left != NULL)
		{
			lMax = GetMaxDepth(root->left, depth + 1);
		}
		if (root->right != NULL)
		{
			rMax = GetMaxDepth(root->right, depth + 1);
		}
		depth = 1 + max(lMax, rMax);
		if (depth > MaxDepth)
		{
			MaxDepth = depth;
		}
		return depth;
	}
};
/*
TreeNode* root = new TreeNode(1);
TreeNode* node1 = new TreeNode(2);
TreeNode* node2 = new TreeNode(3);
TreeNode* node3 = new TreeNode(4);
TreeNode* node4 = new TreeNode(4);
TreeNode* node5 = new TreeNode(4);
root->left = node1;
root->right = node2;
node1->left = node3;
node3->right = node4;
node4->left = node5;
Solution21 SU21;
SU21.maxDepth(root);
*/
/*-------------------------------------------------------------------------------------*/
/*Merge Intervals*/
class Solution20 {
public:
	//class SortIntervals
	//{
	//	public:
	//		bool operator ()(Interval& int1, Interval& int2)
	//		{
	//			return int1.start < int2.start;
	//		}
	//};

	// [](Interval& int1, Interval& int2){return int1.start < int2.start; }

	static bool SortIntervals(Interval& int1, Interval& int2)
	{
		return int1.start < int2.start;
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		int intervalsCount = intervals.size();
		if (intervalsCount>0)
		{
			if (intervalsCount == 1)
			{
				return intervals;
			}
			std::sort(intervals.begin(), intervals.end(), Solution20::SortIntervals);
			auto iter = intervals.begin();
			while (iter != intervals.end() && (iter + 1) != intervals.end())
			{
				if (MergeIntervals(*iter, *(iter + 1)))
				{
					intervals.erase(iter + 1);
				}
				else
				{
					iter++;
				}
			}
		}
		return intervals;
	}

	bool MergeIntervals(Interval& int1, Interval& int2)
	{
		if (int1.end >= int2.start)
		{
			if (int1.end < int2.end)
			{
				int1.end = int2.end;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
};
/*
vector<Interval> vec;
vec.push_back(Interval(1, 3));
vec.push_back(Interval(1, 3));
vec.push_back(Interval(1, 3));
vec.push_back(Interval(1, 3));
vec.push_back(Interval(2, 6));
vec.push_back(Interval(15, 18));
vec.push_back(Interval(8, 10));
Solution20 SU20;
SU20.merge(vec);
*/
/*-------------------------------------------------------------------------------------*/
/*Excel Sheet Column Title*/
class Solution19 {
public:
	string convertToTitle(int n) {
		string result;
		if (n > 0)
		{
			while (n != 0)
			{
				result.push_back('A' + (n - 1) % 26);
				n = (n - 1) / 26;
			}
			reverse(result.begin(), result.end());
		}
		return result;
	}
};
/*
Solution19 SU19;
SU19.convertToTitle(28);
*/
/*-------------------------------------------------------------------------------------*/
/*Majority Element*/
class Solution18 {
public:
	int majorityElement(vector<int> &num) {
		map<int, int> mp;
		int length = num.size();
		int result = 0;
		for (int i = 0; i < length; i++)
		{
			mp[num[i]]++;
		}
		int lenghtMP = mp.size();
		for (auto& m : mp)
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
		if (m == 1 || n == 1)
		{
			num = 1;
		}
		if (m > 1 && n > 1)
		{
			vector<vector<int> > vecResult;
			for (int i = 0; i < n; i++)
			{
				vecResult.push_back(vector<int>(m, 1));
			}
			GetPaths(n, m, vecResult);
			num = vecResult[n - 1][m - 1];
		}
		return num;
	}
	void GetPaths(int n, int m, vector<vector<int> >& vecResult)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				vecResult[i][j] = vecResult[i][j - 1] + vecResult[i - 1][j];
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
			if (numRows >= 1)
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
		while (index <= n*n)
		{
			Fill(indexIJ, lenght, index);
			lenght -= 2;
			indexIJ++;
		}
		return result;
	}

	void Fill(int indexIJ, int n, int &index)
	{
		if (n == 1)
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
