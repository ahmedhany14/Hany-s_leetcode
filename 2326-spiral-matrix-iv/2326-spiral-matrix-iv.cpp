/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        
        int rowS = 0;
        int rowL = m-1;
        int colS = 0;
        int colL = n-1;

        while(head) {
            for(int i = colS; i <= colL && head; i++) {
                ans[rowS][i] = head->val;
                head = head->next;
            }
            rowS++;

            for(int i = rowS ; i <= rowL && head; i++) {
                ans[i][colL] = head->val;
                head = head->next;
            }
            colL--;

            for(int i = colL; i >= colS && head; i--) {
                ans[rowL][i] = head->val;
                head = head->next;
            }
            rowL--;

            for(int i = rowL; i >= rowS && head; i--) {
                ans[i][colS] = head->val;
                head = head->next;
            }
            colS++;
        }

        return ans;

    }
};