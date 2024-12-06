class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(auto i : banned) if(i <= n) st.insert(i);
        int answer = 0;
        for(int i = 1; i <= n and maxSum >= i; ++i){
            if(st.contains(i) == 0 and maxSum >= i){
                maxSum -= i;
                answer++;
            }
        }
        return answer;
    }
};