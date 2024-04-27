#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    int n = int(std::sqrt(N));
    std::vector<std::unordered_set<int>> G(N);
    std::unordered_set<int> heavy;
    std::unordered_map<int64_t, int> m;

    auto on_heavy = [&](int v) {
        for(int u : G[v]) {
            for(int x : heavy) {
                if(G[x].find(u) != G[x].end()) {
                    int a = std::min(v, x);
                    int b = std::max(v, x);
                    m[int64_t(a) * N + b] = u;
                }
            }
        } 
    };

    auto update = [&](int v, int t) {
        for(int u : heavy) {
            if(u == v) {
                continue;
            }
            if(G[u].find(t) != G[u].end()) {
                int a = std::min(v, u);
                int b = std::max(v, u);
                m[int64_t(a) * N + b] = t;
            }
        } 
    };

    int k = 0;
    for(int i = 0; i < Q; i++) {
        int T, A, B;
        std::cin >> T >> A >> B;
        T = 1 + ((int64_t(T) * (1 + k) % MOD) % 2);
        A = 1 + ((int64_t(A) * (1 + k) % MOD) % N);
        B = 1 + ((int64_t(B) * (1 + k) % MOD) % N);
        A -= 1;
        B -= 1;

        //std::cout << T << ' ' << A << ' ' << B << '\n';

        if(T == 1) {
            G[A].insert(B);
            G[B].insert(A); 
            if(G[A].size() - 1 == n) {
                on_heavy(A);
                heavy.insert(A);
            }
            if(G[B].size() - 1 == n) {
                on_heavy(B);
                heavy.insert(B);
            }
            if(heavy.find(A) != heavy.end()) {
                update(A, B);
            }
            if(heavy.find(B) != heavy.end()) {
                update(B, A);
            }
        } else {
            if(A > B) {
                std::swap(A, B);
            }

            int res = 0;
            if(G[A].size() <= n) {
                for(int v : G[A]) {
                    if(G[B].find(v) != G[B].end()) {
                        res = v + 1;
                        break;
                    }
                }
            } else if(G[B].size() <= n) {
                for(int v : G[B]) {
                    if(G[A].find(v) != G[A].end()) {
                        res = v + 1;
                        break;
                    }
                }
            } else {
                int64_t h = int64_t(A) * N + B;
                if(m.find(h) != m.end()) {
                    res = m[h] + 1;
                }
            }

            k = res;
            std::cout << res << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
