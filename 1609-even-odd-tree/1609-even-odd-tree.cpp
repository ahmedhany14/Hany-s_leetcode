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


    bool isEvenOddTree(TreeNode* root) {
        vector<int> level(1000005), adj[1000005];
        queue<TreeNode*> q;
        q.emplace(root);
        level[root->val] = 0;
        adj[0].emplace_back(root->val);
        bool ok = root->val & 1;

        while(q.size()){
            TreeNode* node = q.front();
            q.pop();

            TreeNode* child;
            if(node -> left != NULL){
                child = node -> left;
                level[child -> val] = level[node -> val] + 1;
                if(adj[level[child -> val]].size()){
                    if(level[child -> val] & 1)
                        ok &= (adj[level[child -> val]].back() > child -> val) and (child -> val % 2 == 0);
                    else 
                        ok &= adj[level[child -> val]].back() < child -> val and (child -> val % 2 != 0);
                }
                else {
                    ok &=  (child -> val % 2) !=  (level[child -> val] % 2);
                }
                adj[level[child -> val]].emplace_back(child -> val);
                q.emplace(child);
            }
            if(node -> right != NULL){
                child = node -> right;
                level[child -> val] = level[node -> val] + 1;
                if(adj[level[child -> val]].size()){
                    if(level[child -> val] & 1)
                        ok &= (adj[level[child -> val]].back() > child -> val) and (child -> val % 2 == 0);
                    else 
                        ok &= adj[level[child -> val]].back() < child -> val and (child -> val % 2 != 0);
                }
                else {
                    ok &=  (child -> val % 2) !=  (level[child -> val] % 2);
                }
                adj[level[child -> val]].emplace_back(child -> val);
                q.emplace(child);
            }
        }
        return ok;
    }
};