class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size()){
            return {};
        }
        vector<int> temp;
        vector<vector<int>> ret;
        int total_adj = m;
        for(int i = 0;i < m * n and total_adj; ++i){
            temp.emplace_back(original[i]);
            if(temp.size() == n){
                ret.emplace_back(temp);
                temp.clear();
                total_adj--;
            }
        }
        return ret;
    }
};