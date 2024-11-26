class Solution {
public:
    
    
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> deg(n + 1);
        for(auto i : edges) deg[i[1]]++;
        int winner = -1, cnt = 0;        
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 0){
                cnt ++;
                winner = i;
            }
        }
        return cnt == 1 ? winner : -1;
    }
};

