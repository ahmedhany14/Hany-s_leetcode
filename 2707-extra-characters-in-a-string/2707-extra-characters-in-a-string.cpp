class Solution {
public:
    int help(int i, int &n, string &b, unordered_set<string> &dictionary, vector<int> &dp) {
        if (i >= n)return 0;
        if (dp[i] != -1)return dp[i];
        int a = 1 + help(i + 1, n, b, dictionary, dp);
        string s = "";
        for (int j = i; j < n; j++) {
            s += b[j];
            if (dictionary.count(s)) {
                a = min(a, help(j + 1, n, b, dictionary, dp));
            }
        }
        return dp[i] = a;
    }

    int minExtraChar(string s, vector<string> &dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        unordered_set<string> st;
        for (auto &i: dictionary) {
            st.insert(i);
        }
        return help(0, n, s, st, dp);
    }
};
