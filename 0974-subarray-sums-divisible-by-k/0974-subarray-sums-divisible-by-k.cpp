class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mods;
        mods[0] = 1;
        int sum = 0, answer = 0;        
        auto fix = [&](int sum, int add) -> int{
            sum = (((sum + add) % k) + k) % k; 
            return sum;
        };
        for(auto i : nums){
            sum = fix(sum, i);
            answer += mods[sum];
            mods[sum]++;
        }
        return answer;
    }
};