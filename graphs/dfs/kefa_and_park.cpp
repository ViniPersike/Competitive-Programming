#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

vector<int> has_cat;
vector<int> adj[MAXN];
vector<int> vis;
int ans = 0;

void dfs(int u, int cat_count, int max_cats){

    vis[u] = 1;

    if(has_cat[u] == 1) cat_count++;
    else cat_count = 0;
    if(cat_count > max_cats) return;

    if(adj[u].size() == 1 && cat_count <= max_cats && u != 1) ans++;

    for(auto node : adj[u]){
        if(vis[node] == 0){
            dfs(node, cat_count, max_cats);
        }
    }

}

void solve() { 
    int n, m; cin >> n >> m;
    vis.assign(n+1, 0);
    has_cat.emplace_back(0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        has_cat.emplace_back(x);
    }
    
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    dfs(1, 0, m); 
    cout << ans << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

