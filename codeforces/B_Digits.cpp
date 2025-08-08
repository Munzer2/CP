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

void check_7(ll n,ll d,vector< ll > &ans) {
    if(d == 7) {
        ans.pb(7); 
        return; 
    }
    if(n >= 3) ans.pb(7);
    return; 
}

void solve() {
    ll n, d ; 
    cin >> n >> d;
    vector< ll > ans; 
    ans.pb(1); 
    if(d == 3 || d == 9 || d == 6) ans.pb(3);
    else{ 
        if(n >= 3) ans.pb(3);
    }
    if(d == 5 ) ans.pb(5);
    check_7(n,d,ans);
    if(d == 9) ans.pb(9); 
    else{
        if(d == 3 || d == 6) {
            if(n >= 3) ans.pb(9); 
        }
        else if(n >= 6) ans.pb(9);
    }
    sort(all(ans));
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


///accepted. Good problem.