class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> p;
        for(int i = 0; i < nums.size(); ++i) p.emplace_back(nums[i], i);
        sort(p.begin(), p.end());
        long long score = 0;
        map<int, int> mark;

        for(auto[val, index] : p){
            if(!mark[index]) {
                score += val;
                mark[index - 1] = mark[index + 1] = 1;
            }
        }        
        
        return score;
    }
};