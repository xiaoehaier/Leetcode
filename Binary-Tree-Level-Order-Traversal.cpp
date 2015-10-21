#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        TreeNode *tmp[2][1024] = {NULL};
        tmp[0][0] = root;
        int tmpIndex = 0;
            

        while(!tmp[tmpIndex][0]){
            vector<int> level;
            int i=0, j=0;
            for(; tmp[tmpIndex][i]; ++i){
                level.push_back(tmp[tmpIndex][i]->val);
                if(tmp[tmpIndex][i]->left)
                    tmp[(tmpIndex+1)%2][j++] = tmp[tmpIndex][i]->left;
                if(tmp[tmpIndex][i]->right)
                    tmp[(tmpIndex+1)%2][j++] = tmp[tmpIndex][i]->right;
            }
            ++tmpIndex;
            tmpIndex %= 2;
            tmp[tmpIndex][i] = NULL;
            
            if(!level.empty())
                result.push_back(level);
            
        }
        
        return result;
    }
};