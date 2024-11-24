class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long cnt = 0, sum = 0;
        int mn = 1e9;
        for(auto v: matrix){
            for(auto i: v){
                cnt += i < 0;
                sum += abs(i);
                mn = min(mn, abs(i));
            }
        }
        if(cnt & 1) sum -= 2 * mn;
        return sum;
    }
};