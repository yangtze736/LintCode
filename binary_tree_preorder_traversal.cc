/*
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?

分析
    树的遍历，主要就是先序、中序、后序和层序遍历，使用递归实现起来非常简单
    题目要求不能使用递归解决，要用到stack来辅助。先序遍历的顺序是:根-左-右
    算法为：
        1.把根节点push到栈中
        2.循环检测栈是否为空，若不空则取出栈顶元素，保存其值到vector中，然
        后分别看其右子节点和左子节点是否存在，存在则push到栈stack中。


     方案二未实现：**Morris遍历**
 */

#include<vector>
#include<iostream>
#include<stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode*> pstack;

		if(root != NULL) pstack.push(root);
		while(!pstack.empty()) {
			TreeNode *tmp = pstack.top();
			res.push_back(tmp->val);
			pstack.pop();
			if(tmp->right != NULL) pstack.push(tmp->right);
			if(tmp->left != NULL) pstack.push(tmp->left);
		}

		return res;
	}
};

TreeNode* createTree(int a[], int n)
{
	if (n<=0) return NULL;

	TreeNode **tree = new TreeNode*[n];

	for(int i=0; i<n; i++) {
		if (a[i]==0 ){
			tree[i] = NULL;
			continue;
		}
		tree[i] = new TreeNode(a[i]);
	}
	int pos=1;
	for(int i=0; i<n && pos<n; i++) {
		if (tree[i]){
			tree[i]->left = tree[pos++];
			if (pos<n){
				tree[i]->right = tree[pos++];
			}
		}
	}
	return tree[0];
}

void printTreePreOrder(TreeNode *root)
{
	if (root == NULL){
		//cout << "# ";
		return ;
	}
	cout << root->val << " ";
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

void printArray(vector<int> v)
{
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

/*  创建的树的结构如下，先序遍历结果为：1 2 4 5 7 8 3 6 9
 *
 *             1
 *
 *         2       3
 *
 *      4     5  #    6
 *
 *   #    # 7   8   9    #
 *
 */
int main()
{
	int a[] = {1,2,3,4,5,0,6,0,0,7,8,9,0};
	TreeNode *p = createTree(a, sizeof(a)/sizeof(int));
	printTreePreOrder(p);
	cout << endl;

	Solution solu;	
	vector<int> v = solu.preorderTraversal(p);
	printArray(v);

	return 0;
}
