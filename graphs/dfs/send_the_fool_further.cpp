#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 105
#define int long long

vector<pair<int,int>> adj[MAXN];
vector<int> vis(101);
int ans = 0;

void dfs(int u, int cost){
    vis[u] = 1;
    ans = max(ans, cost);
    
    for(auto [node, c] : adj[u]){
        if(vis[node] == 0){
            dfs(node, cost+c);
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(0, 0);
    cout << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}


