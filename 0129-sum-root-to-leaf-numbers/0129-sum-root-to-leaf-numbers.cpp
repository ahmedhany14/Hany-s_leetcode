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
    string add(string a, string b) {
        if (a.length() > b.length())
            swap(a, b);
        string str = "";
        int n = a.length(), m = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int sum = ((a[i] - '0') + (b[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n; i < m; i++) {
            int sum = ((b[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        return str;
    }
    
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
        string ret = "";
        for(auto a : v) ret = add(ret, a);
        return stoi(ret);
    }
};