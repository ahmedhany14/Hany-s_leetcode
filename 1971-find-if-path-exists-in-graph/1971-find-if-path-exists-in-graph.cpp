class Solution {
public:
    bool ok = 0, vis[200005] = {};
    void dfs(int node, vector<vector<int>>& edges){
        vis[node] = 1;
        for(auto ch: edges[node]) if(!vis[ch]) dfs(ch, edges);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source ,graph);
        return vis[destination];
    }
};