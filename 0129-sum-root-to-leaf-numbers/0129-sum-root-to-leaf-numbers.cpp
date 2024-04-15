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
    void dfs(TreeNode* root, string a, int& ret){
        if(!root -> left and !root -> right){
            ret += stoi(a + char(root -> val + '0'));
            return;
        }
        if(root -> left != NULL)
            dfs(root -> left, a + char(root -> val + '0'), ret);
        if(root -> right != NULL)
            dfs(root -> right, a + char(root -> val + '0'), ret);
    }
    
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        dfs(root, "", ret);
        return ret;
    }
};