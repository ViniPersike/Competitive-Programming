#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAXN 200005

vector<int> adj[MAXN];
vector<int> subtree;

void dfs(int u, int p){
    subtree[u] = 1;

    for(int v : adj[u]){
        if(v != p){
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

void solve(){

    int n; cin >> n;
    subtree.assign(n+1, 0);

    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].emplace_back(i);
        adj[i].emplace_back(x);
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++){
        cout << subtree[i]-1 << " ";
    }
    cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}


