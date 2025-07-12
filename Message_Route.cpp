#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
    return;
}

vector<ll> vis;
vector<vector<ll>> edges;

void dfs(ll curr)
{
    if (vis[curr])
        return;
    vis[curr] = 1;

    for (auto c : edges[curr])
        dfs(c);
    return;
}

void bfs(ll n)
{
    vector<ll> dist(n + 1, 0);
    vector<ll> _v(n + 1, 0);
    vector<ll> pred(n + 1);
    queue<ll> q;
    q.push(1);
    _v[1] = 1; 
    while (!q.empty())
    {
        ll d = q.front();
        q.pop();
        if (d == n) break;
        for (auto c : edges[d])
        {
            if (!_v[c])
            {
                _v[c] = 1; 
                dist[c] = dist[d] + 1;
                pred[c] = d;
                q.push(c);
            }
        }
    }
    cout << dist[n] + 1<< "\n";
    ll curr = n;
    vector< ll > ans ; 
    for (;;)
    {
        ans.pb(curr); 
        if (curr == 1)
            break;
        curr = pred[curr];
    }
    for(ll i = ans.size()-1; i>= 0; --i) cout << ans[i] << " "; 
    cout << "\n"; 
    return;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    edges.resize(n + 1);
    for (ll i = 0; i < m; ++i)
    {
        ll x, y;
        cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    vis.resize(n + 1, 0);

    dfs(1);

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    bfs(n); 
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}


//// only bfs needed actually.