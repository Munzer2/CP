#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll Mod = 1e9 + 7;

void solve()
{
    ll n ; 
    cin >> n ; 
    vector< ll > a(n); 
    for(auto &c : a ) cin >> c; 
    sort(all(a));
    ll cnt = 1;
    vector< ll > ans;
    while(cnt <= 40){
        ll mx = a[n-1], mn = a[0];
        ll avg = (mx + mn)/2;
        ans.pb(avg);
        for(ll i = 0 ; i < n; ++i){
            a[i] = abs(a[i] - avg);
        }
        sort(all(a));
        if(a[0] == a[n-1] && a[0] == 0) break;
        cnt++;
    }
    if(a[0] != a[n-1]) cout << "-1\n"; 
    else 
    {
        cout << ans.size() << "\n"; 
        debug_vector(ans);
    }
    return;
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted. 
