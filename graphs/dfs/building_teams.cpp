#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

vector<int> teams(100005);
vector<int> adj[MAXN];
vector<int> vis(100005];



void solve() { 

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

