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
    void dfs(TreeNode* root, int a, int& ret){
        if(!root -> left and !root -> right){
            ret += a * 10 + root -> val;
            return;
        }
        if(root -> left != NULL)
            dfs(root -> left, a * 10 + root -> val, ret);
        if(root -> right != NULL)
            dfs(root -> right, a * 10 + root -> val , ret);
    }
    
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        dfs(root,0, ret);
        return ret;
    }
};