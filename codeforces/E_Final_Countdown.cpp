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

void find_divs(ll n, vector< ll > &divs) {
    for(ll i = 1; i*i <= n; ++i){
        if(n%i == 0){
            if(n == i*i){
                divs.push_back(i); 
            }
            else{
                divs.push_back(i); 
                divs.push_back(n/i);  
            }
        } 
    }
    return; 
}

void solve()
{
    ll n; 
    cin >> n;
    string s; 
    cin >> s; 
    ll cnt =0, sum = 0;
    for(ll i = n-2; i >= 0; --i){
        cnt += (s[i] - '0'); 
        sum += (s[i] - '0')*(n-i);
    }
    cout << sum << "\n";
    sum -= cnt;
    string d = to_string(sum); 
    cout << d << "\n";
    return;
}

int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}