class Solution {
public:
    
    bool pile_spliting(vector<int>& quantities,int min_max, int temp_n){
        for(auto i : quantities){
            temp_n -= ceil(i * 1.0 / min_max);
        }
        return temp_n >= 0;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e9, best = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            pile_spliting(quantities, mid, n) ?  r = mid - 1, best = mid : l = mid + 1;
        }
        return best;
    }
};