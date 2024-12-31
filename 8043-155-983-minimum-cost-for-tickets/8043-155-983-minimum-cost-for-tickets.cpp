class Solution {
public:
    int n;
    vector<int> days_T, cost_T;
    vector<vector<int>> dp;
    int help(int i, int days) {
        if (i == n) return 0;

        if (~dp[i][days])return dp[i][days];

        int me = 1e9;
        if (days < days_T[i]) 
            me = min({
                me,
                help(i + 1, days_T[i] ) + cost_T[0],
                help(i + 1, days_T[i] + 6) + cost_T[1],
                help(i + 1, days_T[i] + 29) + cost_T[2]
            });
        else me = min(me, help(i + 1, days));

        return dp[i][days] = me;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();

        dp = vector<vector<int>>(n, vector<int>(450, -1));

        days_T = days;
        cost_T = costs;

        return help(0 , 0);
    }

};