#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define pii pair<int, int>
#define MAXN 505

vector<pii> grid = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[MAXN][MAXN];
char maze[MAXN][MAXN];
int count_dots = 0;
int cnt = 0;

bool check(int nx, int ny, int n, int m){
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
}


bool dfs(int x, int y, int n, int m, int k){
    vis[x][y] = 1;
    cnt++;

    if(cnt == count_dots - k) return true;

    for(auto [xx, yy] : grid){
        int nx = x+xx, ny = y+yy;
        if(check(nx, ny, n, m) && maze[nx][ny] == '.'){
            if(vis[nx][ny] == 0){
                if(dfs(nx, ny, n, m, k)) return true;
            }
        }
    }
    return false;
}
void solve() { 
    int startx, starty;
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '.') {
                count_dots++;
                startx = i;
                starty = j;
            }
        }
    }

    dfs(startx, starty, n, m, k);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == '.' && vis[i][j] != 1) cout << 'X';
            else cout << maze[i][j];
        }
        cout << endl;
    }
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

