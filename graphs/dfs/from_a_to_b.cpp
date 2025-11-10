#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define int long long

deque<int> path;
bool found = false;

void dfs(int u, int target){
    if(found || u > target) return;

    path.push_back(u);
    
    dfs(2*u, target);
    dfs(10*u + 1, target);

    if(u == target){
        found = true;
        return;
    }
    
    if(!found) path.pop_back();
}

void solve() { 

    int a, b; cin >> a >> b;
    dfs(a, b);

    if(!found) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << (int) path.size() << endl;
        for(auto v: path){
            cout << v << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
