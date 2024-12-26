class Solution {
public:
    
    int help(int i, int sum, int target, vector<int>&nums){
        if(i == nums.size())return sum == target;       
        return help(i + 1, sum + nums[i], target, nums) + help(i + 1, sum - nums[i], target, nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return help(0, 0, target, nums);
    }
};