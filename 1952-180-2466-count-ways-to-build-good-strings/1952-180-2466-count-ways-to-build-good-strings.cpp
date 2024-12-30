class Solution {
public:
    vector<int> dp;
    int mod = 1000000007;

    int help(int rem, int zero, int one){
        if(rem == 0) return 1;

        if(~dp[rem]) return dp[rem];

        int me = 0;
        if(rem - one >= 0) me += help(rem - one, zero, one) % mod;
        if(rem - zero >= 0) me += help(rem - zero, zero, one) % mod;

        return dp[rem] = me % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1);
        int answer = 0;
        for(int i = low; i <= high; ++i) {
            answer += help(i, zero, one);
            answer %= mod;
        }
        return answer;
    }
};