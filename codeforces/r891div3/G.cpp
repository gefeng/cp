#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t MOD = (int64_t)998244353;

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;

    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }

    int find(int i) {
        if(p[i] < 0) {
            return i;
        } 
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }

        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }

    int size(int i) {
        return w[find(i)];
    }
};

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;

    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        } 
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    
    return res;
}

void run_case() {
    int N, S;
    std::cin >> N >> S;

    std::vector<std::array<int, 3>> E(N - 1);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U -= 1;
        V -= 1;

        E[i] = {U, V, W}; 
    }
    
    std::sort(E.begin(), E.end(), [](const auto& a, const auto& b) {
        return a[2] < b[2];
    });

    dsu uf(N);
    int64_t ans = 1;
    for(auto& e : E) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        int64_t sz_u = uf.size(u);
        int64_t sz_v = uf.size(v);

        ans *= q_pow(S - w + 1, sz_u * sz_v - 1);
        ans %= MOD;

        uf.unite(u, v);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
