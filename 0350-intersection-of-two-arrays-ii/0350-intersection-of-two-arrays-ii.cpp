class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int f0[1001] = {}, f1[1001] = {};
        vector<int> answer;        
        for(auto i : nums1) f0[i]++;
        for(auto i : nums2) f1[i]++;
        for(int i = 0;i < 1001; ++i){
            while(f0[i] and f1[i]) {
                answer.push_back(i);
                f0[i]--; 
                f1[i]--;                
            }
        }
        return answer;
    }
};