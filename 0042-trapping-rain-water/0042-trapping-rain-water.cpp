#define ll long long 
#define lli long long int
#define ld long double 
#define str string 
#define ulli unsigned long long int
#define vc vector
#define all(s) (s).begin(), (s).end()
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define endl '\n'
#define OO 200000000
class Solution {
public:
    int trap(vector<int>& v) {
        ll s = v.size();
        vc<int> pre(s),mxl(s), mxr(s);
        int m = 0;
        for (int i = s - 1; i >= 0; i--) {
            m = max(m, v[i]);
            mxr[i] = m;
        }
        m = 0;
        for (int i = 0; i < s - 1; i++) {
            m = max(m, v[i]);
            mxl[i] = m;
        }

        for (int i = 0; i < s - 1; i++) pre[i] = min(mxl[i], mxr[i]);
        ll ans = 0;
        for (int i = 1; i < s - 1; i++) ans += max(0, pre[i] - v[i]);
        return ans;
    }
};