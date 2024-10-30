#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define FillDp(Dp)  memset( Dp , -1 ,sizeof Dp)
#define all(s) (s).begin(), (s).end()
#define OO (1LL << 62)
#define ld long double 
#define ll int 
#define vc vector
#define fauto(x) for(auto &a : x)
#define endl '\n'
template < typename shap = int > istream& operator >> (istream& cin, vc < shap >& v) { for (auto& x : v) cin >> x; return cin; }
template < typename shap = int > ostream& operator << (ostream& cout, const vc < shap >& v) { for (const shap& x : v) cout << x << ' '; return cout; }
ll const N = 1e5 + 10;
vc<ll> constructlis(vc<ll>vec) { // get lis if i take element of vec[i]
	vector<ll> L, lis(vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		const ll num = vec[i];
		ll pos = lower_bound(L.begin(), L.end(), num) - L.begin();
		if (pos == L.size())L.push_back(num);
		else L[pos] = num;
		lis[i] = pos + 1;
	}
	return lis;
}
class Solution {
public:
    int minimumMountainRemovals(vector<int>& vec) {
    	ll s = vec.size();
	    vc <ll> v = constructlis(vec);
	    reverse(all(vec));
	    vc <ll> v2 = constructlis(vec);
	    ll l = 0, r = s - 1 ,mn = -1;
	    while (l < s) {
            if(v[l] > 1 and v2[r]> 1)mn = max(mn, (v[l] + v2[r]) - 1);
            l++;
            r--;
        }
        return s - mn;
    }
};