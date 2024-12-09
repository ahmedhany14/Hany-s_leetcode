class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& num, vector<vector<int>>& queries) {
        vector<int> same_parity;
        for(int i = 0; i < num.size() - 1; ++i)
            if((num[i] & 1) == (num[i + 1] & 1)) same_parity.push_back(i + 1);
        
        vector<bool> answer;
        for(auto a : queries){
            int st = a[0] + 1, ed = a[1];
            int l = 0, r =  same_parity.size() - 1;
            bool ok = true;
            while(l <= r){
                int mid = (l + r) / 2;
                
                if(same_parity[mid] >= st and same_parity[mid] <= ed){
                    ok = false;
                    break;
                }
                
                if(same_parity[mid] < st) l = mid + 1;
                else r = mid - 1;
            }
            
            answer.push_back(ok);
        }
        return answer;
    }
};