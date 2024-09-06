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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> mark(100005, 0), taken(100005, 0);
        for(auto i :nums) mark[i] = 1;
        ListNode* temp = new ListNode();
        ListNode* ret = temp;
        while(head != nullptr){
            int node = head->val;
            if(!mark[node]){
                ret -> next = new ListNode(head->val);
                ret = ret -> next;
            }
            head = head->next;
        }
        return temp -> next;
    }
};