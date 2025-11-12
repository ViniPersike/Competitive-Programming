#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

<<<<<<< HEAD
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
=======
vector<int> teams(100005);
vector<int> adj[MAXN];
vector<int> vis(100005];



void solve() { 

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
>>>>>>> 8d7849bc4118cf73434f9a268ff473cc9596f5a0
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
<<<<<<< HEAD

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


=======
    
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

>>>>>>> 8d7849bc4118cf73434f9a268ff473cc9596f5a0
