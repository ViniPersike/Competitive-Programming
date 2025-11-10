#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

vector<int> adj[MAXN];
vector<int> vis(MAXN);
vector<pair<int, int>> leaves_A;
vector<pair<int, int>> leaves_B;

void dfs(int u, int steps, int player){
    vis[u] = 1;
    //cout << "nodo atual: " << u << "numero de passos até aqui " << steps << " "; 
    if(adj[u].size() == 1 && u != 1){
        if(player == 1){
      //      cout << "ACHEI UMA FOLHA " << u << endl;
            leaves_A.emplace_back(u, steps);
        }else{
            leaves_B.emplace_back(u, steps);
        }
    }
    
    steps++;
    for(auto node : adj[u]){
        if(vis[node] == 0){
            dfs(node, steps, player);
        }
    }
}

void solve() { 

    int n, x; cin >> n >> x;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    dfs(1, 0, 1);
    
    vis.assign(MAXN, 0);
    
    dfs(x, 0, 2);

    sort(leaves_A.rbegin(), leaves_A.rend());
    sort(leaves_B.rbegin(), leaves_B.rend());

    int ans = 0;

    for(int i = 0; i < (int) leaves_A.size(); i++){
        if(leaves_A[i].second > leaves_B[i].second){
            ans = max(ans, 2*leaves_A[i].second);
        }
    }
    cout << ans << endl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

