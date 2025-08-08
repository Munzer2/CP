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

ll check_square(ll x){
    ll c = sqrt(x); 
    return (x == c*c);
}

ll count(vector< ll > &a, ll val){
    // cout << "Vector: "; 
    // debug_vector(a);
    ll c = lower_bound(all(a),val)-a.begin();
    ll d = upper_bound(all(a), val) - a.begin();
    // cout << c << " " << d << "\n";
    return d-c; 
}


void solve()
{
    ll n; 
    cin >> n; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    // map< ll, vector< ll > > mp; 
    sort(all(a));
    ll q; 
    cin >> q; 
    while(q--){
        ll x,y; 
        cin >> x >> y;
        ll ans = 0; 
        ll check = x*x - 4*y; 
        if((check < 0) || !(check_square(check))) {  cout << "0 "; continue;}
        ll det = sqrt(check);
        ll a_i = (x + det)/2, a_j = (x-det)/2; ///Now we need to find these in the sorted array. Or count the number of occcurences.
        if(a_i == a_j){
            ll c = count(a,a_i);
            ans += (c*(c-1))/2;
        }
        else{
            ans += (count(a,a_i)*count(a,a_j));
        }
        cout << ans << " "; 
    }
    cout << endl;  
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
///accepted. Good problem.