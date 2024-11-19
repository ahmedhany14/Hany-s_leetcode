class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        vector<long long> prefix(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for(int i = 0; i < k ; ++i) f[nums[i]]++;
        long long answer =  0;
        if(f.size() == k) answer = prefix[k];
        int l = 0, r = k;
        while(r < nums.size()){
            f[nums[l]]--;
            f[nums[r]]++;
            if(!f[nums[l]]) f.erase(nums[l]);
            ++l, ++r;
            if(f.size() == k) answer = max(answer, prefix[r] - prefix[l]);
        }
        return answer;
    }
};