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

ll calc(string s){
    ll sum = 0;
    stack< ll > st;
    for(ll i = 0 ; i < s.size(); ++i){
        if(s[i] == '(') st.push(i);
        else{
            ll d = st.top();
            st.pop();
            sum += (i-d);
        }
    }
    return sum; 
}

void solve()
{
    ll n ; 
    cin >> n ; 
    vector< vector< char > > a(2,vector< char > (n));
    for(ll i = 0 ; i < 2; i++){
        for(ll j = 0 ; j < n; ++j) cin >> a[i][j];
    }
    ll cnt = 0;
    for(ll i = 0 ; i < 2; ++i){
        for(ll j = 0 ; j < n ; ++j){
            if(a[i][j] == '.' && j < n-1 && j > 0  && a[(i+1)%2][j+1] == 'x' && a[(i+1)%2][j-1] == 'x' && a[i][j-1] == '.' && a[i][j+1] == '.'){
                cnt++;
                // cout << i << " " << j << "\n";
            } 
        }
    }
    cout << cnt << "\n";
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
