class Solution {
public:
    
    int dfs(int node, vector<int>& mark, vector<vector<int>>& adj){
        int me = 0;
        mark[node] = 1;
        for(auto child: adj[node]) {
            if(!mark[child])
                me += dfs(child, mark, adj) + 1;
        }
        return me;
    }
    
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for(auto i : edges) adj[i[0]].emplace_back(i[1]);
    
        for(int i = 0; i < n; ++i) {
            vector<int> mark(n + 1);
            if(dfs(i, mark, adj) + 1 == n) return i;
        }
        return -1;
    }
};

