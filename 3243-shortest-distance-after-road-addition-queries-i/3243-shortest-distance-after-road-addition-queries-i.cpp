class Solution {
public:
    
    int bfs(int n, vector<vector<int>> &adj){
        

        priority_queue<pair<int, int>> q;
        vector<int>distance(n + 1, 1e9);
        q.push({0, 0});
        while(q.size()){
            auto [cost, node] = q.top();
            q.pop();
            for(auto child: adj[node]){
                if(distance[child] > cost + 1){
                    distance[child] = cost  + 1;
                    q.push({distance[child], child});
                }
            }
        }
        
        return distance[n - 1];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n - 1; ++i) adj[i].emplace_back(i + 1);
    
        vector<int> answer;
        for(auto bridge: queries){
            int u = bridge[0], v = bridge[1];
            adj[u].emplace_back(v);
            int shortest_path = bfs(n, adj);
            answer.push_back(shortest_path);
        }
        
        return answer;
    }
};