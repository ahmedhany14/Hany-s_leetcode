class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitFreq(32, 0);
        int maxGroup = 0;
        for(auto num : candidates){
            for(int bit = 0; bit < 32; ++bit){
                if(num & (1 << bit)) bitFreq[bit]++;
                maxGroup = max(maxGroup, bitFreq[bit]);
            }            
        }
        return maxGroup;
    }
};