#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll check_sum(vector< ll > a, vector< ll > check) {
	if(check.size() == 0) return -1;
	ll j = a.size()-1, i = 0, f= 0, ans = 0;
	while(i < check.size() && j >= 0) {
		if(a[j] > check[i]) {
			ans += check[i];
			i++;
			j--;
			f ^= 1;
		}
		else break;
	}
	for(ll d = j; d >= 0; --d) ans += a[d]; 
	if(!f) {
		ans += check[0];
		ans -= a.back(); 
	}
	return ans; 
}

void solve() {
    ll n,l,r; 
    cin >> n >> l >> r;
    vector< ll > a(n),b,c,d; 
    for(auto &x : a) cin >> x; 
    for(ll i = l-1; i < r; ++i) b.pb(a[i]); 
    for(ll i = r; i < n; ++i) c.pb(a[i]); 
    for(ll i = 0; i < l-1; ++i) d.pb(a[i]);
    sort(all(b)); sort(all(c)); sort(all(d));
    cout << check_sum(b,c) << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}