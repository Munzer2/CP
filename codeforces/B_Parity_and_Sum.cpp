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
    cin >> n; 
    vector< ll > a(n);
    vector< ll > ev;
    ll mx = -1;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0 ; i < n; ++i){
        if(a[i]%2) mx = max(mx,a[i]);
        else{
            ev.pb(a[i]);
        }
    }
    if(mx == -1 || ev.size() == 0){ 
        cout << "0\n";
        return;
    }
    sort(all(ev)); 
    // ll ans = ev.size();
    // ll i = 0, j = ev.size()-1;
    // while(i<=j){
    //     if(ev[i]<mx){
    //         mx += ev[i];
    //         i++;
    //     }
    //     else{
    //         ans++;
    //         mx = 2*a[j] + mx;
    //         j--;
    //         break;
    //     }
    // }
    // cout << ans << "\n";
    ll ans = 0;
    ll i = 0, j= ev.size()-1;
    // debug_vector(ev);
    while(i <= j){
        if(ev[i] < mx){
            ans++;
            mx += ev[i];
            i++;
        }
        else{
            ans+=2;
            mx = 2*ev[j] + mx;
            j--;
        }
        // cout << mx << "\n";
    }
    cout << ans << "\n";
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