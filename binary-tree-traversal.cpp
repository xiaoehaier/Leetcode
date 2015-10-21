/*
Definition for binary tree
*/

#include <vector>
#include <stack>
using std::stack;
using std::vector;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* 
class Solution {
	vector<int> preorder;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return preorder;

        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return preorder;
    }
};
*/

/*class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode *> path;
        path.push(root);
        
        while (!path.empty()) {
        	TreeNode *tmp = path.top();
        	path.pop();
        	result.push_back(tmp->val);

        	if (tmp->right) path.push(tmp->right);
        	if (tmp->left) path.push(tmp->left);
    	}

    	return result;
    }
};*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode *> path;
        path.push(root);
        
        while (!path.empty()) {
            TreeNode *tmp = path.top();

            if (!tmp->left && !tmp->right) {
                path.pop();
                result.push_back(tmp->val);
            }

            if (tmp->right) path.push(tmp->right);
            if (tmp->left) path.push(tmp->left);
            tmp->left = tmp->right = NULL;

        }

        return result;
    }
};