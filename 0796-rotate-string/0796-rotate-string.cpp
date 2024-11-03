class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        int cnt = s.size();
        while(cnt--){
            string p = "";
            p += s.back();
            s.pop_back();
            s = p + s;
            if(s == goal) return true;
        }
        return false;
    }
};