class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> vis(n);
        vector<pair<long long,long long>> p(n);
        long long ret = 0, idx = 1;

        for(auto i : roads) vis[i[0]]++, vis[i[1]]++;
        for(int i = 0;i < n;++i) p[i] = {vis[i], i};
        sort(p.begin(), p.end());
        for(auto [l, r] : p) ret += l * idx++;
        return ret;
    }
};