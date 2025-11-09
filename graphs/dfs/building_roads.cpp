#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 100005
#define int long long
 
vector<int> adj[MAXN];
vector<int> vis(MAXN+1);
int components = 0;
 
void dfs(int u){
    vis[u] = 1;
    
    for(auto v : adj[u]){
        if(vis[v] == 0){
            dfs(v);
        }
    }
}
 
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    vector<pair<int, int>> ans; 
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
            components++;
            if(i != 1){
                ans.emplace_back(i-1, i);
            }
        }
    } 
    cout << components-1 << endl;
    for(auto [a,b] : ans){
        cout << a << " " << b << endl;
    }
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
 
