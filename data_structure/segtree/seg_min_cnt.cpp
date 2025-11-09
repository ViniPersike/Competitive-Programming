#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define pli pair<ll,int>
#define INF 1000000005

struct segTree{
    pli merge(pli a, pli b){
        if(a.first == b.first){
            return {a.first, a.second+b.second};
        }
        if(a.first < b.first) {return a;}
        return b;
    }
    pli neutral = {INF, 0};
    int lc(int p) {return 2*p;}
    int rc(int p) {return 2*p+1;}
    int n;
    vector<pli> t;

    void build(int p, int l, int r, const vector<pli> &v){
        if(l == r){
            t[p] = v[l];
        }else{
            int mid = (l+r)/2;
            build(lc(p), l, mid, v);
            build(rc(p), mid+1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    
    void build(int _n){
        n = _n;
        t.assign(4*n, neutral);
    }

    void build(const vector<pli> &v){
        n = (int) v.size();
        t.assign(4*n, neutral);
        build(1, 0, n-1, v);
    }

    pli query(int p, int l, int r, int L, int R){
        if(l > R || r < L) return neutral;
        if(l >= L && r <= R) return t[p];
        int mid = (l+r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid+1, r, L, R);
        return merge(ql, qr);
    }
    pli query(int l, int r) {return query(1, 0, n-1, l, r);}
    
    void update(int p, int l, int r, ll x, int i){
        if(l == r){
            t[p] = {x, 1};
        }else{
            int mid = (l+r) / 2;
            if(i <= mid) {update(lc(p), l, mid, x, i);}
            else {update(rc(p), mid+1, r, x, i);}
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }   
    }
    void update(ll x, int i) {return update(1, 0, n-1, x, i);}
}seg;

void solve(){
    int n, m; cin >> n >> m;
    segTree st;
    vector<pli> v(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v[i] = make_pair(a, 1);
    }
    st.build(v);
    for(int i = 0; i < m; i++){
        int q; cin >> q;
        if(q == 1){
            int index, value; cin >> index >> value;
            st.update(value, index);
        }else{
            int l, r; cin >> l >> r;
            auto [valor, freq] = st.query(l, r-1);
            cout << valor << " " << freq << endl;
        }
    }

}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

