class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int> Xor;
        vector<int>sub;
        int n = nums.size(), mx = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            sub.clear();
            int x = 0;
            for (int i = 0; i < n; i++)if (mask & (1 << i))sub.push_back(nums[i]);
            for (auto& it : sub)x |= it;
            Xor[x]++;
            mx = max(x, mx);
        }
        return Xor[mx];        
    }
};