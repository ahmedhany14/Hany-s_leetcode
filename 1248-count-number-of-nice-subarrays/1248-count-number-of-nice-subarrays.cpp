class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int answer = 0, sum = 0;
        for(auto i : nums){
            sum += i % 2;
            answer += mp[sum - k];
            mp[sum]++;
        }
        return answer;
    }
};