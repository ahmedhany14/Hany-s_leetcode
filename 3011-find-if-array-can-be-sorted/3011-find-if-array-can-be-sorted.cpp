class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int n = nums.size();        
        for(int k = 0;k < n; k++){
            for(int i = 0;i < n; ++i){
                for(int ii = i + 1;ii < n; ++ii){
                    bitset<10> p(nums[i]), q(nums[ii]);
                    if(p.count() == q.count() and nums[i] > nums[ii]) swap(nums[i], nums[ii]);
                    else break;
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};