class Solution {
public:
    int sp[503][30];
    void sparse_table(vector<int>&a, vector<vector<int>> &sp,int n) {
        for(int i = 0 ;i < n ;i++)
            sp[i][0] = a[i];
        for (int k = 1; k < 30; k++) 
            for (int j = 0; j + (1 << k) - 1 < n; j++)
                sp[j][k] = max(sp[j][k - 1], sp[j + (1 << (k - 1))][k - 1]);
    }
    int query(int l , int r, vector<vector<int>> &sp) {
        int k = 0;
        int len = r - l + 1;
        while ((1 << (k + 1)) <= len)k++;
        return max(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
    int help(int i, int n, int k, vector<int>&a, vector<int>&dp, vector<vector<int>> &sp){
        if(i >= n) return 0;
        if(~dp[i]) return dp[i];
        int me = 0;
        me = max(me, help(i + 1, n, k, a, dp, sp) + a[i]);
        for(int j = 1; j <= k; j++){
            int l = i, r = i + j;
            if(i + j <= n) me = max(me, help(r, n, k, a, dp, sp) + query(l, r - 1, sp) * (r - l));
        }
        return dp[i] = me;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int LOG = 0, n = arr.size();
        while (n) ++LOG, n >>= 1;
        vector<vector<int>> sp(arr.size(), vector<int>(LOG));
        vector<int> dp(arr.size(), -1);
        sparse_table(arr, sp, arr.size());
        int answer = help(0, arr.size(), k, arr, dp, sp);
        return answer;
    }
};