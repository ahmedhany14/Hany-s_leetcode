class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long part1 = 0;
        for(auto a: nums) part1 += a;

        long long part2 = 0;
        int answer = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            part1 -= nums[i];
            part2 += nums[i];
            answer += part2 >= part1;
        }
        return answer;
    }
};