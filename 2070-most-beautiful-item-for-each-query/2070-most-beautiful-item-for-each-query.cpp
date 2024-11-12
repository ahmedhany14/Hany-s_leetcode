class Solution {
public:
    bool cmp (vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return b[1] < a[1];
        return b[0] < a[0];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> answer;
        vector<int> maxBeauty;
        int mx = 0;
        for(auto i : items){
            mx = max(i[1], mx);
            maxBeauty.push_back(mx);
        }
        for(auto q: queries){
            int l = 0, r = items.size() - 1, best = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(items[mid][0] <= q){
                    best = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(!~best) 
                answer.push_back(0);
            else 
                answer.push_back(maxBeauty[best]);
        }
        return answer;
    }
};