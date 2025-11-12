#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

vector<int> adj[MAXN];
vector<int> vis(100005);
vector<int> teams(100005);
bool impossible = false;

void dfs(int u, int team){
    vis[u] = 1;
    teams[u] = team;
    //cout << "chegou aqui 0" << endl;
    for(auto node : adj[u]){
        if(vis[node] == 0){
            if(team == 1) dfs(node, 2);
            else dfs(node, 1);
        }else if(teams[node] == team){
            impossible = true;
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

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i, 1);
        }
    }
    
    if(impossible) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i = 1; i <= n; i++){
            cout << teams[i] << " ";
        }
        cout << endl;
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}


