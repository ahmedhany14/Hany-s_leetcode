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
    int dfs(TreeNode* root, bool right){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            return right == 0 ? root->val : 0;
        }
        return dfs(root -> left, 0) + dfs(root -> right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, -1);
    }
};