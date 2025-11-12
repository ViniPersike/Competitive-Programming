#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 100005
#define int long long

set<int> l;
set<int> r;
vector<int> adj[MAXN];
vector<int> vis(MAXN);

void dfs(int u, char color){
    vis[u] = 1;
    
    if(color == 'l') l.insert(u);
    else r.insert(u);

    for(auto node : adj[u]){
        if(vis[node] == 0){
            if(color == 'l') dfs(node, 'r');
            else dfs(node, 'l');
        }
    }
}

void solve() { 

    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    dfs(1, 'l');

    cout << (int)l.size()*(int)r.size() - (n-1) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

