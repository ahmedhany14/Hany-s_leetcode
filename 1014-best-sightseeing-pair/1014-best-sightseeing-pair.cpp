class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxScore = 0;
        int maxLeft = values[0] + 0;
        for(int j = 1; j < n; j++) {
            maxScore = max(maxScore, maxLeft + values[j] - j);
            maxLeft = max(maxLeft, values[j] + j);
        }
        return maxScore;
    }
};