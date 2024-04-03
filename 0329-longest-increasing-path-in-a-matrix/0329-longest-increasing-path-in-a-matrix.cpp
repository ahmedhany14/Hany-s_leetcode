class Solution {
public:
    int m , n, ret;
    vector<vector<vector<int> > >  dp;
    vector<vector<int>> a;
    int help(int i, int j, int change){
        if(i >= n | j >= m | i < 0 | j < 0) return 0;
        int &me = dp[i][j][change];
        if(~me) return me;
        me = 0;
        bool ok = 0;
        if(change == 0) ok = (a[i][j] > a[i - 1][j]);
        if(change == 1) ok = (a[i][j] > a[i + 1][j]);
        if(change == 2) ok = (a[i][j] > a[i][j - 1]);
        if(change == 3) ok = (a[i][j] > a[i][j + 1]);

        if(change == 4 || ok){
            me = max(me, 1 + help(i + 1,j, 0));
            me = max(me, 1 + help(i - 1,j, 1));
            me = max(me, 1 + help(i ,j + 1, 2));
            me = max(me, 1 + help(i ,j - 1, 3));
        }
        return me;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        a = matrix;
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(m, vector<int>(5, -1)));

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                ret = max(ret, help(i, j, 4));
        return ret;
    }
};