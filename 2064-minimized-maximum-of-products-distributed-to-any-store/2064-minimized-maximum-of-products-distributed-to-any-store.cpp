class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int l = 1, r = *max_element(quantities.begin(), quantities.end()), best = 0;
        while(l <= r){
            int mid = (l + r) / 2, temp_n = n;
            for(auto i : quantities) temp_n -= ceil(i * 1.0 / mid);
            temp_n >= 0 ?  r = mid - 1, best = mid : l = mid + 1;
        }
        return best;
    }
};