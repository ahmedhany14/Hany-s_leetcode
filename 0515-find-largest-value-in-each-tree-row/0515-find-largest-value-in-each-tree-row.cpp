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
    
    int max_dep(TreeNode* root){
        if(root == NULL) return 0;
        int me = 0;
        me = max(me, 1 + max_dep(root->right));
        me = max(me, 1 + max_dep(root->left));
        return me;
    }
    
    void dfs(TreeNode* root, int dep, vector<int>&depth){
        if(root == NULL) return;
        depth[dep - 1] = max(depth[dep - 1], root->val);
        dfs(root->right, dep + 1, depth);
        dfs(root->left, dep + 1, depth);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> depth (max_dep(root), -(1LL << 31));
        dfs(root, 1, depth);
        return depth;
    }
};