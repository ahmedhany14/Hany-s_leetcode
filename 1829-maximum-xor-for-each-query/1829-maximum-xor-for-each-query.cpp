class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorRES = 0;
        for(auto i: nums) xorRES ^= i;
        vector<int> query(nums.size());
        
        int mx_bit = (1 << maximumBit) - 1;
        for(int i = 0; i < nums.size(); ++i){
            query[i] = xorRES ^ mx_bit;
            
            xorRES ^= nums[nums.size() - i - 1];   
        }
        return query;
    }
};