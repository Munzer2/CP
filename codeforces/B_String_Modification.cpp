#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define FAST() ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll check(string s, string pattern) { 
    ll n = s.size(); 
    for(ll i = 0; i < n ; ++i) { 
        string _s = "" , _c = ""; 
        _s += s.substr(i,n-i); 
        _c += s.substr(0,i);
        if((n-i)%2 == 0) _s += _c; 
        else {
            reverse(all(_c)); _s += _c ;
        }
        if(_s == pattern) {
            return i+1; 
        } 
    }
    return -1; 
}

void solve() {
    ll n ; 
    cin >> n ; 
    string s; cin >> s;
    vector< string > vect; 
    for(ll i = n-1; i >= 0; --i) {  
        string _s = "", _c = ""; 
        _s += s.substr(i,n-i); 
        _c += s.substr(0,i);
        if((n-i)%2 == 0) _s += _c; 
        else {
            reverse(all(_c)); _s += _c ;
        } 
        vect.push_back(_s); 
    } 
    sort(all(vect));
    // for(auto &s : vect) cout << s << "\n"; 
    ll k = check(s , vect[0]); 
    cout << vect[0] << "\n" << k << "\n";
    return;
}

int main() {
    FAST();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}