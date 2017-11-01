/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

分析
    层序遍历二叉树是典型的广度优先搜索BFS的应用，但是这里稍微复杂一点的是，我们要把各个层
    的数分开，存到一个二维向量里面.建立一个queue，然后先把根节点放进去，这时候找根节点的
    左右两个子节点，这时候去掉根节点，此时queue里的元素就是下一层的所有节点，用一个for循环
    遍历它们，然后存到一个一维向量里，遍历完之后再把这个一维向量存到二维向量里，以此类推可
    以完成层序遍历.
 */

#include<vector>
#include<queue>
#include<iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL) return res;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> oneLevel;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();
				oneLevel.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			res.push_back(oneLevel);
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

void printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

int main()
{
	int a[] = {3,9,20,0,0,15,7};
	TreeNode *p = createTree(a, sizeof(a)/sizeof(int));

	Solution solu;	
	vector<vector<int>> v = solu.levelOrder(p);
	printMatrix(v);

	return 0;
}
