#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
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


void solve()
{
    ll n , m ; 
    cin >> n >> m; 
    vector< vector< char > > a(n,vector<char>(m));
    for(ll i = 0 ; i < n ; ++i ) {
        for(ll j = 0 ;j < m ; ++j ) cin >> a[i][j]; 
    }
    ll prev = 0;
    ll row = 0;  
    for(ll i = 0; i < n; ++i){
        ll str_cnt = 0;
        for(ll j = 0 ; j < m; ++j){
            if(a[i][j] == '#' ) str_cnt++;
        }
        if(str_cnt > prev){
            prev = str_cnt; 
            row = i;
        }
        else if(str_cnt < prev){
            row = i-1; 
            break;
        }
    }
    ll cnt =0 ;
    for(ll i = 0 ; i < m ; ++i){
        if(a[row][i] == '#'){
            cnt++;
            if(cnt == prev/2 + 1){
                cout << row + 1 << " " << i+1 << "\n"; 
                break; 
            } 
        }
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