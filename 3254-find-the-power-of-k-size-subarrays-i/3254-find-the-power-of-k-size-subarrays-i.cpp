class Solution {
public:
    
    bool is_sorted(int start, int end, vector<int>& nums){
        for(int i = start; i < end; ++i) {
            if(nums[i] != nums[i + 1] - 1){
                return false;
            }
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> answer(n - k + 1, -1);
        for(int i = 0;i <= n - k; ++i){
            if(is_sorted(i, i + k - 1, nums)){
                int mx = 0;
                for(int j = i; j < i + k; ++j){
                    mx = max(mx, nums[j]);
                }
                answer[i] = mx;
            }
        }  
        
        return answer;
            
    }
};
