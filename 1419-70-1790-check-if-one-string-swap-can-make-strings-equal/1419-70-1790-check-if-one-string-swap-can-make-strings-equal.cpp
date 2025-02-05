class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> ids;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i])ids.push_back(i);
            if(ids.size() > 2) return 0;
        }
        if(!ids.size()) return 1;
        if(ids.size() != 2) return 0;
        if(s1[ids[0]] == s2[ids[1]] and s1[ids[1]] == s2[ids[0]]) return 1;
        return 0;
    }
};