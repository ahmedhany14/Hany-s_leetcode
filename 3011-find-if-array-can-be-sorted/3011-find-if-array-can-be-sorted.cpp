class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if(nums[i] <= nums[i + 1]) continue;
            bitset<10> p(nums[i]), q(nums[i + 1]);
            if (p.count() == q.count()) swap(nums[i], nums[i + 1]);
            else return false;
        }
        for (int i = n - 1; i > 0; --i) {
            if(nums[i] >= nums[i - 1]) continue;
            bitset<10> p(nums[i]), q(nums[i - 1]);
            if (p.count() == q.count()) swap(nums[i], nums[i - 1]);
            else return false;
        }

        return true;
    }
};
