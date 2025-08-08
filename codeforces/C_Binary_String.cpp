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
string s ; 


ll check(ll k, vector< ll > &ind, vector< ll > &pre){
    if(ind.size()<= k) return 1;
    // debug_vector(ind);
    for(ll i = 0 ; i <= ind.size()-k; ++i){
        ll L = ind[i], R = ind[i+k-1];
        ll left = (i > 0 ? ind[i-1]:-1);
        ll right = (i+k <= ind.size()-1 ? ind[i+k]:-1);
        right = (right == -1 ? pre.back(): pre[right]); 
        left = (left == -1 ? 0  : pre[left]);
        ll ones = pre.back() - right + left;
        if(ones <= k) return 1;
    }
    return 0;
}


void check2(){
    return;
}


void solve()
{
    cin >> s;
    vector< ll > ind;
    vector< ll > pre(s.size(), 0);
    for(ll i = 0 ; i < s.size(); ++i){
        if(s[i] == '0') { ind.push_back(i); pre[i] = (i == 0 ? 0 : pre[i-1]); }
        else{
            pre[i] = (i == 0 ? 1 : pre[i-1] + 1);
        } 
    }
    // debug_vector(ind);
    // debug_vector(pre);
    ll l = 0, h = s.size();
    ll cnt = 0;
    while(l < h){
        ll mid = (l+h)/2;
        if(check(mid,ind,pre)){
            h = mid;
        }
        else{
            l = mid+1;
        }
        // cout << l << " " << h << "\n";
    }
    cout << l << "\n"; 
    // check(2,ind, pre);
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