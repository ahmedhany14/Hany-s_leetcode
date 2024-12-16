class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    
        while(k--){
            int mn = 1e9, ind = -1;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] < mn) mn = nums[i], ind = i;
            }
            nums[ind] *= multiplier;
        }
        return nums;
    }
};