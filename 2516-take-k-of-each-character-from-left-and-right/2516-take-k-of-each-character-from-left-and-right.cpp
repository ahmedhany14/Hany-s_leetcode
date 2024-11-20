class Solution {
public:
    
    bool have_k(map<char, int>& f, int& k){
        if(f['a'] >= k and f['c'] >= k and f['b'] >= k) return 1;
        return 0;
    }
    bool can(int& mid, string& s, int& k){
        int skip = s.size() - mid;
        map<char,int> f;
        for(int i = skip; i < s.size(); ++i) f[s[i]]++;
        if(have_k(f, k)) return 1;
        int l = 0, r = skip;
        while(r < s.size()){
            f[s[l++]]++;
            f[s[r++]]--;
            if(have_k(f, k)) return 1;
        }
        return 0;
    }
    
    int takeCharacters(string s, int k) {
        int l = 0, r = s.size() , best = -1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if(can(mid, s, k)) {
                best = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return best;
    }
};