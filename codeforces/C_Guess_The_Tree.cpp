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


void print(vector< pair< ll, ll >> edges){
    cout << "! " ; 
    for(ll i = 0 ; i < edges.size(); ++i){
        cout << edges[i].first << " " << edges[i].second << " ";
    }
    cout << endl;
}


void solve()
{
    ll n ; 
    cin >> n ;
    ll end = 2;
    vector< pair< ll , ll >> edges; 
    while(1){
        if(end > n){
            print(edges);
            break;
        }
        ll strt = 1;
        while(1){
            cout << "? " << strt << " " << end << "\n"; 
            cout.flush();
            ll x; 
            cin >> x; 
            if(x == strt){
                edges.push_back({strt,end}); 
                break; 
            }
            else strt = x;
        }
        end++;
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

//accepted.