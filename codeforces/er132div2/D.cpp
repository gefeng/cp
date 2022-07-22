#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int highestOneBit(unsigned int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (i >> 1);
}

vector<int> st;
int N = 0, M = 0, H = 0;

void propagate(int i) {
    st[i] = max(st[2 * i], st[2 * i + 1]);
}

void build(int n) {
    N = n;
    M = highestOneBit(max(1, N - 1)) << 2;
    H = M >> 1;

    st.resize(M, 0);
}

void build(const vector<int>& v) {
    build(v.size());

    for(int i = 0; i < N; i++) {
        st[i + H] = v[i];
    }

    for(int i = H - 1; i > 0; i--) {
        propagate(i);
    }
}

void update(int i, int v) {
    st[i + H] = v;
    for(int j = i + H >> 1; j > 0; j >>= 1) {
        propagate(j);         
    }
}

int query(int l, int r) {
    int res = 0;
    for(l += H, r++, r += H; l < r; l >>= 1, r >>= 1) {
        if(l & 1) {
            res = max(res, st[l++]);
        }
        if(r & 1) {
            res = max(res, st[--r]);
        }
    }
    return res;
}

void run_case() {
    int n = 0;
    int m = 0;
    int q = 0;
    vector<array<int, 5>> Q;

    cin >> n >> m;
    build(m);
    for(int i = 0; i < m; i++) {
        int x = 0;
        cin >> x;
        update(i, x);
    } 
    
    cin >> q;
    Q.resize(q);
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> Q[i][j];
        } 
    }

    for(int i = 0; i < q; i++) {
        int sx = Q[i][1];
        int dx = Q[i][3];
        int sy = Q[i][0];
        int dy = Q[i][2];
        int k = Q[i][4];
        int d_h = abs(sx - dx);
        int d_v = abs(sy - dy);
        int max_h = query(min(sx, dx), max(sx, dx) - 2);
        
        bool res = false;
        if(d_h < 2 || max_h < n) {
            int min_d = max_h - sy + 1;
            int steps = (min_d + k - 1) / k;
            res = d_h % k == 0 && d_v % k == 0 && steps * k <= n - sy;
        }

        cout << (res ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    run_case();
}
