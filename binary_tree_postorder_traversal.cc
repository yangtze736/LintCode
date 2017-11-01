/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

分析
    二叉树后序遍历的顺序是左-右-根，所以当一个节点值被取出来时，它的左右子节点
    要么不存在，要么已经被访问过。
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode*> pstack;
		if(!root) return res;

		TreeNode *tmp = root, *delet = root;
		pstack.push(root);

		while( !pstack.empty() ) {
			tmp = pstack.top();
			// tmp节点的左右子节点为空或者tmp节点的左右子节点已经被访问,则将它从stack中取出放入数组
			if( (!tmp->right && !tmp->left) || tmp->right == delet || tmp->left == delet  ) {
			delet = pstack.top();
			pstack.pop();
			res.push_back(delet->val);	
			} else {
				if( tmp->right ) pstack.push(tmp->right);
				if( tmp->left ) pstack.push(tmp->left);
			}		
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

void printTreePostOrder(TreeNode *root)
{
	if (root == NULL){
		//cout << "# ";
		return ;
	}
	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	cout << root->val << " ";
}

void printArray(vector<int> v)
{
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

/*  创建的树的结构如下，后序遍历结果为：4 7 8 5 2 9 6 3 1
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
	printTreePostOrder(p);
	cout << endl;

	Solution solu;	
	vector<int> v = solu.postorderTraversal(p);
	printArray(v);

	return 0;
}
