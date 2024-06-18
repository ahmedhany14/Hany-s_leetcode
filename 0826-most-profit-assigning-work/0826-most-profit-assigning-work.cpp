class Solution {
public:
    int sp[(int)1e4 + 10][30];
    int a[(int)1e4 + 10];
    void sparse_table(int n) {
       for(int i = 0 ;i < n ;i++) 
         sp[i][0] = a[i];
       for (int k = 1; k < 30; k++) 
         for (int j = 0; j + (1 << k) - 1 < n; j++)
           sp[j][k] = max(sp[j][k - 1], sp[j + (1 << (k - 1))][k - 1]);
    }

    int query(int l , int r) {
      int k = 0;
       int len = r - l + 1;
       while ((1 << (k + 1)) <= len) k++; 
       return max(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;
        int n = (int)profit.size(), m = (int)worker.size();
        for(int i = 0;i < n; ++i) p.emplace_back(difficulty[i], profit[i]);
        sort(p.begin(), p.end());
        for(int i = 0;i < n; ++i) a[i] = p[i].second;
        sparse_table(n);
        auto get_upper = [&](int i)->int{
            int l = 0, r = n - 1, best = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(p[mid].first <= worker[i]) best = mid, l = mid + 1;
                else r = mid - 1;
            }
            return best;
        };
        int answer = 0;
        for(int i = 0;i < m; i++){
            int high = get_upper(i);
            if(~high) answer += query(0, high);
        }
        return answer;
    }
};