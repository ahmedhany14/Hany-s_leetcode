class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mods;
        mods[0] = 1;
        int sum = 0, answer = 0;        
        for(auto i : nums){
            sum += i;
            sum %= k;
            if(sum < 0) sum += k;
            answer += mods[sum];
            mods[sum]++;
        }
        return answer;
    }
};