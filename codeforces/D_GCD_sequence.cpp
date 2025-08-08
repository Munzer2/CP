#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}


ll remove_imb_and_check(vector< ll > a, vector< ll > check, ll ind){
    if(ind-1 < 0) check[ind] = -1;
    else if(ind+1 >=a.size() ) check[ind-1] = 1e15;
    else {
        check[ind] = check[ind-1] = gcd(a[ind-1], a[ind+1]); 
    }
    // debug_vector(check); 
    return is_sorted(check.begin(), check.end()); 
}


void solve()
{
    ll n; 
    cin >> n; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x;
    vector< ll > check(n-1);
    for(ll i = 1; i < n; ++i) check[i-1] = gcd(a[i], a[i-1]);
    // cout << "The vector: " ; debug_vector(check); 
    if(is_sorted(check.begin(), check.end())) {
        cout << "YES\n"; 
        return; 
    }
    vector< ll > all_imb; 
    for(ll i = 0; i < n-2; ++i){
        if(check[i] > check[i+1])
        {
            all_imb.push_back(i);
        }
    }
    if(all_imb.size() > 2 ) { cout << "NO\n"; return;  }
    if(all_imb.size() ==2  && all_imb[1] - all_imb[0] > 2) { cout << "NO\n"; return; }
    for(ll i = all_imb[0]; i <= all_imb[0] + 2; ++i){
        if(remove_imb_and_check(a,check, i)) 
        {
            cout << "YES\n"; 
            return; 
        }
    }
    cout << "NO\n"; 
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
///accepted. phew. 1400 rated. 