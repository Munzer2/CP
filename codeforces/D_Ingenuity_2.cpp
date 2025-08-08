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


ll check(ll p1,ll p2){
    ll d = abs(p1-p2); 
    return (d%2 ? 0 : 1); 
}

ll check2(string &s){
    ll h_cnt= 0, r_cnt = 0;
    for(ll i = 0; i < s.size(); ++i){
        if(s[i] == 'H') h_cnt++; 
        else r_cnt++; 
    }
    return !(r_cnt == 0 || h_cnt == 0);
}
map< char, vector< ll > > ind;
ll t1 = 0; 

void func(string &s, map< char, ll >& mp, char c1, char c2){
    ll d = min(mp[c1], mp[c2]);
    for(ll i = 0 ; i< d;++i){
        ll ind1 = ind[c1][i]; 
        ll ind2 = ind[c2][i]; 
        if(t1%2 == 0) {
            s[ind1] = s[ind2] = 'H';
        }
        else s[ind1] = s[ind2] = 'R';
        t1++;
    }
    char x = (mp[c1] > mp[c2] ? c1 : c2);
    for(ll i = d; i < ind[x].size(); ++i){
        ll index = ind[x][i];
        if(i%2) s[index] = 'R'; 
        else s[index] = 'H';
    }
    return;
}



void solve()
{
    ll n; 
    cin >> n ; 
    string s; 
    cin >> s; 
    map< char, ll > mp; 
    for(auto x : s ) mp[x]++;
    for(ll i =0 ; i < s.size(); ++i ){
        ind[ s[i] ].push_back(i); 
    }
    if(check(mp['N'],mp['S']) && check(mp['E'],mp['W'])){
         func(s,mp,'N','S');
         func(s,mp,'E','W');
        //  cout << s << "\n"; 
         if(check2(s)) cout << s << "\n"; 
         else cout << "NO\n";  
    }
    else cout << "NO\n";

    ind['S'].clear(); 
    ind['N'].clear(); 
    ind['E'].clear(); 
    ind['W'].clear(); 
    
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