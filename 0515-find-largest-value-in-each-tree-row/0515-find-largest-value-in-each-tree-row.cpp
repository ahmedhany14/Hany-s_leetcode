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
    void dfs(TreeNode* root, int dep, vector<vector<int>>&depth){
        if(root == NULL) return;
        depth[dep].emplace_back(root->val);        
        dfs(root->right, dep + 1, depth);
        dfs(root->left, dep + 1, depth);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> depth (10004);
        dfs(root, 1, depth);
        vector<int> answer;        
        for(int i = 1; i < depth.size(); ++i){
            if(depth[i].size()){
                int mx = *max_element(depth[i].begin(), depth[i].end());
                answer.emplace_back(mx);
            }
        }
        return answer;
    }
};