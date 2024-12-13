class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> p;
        for(int i = 0; i < nums.size(); ++i) p.emplace_back(nums[i], i);
        sort(p.begin(), p.end());
        long long score = 0;

        vector<int> mark(nums.size() + 1);
        for(auto[val, index] : p){
            if(!mark[index]) {
                score += val;
                if(index - 1 >= 0)
                    mark[index - 1] = 1;
                mark[index + 1] = 1;
            }
        }        
        
        return score;
    }
};