class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
        
        int l = 0, r = 1e9, best = 0;
        sort(position.begin(), position.end());
        auto can = [&](int dist) -> bool{
            int cnt = 1, last = position[0];  
            for(int i = 1; i < position.size(); ++i){
                if(cnt == m) break;
                if(position[i] - last >= dist){
                    ++cnt;
                    last = position[i];
                }
            }
            return cnt == m;
        };
        
        while(l <= r){
            int mid = (l + r) / 2;
            can(mid) ? best = mid, l = mid + 1 : r = mid - 1;
        }

        return best;
        
    }
};