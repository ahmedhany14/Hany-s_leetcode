#define ll long long 
class Solution {
public:
    int minimumSize(vector<int>& v, int op) {
        auto can = [&](ll number)->bool {
            ll cnt = op;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] <= number)continue;
                if (v[i] % number == 0) {
                    ll k = v[i];
                    ll o = v[i] / number - 1;
                    if (o <= cnt)
                        cnt -= o;
                    else return 0;
                }
                else {
                    ll o = v[i] / number;
                    if (o <= cnt)
                        cnt -= o;
                    else return 0;
                }
            }
            return 1;
        };
        ll l = 1, r = 1e9, ans = 0;
        while (l<=r){
            ll mid = l + (r - l) / 2;
            if (can(mid))ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};