/*
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?

分析
    非递归思路：从根节点开始，先将根节点压入栈，然后再将其所有左子结点
    压入栈，然后取出栈顶节点，保存节点值，再将当前指针移到其右子节点上，
    若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。这样就
    保证了访问顺序为左-根-右
 */

#include<vector>
#include<iostream>
#include<stack>
#include<unistd.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

using namespace std;

//
//                 1
//             2       3
//          4    5   #    6
//        #   #7   8    9   #   
//	 
//	  这里注意实现的技巧：是按照／一遍遍的刷到stack中去，先将1 2 4刷到
//	  stack中去，拿4出来时p为空，拿2出来时p指向5，将5 7刷到stack中去，
//	  拿7出来时p为空，拿5出来时p指向8，将8刷到stack中去，拿8出来时p为空
//	  拿1出来时p指向3，将3刷到stack中，拿3出来时p指向6，将6 9刷到stack
//	  中去，拿9出来时p为空，拿6出来。
//	  中序遍历结果应为：4 2 7 5 8 1 3 9 6 
//	 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode*> pstack;
		TreeNode *p = root;

		while(p != NULL || !pstack.empty()) {
			while(p != NULL) {
				pstack.push(p);
				p = p->left;
			}
			p = pstack.top();
			pstack.pop();
			res.push_back(p->val);
			p = p->right;
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

void printTreeInOrder(TreeNode *root)
{
	if (root == NULL){
		//cout << "# ";
		return ;
	}
	printTreeInOrder(root->left);
	cout << root->val << " ";
	printTreeInOrder(root->right);
}

void printArray(vector<int> v)
{
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

/*  创建的树的结构如下，中序遍历结果为：4 2 7 5 8 1 3 9 6
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
	printTreeInOrder(p);
	cout << endl;

	Solution solu;	
	vector<int> v = solu.inorderTraversal(p);
	printArray(v);

	return 0;
}
