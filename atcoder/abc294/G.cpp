#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

struct fenwick_tree {
    int n;
    std::vector<LL> t;

    fenwick_tree(int _n) : n(_n + 1) {
        t.resize(n, 0LL);
    }

    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            t[i] += v;
        }
    }

    LL query(int i) {
        LL res = 0LL;
        for(++i; i > 0; i -= i & -i) {
            res += t[i];
        }
        return res;
    }

    LL query(int l, int r) {
        return query(r) - query(l - 1);
    }
};



void dfs(std::vector<std::vector<std::array<int, 3>>>& G, int v, int p, 
         std::vector<int>& et, std::vector<int>& in_v, std::vector<int>& v_to_i,
         std::vector<int>& in_e, std::vector<int>& out_e) {
    in_v[v] = et.size();
    v_to_i[v] = et.size();
    et.push_back(v);

    for(auto& nei : G[v]) {
        if(nei[0] != p) {
            in_e[nei[2]] = et.size();

            dfs(G, nei[0], v, et, in_v, v_to_i, in_e, out_e);

            out_e[nei[2]] = et.size();
            et.push_back(v);
        }
    }
}

struct seg_tree {
    const int INF = (int)2e9;

    int n;
    int m;
    int h;

    std::vector<int> t;

    seg_tree(int _n) : n(_n) {
        m = highest_one_bit(std::max(1, n - 1)) << 2; 
        h = m / 2;
        t.resize(m, INF);
    }

    seg_tree(const std::vector<int>& v) : seg_tree(v.size()) {
        for(int i = 0; i < n; i++) {
            t[i + h] = v[i];
        }

        for(int i = h - 1; i > 0; i--) {
            propagate(i);
        }
    }

    // handy function from java library
    int highest_one_bit(int i) {
        i |= (i >> 1);
        i |= (i >> 2);
        i |= (i >> 4);
        i |= (i >> 8);
        i |= (i >> 16);
        return i - (i >> 1);
    }

    void propagate(int i) {
        t[i] = std::min(t[2 * i], t[2 * i + 1]);
    }

    void add(int i, int v) {
        t[i + h] = v;
        
        for(int j = (i + h) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int query(int l, int r) {
        int res = INF;
        for(int i = l + h, j = r + h; i <= j; i >>= 1, j >>= 1) {
            if(i % 2 == 1) {
                res = std::min(res, t[i++]);
            } 
            if(j % 2 == 0) {
                res = std::min(res, t[j--]);
            }
        } 

        return res;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::array<int, 3>>> G(N);
    std::vector<int> E_W(N - 1);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U -= 1;
        V -= 1;

        G[U].push_back({V, W, i});
        G[V].push_back({U, W, i});
        E_W[i] = W;
    }

    std::vector<int> et;  // euler tour
    std::vector<int> in_v(N);  // save the timestamp of first visiting v
    std::vector<int> v_to_i(N); 
    std::vector<int> in_e(N - 1);
    std::vector<int> out_e(N - 1);

    dfs(G, 0, -1, et, in_v, v_to_i, in_e, out_e);
    
    int sz = et.size();
    fenwick_tree ft(sz);
    seg_tree rmq(sz);

    std::vector<int> t_to_v(sz);
    for(int i = 0; i < N; i++) {
        t_to_v[in_v[i]] = i;
    }

    for(int i = 0; i < sz; i++) {
        rmq.add(i, in_v[et[i]]);
    }

    for(int i = 0; i < N - 1; i++) {
        ft.update(in_e[i], E_W[i]);
        ft.update(out_e[i], -E_W[i]);
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int I, W;
            std::cin >> I >> W;
            I -= 1;
            
            int d = W - E_W[I];
            E_W[I] = W;
            ft.update(in_e[I], d);
            ft.update(out_e[I], -d);
        } else {
            int U, V;
            std::cin >> U >> V;

            U -= 1;
            V -= 1;

            int i = v_to_i[U];
            int j = v_to_i[V];
            if(i > j) {
                swap(i, j);
            }

            int lca = t_to_v[rmq.query(i, j)];

            LL ans = ft.query(i) + ft.query(j) - 2LL * ft.query(v_to_i[lca]);
            std::cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
