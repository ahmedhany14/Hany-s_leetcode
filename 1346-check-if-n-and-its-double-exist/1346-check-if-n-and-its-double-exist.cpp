class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto i : arr) mp[i]++;
        for(auto i : arr) {
            mp[i]--;
            if(mp[i * 2]) return 1;
            mp[i]++;
        }
        return 0;
    }
};