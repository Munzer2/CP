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



void solve()
{
    ll n; 
    cin >> n ; 
    vector< ll > a(n); 
    ll s = 0;
    for(auto &x: a ) { cin >>x; s+=x; }
    map< ll ,ll >mp;
    vector< ll > ans(n,0); 
    ll curr = 0;
    for(ll i = 0 ; i<n; ++i){
        if(mp[a[i]] == 1 && a[i] > curr){
            curr = a[i];
        }
        ans[i] = curr;
        mp[a[i]]++; 
    } 
    // debug_vector(ans);
    map< ll, ll > check;
    ll cnt = n-1;
    curr = 0;
    for(ll i = 0 ; i <n; ++i) check[ans[i]]++;
    for(ll i = 1; i < n; ++i){
        if(check[ans[i]] == 1){
            s += ((cnt-1)*curr + ans[i]);
        }
        else{
            curr = ans[i];
            s += (cnt*curr);
        }
        cnt--;
    } 
    cout << s << "\n";
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