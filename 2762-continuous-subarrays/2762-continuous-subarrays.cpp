class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0, r = 0;
        map<int,int> mp;
        long long answer = 0;
        while(r < nums.size()){
            mp[nums[r]]++;
            
            int mn = mp.begin()-> first;
            int mx = mp.rbegin()-> first;
            while(mx - mn > 2){
                mp[nums[l]]--;
                if(!mp[nums[l]]) mp.erase(nums[l]);
                mx = mp.rbegin()-> first;
                mn = mp.begin()-> first;
                ++l;
            }
            answer += r - l + 1; 
            ++r;
        }
        return answer;
    }
};