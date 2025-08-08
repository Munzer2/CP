#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
#define fs first
#define sc second
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}



ll n; 
vector< ll >a; 

pair< ll, pair< ll, ll >> check(ll strt, ll end){
    ll neg = 0;
    for(ll i = strt; i <= end; ++i) if(a[i] < 0) neg++;
    if(neg%2 == 0){
        ll tot = 0;
        for(ll i = strt ; i <= end; ++i) if(abs(a[i]) == 2) tot++ ; 
        return {tot,{strt,end}};
    }
    ll tot1 = 0, tot2 = 0;
    ll fir_neg = -1, lst_neg = -1;
    for(ll i = strt ; i <= end; ++i) if(a[i] < 0) { fir_neg = i ; break;  }
    for(ll i = end; i >= strt; --i) if(a[i] < 0) { lst_neg = i; break;  }
    for(ll i = strt; i < lst_neg; ++i) if(abs(a[i]) == 2) tot1++ ; 
    for(ll i = end; i> fir_neg; --i) if(abs(a[i]) == 2) tot2++;
    if(tot1 > tot2) {
        return {tot1,{strt, lst_neg-1}}; 
    }
    else return { tot2,{fir_neg+1,end}};
}


void solve()
{
    cin >> n ; 
    ll z = 0; 
    a.resize(n);
    for(ll i = 0 ; i < n; ++i){
        cin >> a[i];
        if(a[i] == 0) z++;
    }
    if(z == 0){
        pair< ll, pair< ll, ll>> ans = check(0,n-1);
        cout << ans.sc.fs << " " << n-1-ans.sc.sc << "\n";
        return; 
    } 
    pair< ll, pair< ll, ll >> ans = {-1, {-1,-1}};
    ll mx = 0;
    ll lst = -1;
    for(ll i = 0; i <= n; ++i){
        if(i == n || a[i] == 0){
            if(lst != i-1){
                pair< ll, pair< ll,ll>> curr = check(lst+1,i-1);
                // debug_vector(curr);
                if(mx < curr.fs){
                    mx = curr.fs;
                    ans = curr; 
                }
            }
            lst = i;
        }
    }
    if(ans.fs == -1) cout << n << " 0\n"; 
    else cout << ans.sc.fs << " " << n-1-ans.sc.sc << "\n"; 
    return; 
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}


///Dont ever pass a huge vector or array as parameter to a function.Accepted.