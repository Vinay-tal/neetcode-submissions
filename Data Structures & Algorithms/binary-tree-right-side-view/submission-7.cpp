/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* root,int depth){
        if(root == NULL)return;
        int n = res.size();
        if(depth == n){
            res.push_back(root->val);
        }
        dfs(root->right,1+depth);
        dfs(root->left,1+depth);

    }
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        dfs(root,0);
        return res;

        
    }
};
