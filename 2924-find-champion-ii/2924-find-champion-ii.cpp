class Solution {
public:
    vector<int>adj[101];
    
    int dfs(int node, vector<int>& mark){
        int me = 0;
        mark[node] = 1;
        for(auto child: adj[node]) {
            if(!mark[child])
                me += dfs(child, mark) + 1;
        }
        return me;
    }
    
    int findChampion(int n, vector<vector<int>>& edges) {
        for(auto i : edges) adj[i[0]].emplace_back(i[1]);
    
        for(int i = 0; i < n; ++i) {
            vector<int> mark(n + 1);
            if(dfs(i, mark) + 1 == n) return i;
        }
        return -1;
    }
};

