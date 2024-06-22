class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), all = 0;
        vector<int> prefix(n + 1);
        for(int i = 0; i < n; ++i){
            grumpy[i] == 1 ? prefix[i + 1] = customers[i] : all += customers[i];;
            prefix[i + 1] += prefix[i];
        }
        int ret = 0;
        for(int i = 0;i <= n - minutes; i++) ret = max(ret, all + prefix[i + minutes] - prefix[i]);
        return ret;;        
    }
};