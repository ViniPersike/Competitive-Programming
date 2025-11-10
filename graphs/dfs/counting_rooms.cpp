#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define MAXN 1000

vector<pii> grid = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(int nx, int ny, int n, int m){
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

char matriz[MAXN][MAXN];
int vis[MAXN][MAXN];
int components = 0;

void dfs(int x, int y, int n, int m){
    vis[x][y] = 1;
    
    for(auto [xx, yy] : grid){
        int nx = x + xx;
        int ny = y + yy;
        if(check(nx, ny, n, m)){
            if(vis[nx][ny] == 0 && matriz[nx][ny] == '.'){
                dfs(nx, ny, n, m);
            }
        }
    }
}

void solve(){
    vector<pii> dots;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            matriz[i][j] = c;
            if(c == '.'){
                dots.emplace_back(i, j);
            }
        }
    }

    for(auto [u, v] : dots){
        if(vis[u][v] == 0){
            components++;
            dfs(u, v, n, m);
        }
    }
    
    cout << components << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}


