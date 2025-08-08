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

ll check(map< ll, ll > mp, map< ll, ll > mp1) {
    ll check = 1; 
    // cout << "----\n";
    for(auto &x : mp) {
        // cout << x.first << " " << x.second << " " << mp1[x.first] << "\n";  
        if(x.second > mp1[x.first]) {
            check  =  0;
            break; 
        }
    }
    return check;
}

void solve() {
    ll n ; 
    cin >> n; 
    vector< ll > a(n);
    for(auto &x: a) cin >> x; 
    map< ll, ll > mp,mp1;
    mp[1] = 1; 
    mp[0] = 3;
    mp[3] = 1; 
    mp[2] = 2;
    mp[5] = 1;
    for(ll i = 0 ;i < n; ++i) {
        mp1[a[i]]++;
        ll d = check(mp, mp1);
        if(d) {
            cout << i+1 << "\n"; 
            return; 
        }
    }
    cout << "0\n"; 
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

///accepted.