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
    vector<string> v;
    void dfs(TreeNode* root, string a){
        if(!root -> left and !root -> right){
            v.push_back(a + char(root -> val + '0'));
            return;
        }
        if(root -> left != NULL)
            dfs(root -> left, a + char(root -> val + '0'));
        if(root -> right != NULL)
            dfs(root -> right, a + char(root -> val + '0'));
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        int ret = 0;
        for(auto a : v) ret += stoi(a);
        return ret;
    }
};