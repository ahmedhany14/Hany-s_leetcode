class Solution {
public:
    vector<int> dp;

    int help(int rem){
        if(rem <= 0) return rem == 0 ? 0 : 1e9;
        int me = 1e9;
        if(~dp[rem]) return dp[rem];
        for(int i = 1; i <= 100; i++) me = min(me, help(rem - i * i) + 1);
        return dp[rem] = me;
    }
    int numSquares(int n) {
        dp.resize(n + 1, -1);
        return help(n);
    }
};