#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = int(2e5);
constexpr int64_t MOD = int64_t(998244353);

std::vector<std::map<int, int>> pf(MAX + 1);
std::vector<int64_t> inv(MAX + 1);

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

void dfs1(std::vector<std::vector<std::array<int, 3>>>& G, std::vector<int>& vis, std::map<int, int>& m1, std::map<int, int>& m2, std::map<int, int>& m, int v, int a, int b) {
    vis[v] = 1; 
    
    std::map<int, int> ma;
    std::map<int, int> mb;
    std::map<int, int> tmp1;
    std::map<int, int> tmp2;
        
    if(a != -1) {
        for(auto [x, f] : pf[a]) {
            if(pf[b].find(x) != pf[b].end()) {
                int d = std::min(f, pf[b][x]);
                if(f > d) {
                    ma[x] = f - d; 
                }
            } else {
                ma[x] = f;
            }
        } 

        for(auto [x, f] : pf[b]) {
            if(pf[a].find(x) != pf[a].end()) {
                int d = std::min(f, pf[a][x]);
                if(f > d) {
                    mb[x] = f - d;
                }
            } else {
                mb[x] = f;
            }
        }

        for(auto [x, f] : ma) {
            tmp1[x] = m1[x];
            if(m2.find(x) != m2.end()) {
                int d = std::min(f, m2[x]);
                tmp2[x] = m2[x];
                m2[x] -= d;
                m1[x] += f - d;
            } else {
                m1[x] += f;
            }
        }

        for(auto [x, f] : mb) {
            tmp2[x] = m2[x];
            if(m1.find(x) != m1.end()) {
                int d = std::min(f, m1[x]);
                tmp1[x] = m1[x];
                m1[x] -= d;
                m2[x] += f - d;
                m[x] = std::max(m[x], m2[x]);
            } else {
                m2[x] += f;
                m[x] = std::max(m[x], m2[x]);
            }
        }
    }

    for(auto& nei : G[v]) {
        if(!vis[nei[0]]) {
            dfs1(G, vis, m1, m2, m, nei[0], nei[2], nei[1]);
        }
    }

    if(a != -1) {
        for(auto [x, f] : ma) {
            if(m2.find(x) != m2.end()) {
                m2[x] = tmp2[x];
            } else {
                m1[x] += f;
            }
            m1[x] = tmp1[x];
        }
        for(auto [x, f] : mb) {
            if(m1.find(x) != m1.end()) {
                m1[x] = tmp1[x];
            }
            m2[x] = tmp2[x];
        }
    }
}

void dfs2(std::vector<std::vector<std::array<int, 3>>>& G, std::vector<int>& vis, int v, int a, int b, int64_t x, int64_t& ans) {
    vis[v] = 1;
    if(a != -1) {
        x *= int64_t(a) * inv[b] % MOD;
        x %= MOD;
    }

    ans += x;
    ans %= MOD;

    for(auto& nei : G[v]) {
        if(!vis[nei[0]]) {
            dfs2(G, vis, nei[0], nei[2], nei[1], x, ans);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::array<int, 3>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, A, B;
        std::cin >> U >> V >> A >> B;
        U -= 1;
        V -= 1;
        G[U].push_back({V, A, B});
        G[V].push_back({U, B, A});
    }

    std::map<int, int> m1;
    std::map<int, int> m2;
    std::map<int, int> m;
    std::vector<int> vis(N, 0);
    dfs1(G, vis, m1, m2, m, 0, -1, -1);

    int64_t x = 1;
    for(auto [v, f] : m) {
        for(int i = 0; i < f; i++) {
            x *= v; 
            x %= MOD;
        }
    }
    //std::cout << x << '\n';

    int64_t ans = 0;
    vis = std::vector<int>(N, 0);
    dfs2(G, vis, 0, -1, -1, x, ans);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        inv[i] = q_pow(i, MOD - 2);
        
        int x = i;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int cnt = 0;
                while(x % f == 0) {
                    cnt += 1;
                    x /= f;
                }
                pf[i][f] = cnt;
            }
        }
        if(x > 1) {
            pf[i][x] = 1;
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
