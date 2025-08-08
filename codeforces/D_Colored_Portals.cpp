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


ll INF = 1e15; 

ll check(vector< ll >a, ll x, ll y){
    if(a.size() == 0) return INF;
    ll end = max(x,y); 
    ll strt = min(x,y); 
    ll c = lower_bound(all(a),end+1) - a.begin();
    ll d = lower_bound(all(a),strt) - a.begin();
    ll e = lower_bound(all(a),strt+1) - a.begin();
    if(a[e] > strt && a[e] < end) {
        return end-strt;
    }
    
    return 1; 
}





void solve()
{
    ll n, q; 
    cin >> n >> q; 
    vector< string > a(n);
    map< string, vector< ll > > mp; 
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]].pb(i); 
    }  
    while(q--){
        ll x,y; 
        cin >> x >> y; 
        x--; y--;
        string a1 = a[x], b = a[y];
        char c = a1[0], d = a1[1], e = b[0], f = b[1];
        if(c == d || c == e || d == e || d == f) cout << abs(x-y) << "\n"; 
        else{
            string poss;
            if(c > f ) { poss += f ; poss += c; }
            else { poss += c ; poss += f; }
            string poss1;
            if(d > e ) { poss1 += e ; poss1 += d; } 
            else { poss1 += d ; poss1 += e; }
            // check(mp[poss],x,y);
            // check(mp[poss1],x,y);
            check(mp[poss],x,y);
        }
    }
    return;  
}


void solve2(){

    vector< ll > a({1,1,2,3,5,6,9,10}); 
    cout << upper_bound(all(a),3) - a.begin() << "\n" ; 
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        // solve() ;
        solve2(); 
    }
    return 0 ;  
}