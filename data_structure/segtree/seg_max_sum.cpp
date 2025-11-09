#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct segTree{
    ll merge(ll a, ll b){
        maior = max(maior, (a+b));
        cout << "MERGE FEITO -> MAIOR = " << maior << endl;
        cout << "a = " << a << " " << "b = " << b << endl;
        return a+b;
    }
    ll neutral = 0;
    inline int lc(int p) {return 2*p;}
    inline int rc(int p) {return 2*p+1;}
    int n;
    ll maior = neutral;
    vector<ll> t;

    void build(int p, int l, int r, const vector<ll> &v){
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
    void build(const vector<ll> &v){
        n = (int)v.size();
        t.assign(4*n, neutral);
        build(1, 0, n-1, v);
    }
    
    ll query(int p, int l, int r, int L, int R){
        if(l > R || r < L) return neutral;
        if(l >= L && r <= R) return t[p];
        int mid = (l+r)/2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid+1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) {return query(1, 0, n-1, l, r);}

    void update(int p, int l, int r, ll x, int i){
        if(l == r){
            t[p] = x;
        }else{
            int mid = (l+r)/2;
            if(i <= mid) update(lc(p), l, mid, x, i);
            else update(rc(p), mid+1, r, x, i);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void update(ll x, int i) {return update(1, 0, n-1, x, i);}

    void ans(){
        cout << maior << endl;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    segTree st;
    st.build(v);
    st.ans();
    for(int i = 0; i < m; i++){
        int index, value; cin >> index >> value;
        st.update(value, index);
        st.ans();
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

