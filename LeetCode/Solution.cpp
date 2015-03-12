#include "stdafx.h"
#include "DataStructure.h"
/*-------------------------------------------------------------------------------------*/
/*Gas Station*/
class Solution68 {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int len = gas.size();
		vector<int> vec;
		for (int i = 0; i < len; i++)
		{
			vec.push_back(gas[i]-cost[i]);
		}
		int sum = 0;
		int leftGas = 0;
		int start = 0;
		for (int i = 0; i < len; i++)
		{
			leftGas += vec[i];
			sum += vec[i];
			if (sum<0)
			{
				sum = 0;
				start = i + 1;
			}
		}
		if (leftGas<0)
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
		if (k>0)
		{
			RotateAll(nums, 0, n - k - 1);
			RotateAll(nums, n - k,n-1);
			RotateAll(nums, 0, n -1);
		}
	}

	void RotateAll(int nums[], int start,int end)
	{
		int mid = (end+start) / 2;
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
		while (n>0)
		{
			if (n&1==1)
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
		vector<string> strArray = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> res(1, "");
		for (int i = 0; i < digits.size(); i++)
		{
			vector<string> tmp;
			for (int j = 0; j < res.size(); j++)
			{
				for (int k = 0; k < strArray[digits[i]-'0'].size(); k++)
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
	int SumToRoot(TreeNode* root,int sum)
	{
		if (root)
		{
			if (root->left==NULL&&root->right==NULL)
			{
				sum=sum+root->val;
				allSum += sum;
				return sum;
			}
			int lSum = 0;
			int rSum = 0;
			if (root->left)
			{
				lSum = SumToRoot(root->left, (sum + root->val)*10);
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
		if (l1==NULL)
		{
			return l2;
		}
		if (l2==NULL)
		{
			return l1;
		}
		ListNode* p1=l1;
		ListNode* p2=l2;
		int carry = 0;
		ListNode* head=p1;
		ListNode* p=head;
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
			if (carry!=0)
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
		if (carry!=0)
		{
			ListNode* last=new ListNode(carry);
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
		if (len==0)
		{
			return 0;
		}
		int end = len;
		int start = len;
		int index = len-1;
		if (s[index]==' ')
		{
			while (s[index]==' '&&index>=0)
			{
				end = index;
				index--;
			}
		}
		if (index<0)
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
		if (l1==NULL)
		{
			return l2;
		}
		if (l2==NULL)
		{
			return l1;
		}
		ListNode* head;
		ListNode* p;
		ListNode* p1=l1;
		ListNode* p2=l2;
		if (p1->val<p2->val)
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
			if (p1->val<p2->val)
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
		if (lenA>lenB)
		{
			len = lenA;
			for (int i = lenB; i < lenA; i++)
			{
				b.push_back('0');
			}
		}
		if (lenA<lenB)
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
			result.push_back(tmp%2+'0');
		}
		if (carry!=0)
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
		if (n==1)
		{
			return 1;
		}
		if (n==2)
		{
			return 2;
		}
		vector<int> stair(n+1, 0);
		stair[1] = 1;
		stair[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			stair[i] = stair[i - 2] + stair[i-1];
		}
		return stair[n];
	}
};
/*-------------------------------------------------------------------------------------*/
/*Remove Duplicates from Sorted List*/
class Solution52 {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head!=NULL)
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
				if (q!=NULL)
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
		if (n>0)
		{
			for (int i = 0; i < n; i++)
			{
				if (A[i]!=elem)
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
		if (n>0)
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
					if (index==-1)
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
		if (m==0)
		{
			while (n-1 >= 0)
			{
				A[index] = B[n-1];
				n--;
				index--;
			}
		}
		while (m-1>=0&&n-1>=0)
		{
			if (A[m-1]>B[n-1])
			{
				A[index] = A[m-1];
				m--;
			}
			else
			{
				A[index] = B[n-1];
				n--;
			}
			index--;
		}
		while (n-1>=0)
		{
			A[index] = B[n-1];
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
		return isSame(p,q);
	}
	bool isSame(TreeNode* r1,TreeNode* r2)
	{
		if (r1==NULL&&r2==NULL)
		{
			return true;
		}
		else if (r1==NULL&&r2!=NULL||r1!=NULL&&r2==NULL)
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
		if (len>0)
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
						if (s[i]==')')
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
		while (p1->next&&n!=0)
		{
			p1 = p1->next;
			n--;
		}
		if (n==1)
		{
			return head->next;
		}
		if (n>1)
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
		for (int i = 0; i< s.size(); i++)
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
		if (x<0)
		{
			return false;
		}
		int count = 0;
		int tmp = x;
		while (tmp!=0)
		{
			count++;
			tmp /= 10;
		}
		for (int i = count-1; i >0; i-=2)
		{
			int left = x / pow(10,i);
			int right = x % 10;
			if (left!=right)
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
		if (tmpL>INT_MAX)
		{
			return INT_MAX;
		}
		if (tmpL<INT_MIN)
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
		if (root!=NULL)
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
					if (tmp->left!=NULL)
					{
						qu.push(tmp->left);
					}
					if (tmp->right != NULL)
					{
						qu.push(tmp->right);
					}
					if (tmp->left==NULL&&tmp->right==NULL)
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
		if (root!=NULL)
		{
			return equalSum(root,0,sum);
		}
		else
		{
			return false;
		}
	}
	bool equalSum(TreeNode *root, int sum,int target)
	{
		if (root->left==NULL&&root->right==NULL)
		{
			if (target==root->val+sum)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool lHasPath = false;
		if (root->left!=NULL)
		{
			lHasPath = equalSum(root->left,root->val+sum,target);
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
		if (rowIndex>=0)
		{
			vector<int> result(rowIndex+1,0);
			result[0]=1;
			int index = 0;
			while (index<rowIndex)
			{
				result[index + 1] = 1;
				for (int i = index; i >=1; i--)
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
		int result=0;
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
		if (n>=0)
		{
			for (int i = 5; i <= n; i+=5)
			{
				int j = i;
				int tmp = j % 5;
				while (tmp==0)
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
		if (n>0)
		{
			int index = 1;
			while (index<n + 1)
			{
				if (index == 1)
				{
					tmp = "1";
					result = tmp+'#';
					tmp.clear();
				}
				else
				{
					int len = result.size();
					char cur='#';
					int num = 0;
					for (int i = 0; i < len; i++)
					{
						if (cur==result[i])
						{
							num++;
							continue;
						}
						else
						{
							if (i==0)
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
		result.replace(result.size() - 1, result.size() - 1,"");
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
		for (int i = 0; i < 9; i+=3)
		{
			for (int j = 0; j < 9; j+=3)
			{
				memset(validArray, 0, sizeof(int) * 10);
				for (int m = i; m < i+3; m++)
				{
					for (int n = j; n < j+3; n++)
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
				if (board[i][j] >= '1'&&board[i][j]<='9')
				{
					validArray[board[i][j]-'0']++;
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

	bool validCol( vector<vector<char> > &board)
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
		if (len==0)
		{
			return true;
		}
		for (int i = 0; i < len; i++)
		{
			if (s[i]>='A'&&s[i]<='Z')
			{
				str.push_back(tolower(s[i]));
			}
			if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i]>='0'&&s[i]<='9'))
			{
				str.push_back(s[i]);
			}
		}
		string strReverse = str;
		reverse(strReverse.begin(), strReverse.end());
		if (str==strReverse)
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
			if (s[i]=='(')
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
		if (m==0&&n==0)
		{
			return 0;
		}
		int indexA = 0;
		int indexB = 0;
		vector<int> vecC;
		while (indexA!=m&&indexB!=n)
		{
			if (A[indexA]<B[indexB])
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
		while (indexA!=m)
		{
			vecC.push_back(A[indexA]);
			indexA++;
		}
		while (indexB != n)
		{
			vecC.push_back(B[indexB]);
			indexB++;
		}
		if ((m+n)%2==0)
		{
			return (vecC[(m + n) / 2] + vecC[(m + n) / 2-1])/2.0;
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
		if (nRows==1)
		{
			return s;
		}
		int len = s.size();
		if (len<=nRows)
		{
			return s;
		}
		vector <string> vecStr(nRows);
		int index = -1;
		while (index+1<len)
		{
			if (index + nRows < len)
			{
				for (int i = 0; i < nRows; i++)
				{
					vecStr[i] += s[index + i + 1];
				}
				index =index + nRows;
				int dist = len - index-1;
				if (dist>=nRows-2)
				{
					dist = nRows - 2;
				}
				for (int i = 0; i < dist; i++)
				{
					vecStr[nRows-i-2] += s[index + 1 + i];
				}
				index = index + dist;
			}
			else
			{
				for (int i = 0; i < len-index-1; i++)
				{
					vecStr[i] += s[index +1 + i];
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
		if (headA==NULL||headB==NULL)
		{
			return NULL;
		}
		ListNode *pA=headA;
		ListNode *pB=headB;
		while (pA!=NULL)
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
		if (lenA>lenB)
		{
			for (int i = 0; i < lenA-lenB; i++)
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
			if (pA==pB)
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
		if (num1=="0"||num2=="0")
		{
			return "0";
		}
		string index = "0";
		string result = "0";
		int len1 = num1.size();
		int len2 = num2.size();
		vector<string> tmpVec;
		if (len1<len2)
		{	
			for (int i = len1-1; i >=0 ; i--)
			{
				string tmp = multi(num2,num1[i]-'0');
				if (tmp!="0")
				{
					for (int j = 0; j < len1 - 1 - i; j++)
					{
						tmp += "0";
					}
					tmpVec.push_back(tmp);
				}
			}
			for (auto& m:tmpVec)
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
		if (num==0)
		{
			return "0";
		}
		int len = str.size();
		string result;
		int carry = 0;
		for (int i = len-1; i >=0; i--)
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
		if (len1<len2)
		{
			for (int i = len1-1; i >= 0; i--)
			{
				int tmp = (num1[i] - '0') + (num2[len2-len1+i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
			for (int i = len2-len1-1; i >= 0; i--)
			{
				int tmp = (num2[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}

		}
		else if (len1>len2)
		{
			for (int i = len2 - 1; i >= 0; i--)
			{
				int tmp = (num1[len1 - len2 + i] - '0') + (num2[i] - '0') + carry;
				carry = tmp / 10;
				result.push_back(tmp % 10 + '0');
			}
			for (int i = len1-len2-1; i >=0; i--)
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
