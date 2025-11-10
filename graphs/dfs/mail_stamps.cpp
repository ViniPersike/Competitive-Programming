#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 1000000005
#define int long long

unordered_map<int, vector<int>> adj;
unordered_map<int, int> vis;

void dfs(int u){
    vis[u] = 1;
    cout << u << " ";
    for(auto node : adj[u]){
        if(vis[node] == 0){
            dfs(node);
        }
    }
}

void solve(){
    int n; cin >> n;
    set<int> indexes;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        indexes.insert(a);
        indexes.insert(b);
    }
    for(auto num : indexes){
        if((int)adj[num].size() == 1){
            dfs(num);
            break;
        }
    }
    cout << endl << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}


