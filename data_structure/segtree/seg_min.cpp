#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define INF 1000000005

struct segTree{
    ll merge(ll a, ll b) {return min(a,b);}
    const ll neutral = INF;
    inline int lc(int p) {return 2*p;}
    inline int rc(int p) {return 2*p+1;}
    int n;
    vector<ll> t;

    void build(int p, int l, int r, const vector<ll> &v){
        if(l == r){
            t[p] = v[l];
        }else{
            int mid = (l+r) / 2;
            build (lc(p), l, mid, v);
            build (rc(p), mid+1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void build(int _n){
        n = _n;
        t.assign(4*n, neutral);
    }
    void build(const vector<ll> &v){
        n = (int)v.size();
        t.assign(4*n, neutral);
        build(1, 0, n-1, v);
    }

    ll query(int p, int l, int r, int L, int R){
        if(l > R || r < L) return neutral;
        if(l >= L && r <= R) return t[p];
        int mid = (l+r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid+1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) {return query(1, 0, n-1, l, r);}

    void update(int p, int l, int r, int i, ll x){
        if(l == r){
            t[p] = x;
        }else{
            int mid = (l+r)/2;
            if(i <= mid) update(lc(p), l, mid, i, x);
            else update(rc(p), mid+1, r, i, x);
            t[p] = merge(t[lc(p)], t[rc(p)]); 
        }
    }
    void update(int i, ll x) {update(1, 0, n-1, i, x);}
}seg;

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    segTree st;
    st.build(v);
    for(int i = 0; i < m; i++){
        int q; cin >> q;
        if(q == 1){
            int index, value; cin >> index >> value;
            st.update(index, value);
        }else{
            int l, r; cin >> l >> r;
            ll ans = st.query(l, r-1);
            cout << ans << endl;
        }
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

