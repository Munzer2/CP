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

ll get_max(ll val, vector< ll > a) {
    ll r_sum = 0, f = 0;
    ll best = 0; 
    for(ll i = 0 ;i < a.size(); ++i) {
        if(a[i] != 1 && a[i] != -1) {
            f = 0;
            r_sum = 0;
            continue;
        } 
        if(a[i] == val) {
            if(!f) {
                f = 1; 
            }
            r_sum += a[i];
            best = (val == 1 ? max(best, r_sum) : min(best, r_sum));
        }
        else {
            if(f) {
                if(val == 1) {
                    if(r_sum + a[i] > 0) r_sum += a[i];
                    else { 
                        f = 0;
                        r_sum = 0; 
                    }
                }
                else {
                    if(r_sum + a[i] < 0) r_sum += a[i]; 
                    else {
                        f = 0;
                        r_sum = 0; 
                    }
                }
            }
        }
    }
    if(f) {
        if(val == -1) best = min(best, r_sum) ; 
        else best = max(best, r_sum); 
    }
    return best; 
}

pair< ll, ll > get_max_min(vector< ll > a,ll side, ll ind) {
    ll _mx = 0, _mn = 0;
    ll run_s = 0;
    for(ll i = ind+side; i>= 0 && i < a.size(); i+= side) {
        run_s += a[i];
        _mx = max(_mx, run_s); 
        _mn = min(_mn, run_s);
    }
    return {_mx, _mn};
}


void solve() {
    ll n ; 
    cin >> n ; 
    vector< ll > a(n); 
    ll ind = -1;
    for(ll i = 0 ; i < n; ++i) { cin >> a[i]; if(a[i] != 1 && a[i] != -1) ind = i; } 
    vector< ll > ans; 
    if(1) {
        ll mx_min_1 = get_max(-1,a); 
        ll mx_1 = get_max(1,a);
        for(ll i = -1; i >= mx_min_1 ; --i) {
            ans.pb(i);
        }
        ans.pb(0); 
        for(ll i = 1; i <= mx_1; ++i) {
            ans.pb(i);  
        }
        if(ind == -1) {
            cout << ans.size() << "\n";
            sort(all(ans)); 
            debug_vector(ans);
            return;
        } 
    } 
    pair< ll, ll > p1 = get_max_min(a, 1, ind);
    pair< ll, ll > p2 = get_max_min(a, -1, ind);
    ll _mn = p1.second + p2.second + a[ind], _mx = p1.first + p2.first + a[ind]; 
    for(ll i = _mn ; i <= _mx; ++i) ans.pb(i); 
    sort(all(ans)); 
    auto new_end = unique(all(ans));
    ans.erase(new_end, ans.end());
    cout << ans.size() << "\n";
    debug_vector(ans); 
    return;
}

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

///accepted. Not a pretty solution. 