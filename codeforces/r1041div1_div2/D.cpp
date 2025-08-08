#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

bool bipartite(std::vector<std::vector<int>>& G, int v, int c, int p, std::vector<int>& color) {
    color[v] = c;

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        if(color[nei] == -1) {
            if(!bipartite(G, nei, c ^ 1, v, color)) {
                return false;
            }
        } else if(color[nei] == c) {
            return false;
        }
    }
    return true;
}

bool cycle(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& vis) {
    vis[v] = 1;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        if(vis[nei] == 1) {
            return true;
        }
        if(vis[nei] == 0) {
            if(cycle(G, nei, v, vis)) {
                return true;
            }
        }
    }
    vis[v] = 2;
    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        degree[U] += 1;
        degree[V] += 1;
    }

    // check bipartite
    std::vector<int> color(N, -1);
    if(!bipartite(G, 0, 0, -1, color)) {
        std::cout << 0 << '\n';
        return;
    } 

    // check cycle
    std::vector<int> vis(N, 0);
    if(cycle(G, 0, -1, vis)) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int64_t ans = 1;
    std::vector<int> a;
    std::vector<int> b;
    for(int v = 0; v < N; v++) {
        int cnt = 0;
        for(int nei : G[v]) {
            if(degree[nei] > 1) {
                cnt += 1;
            } 
        }
        if(cnt > 2) {
            std::cout << 0 << '\n';
            return;
        }

        if(color[v] == 0) {
            a.push_back(v);
        } else {
            b.push_back(v);
        }
    } 

    int cnt_a = 0;
    int cnt_b = 0;
    cnt_a = std::ranges::count_if(a, [&](int v) {
                return degree[v] > 1;
            });
    cnt_b = std::ranges::count_if(b, [&](int v) {
                return degree[v] > 1;
            });

    if(std::min(cnt_a, cnt_b)) {
        ans = 2;
    }
    ans *= 2;
    ans %= MOD;
    
    for(int v = 0; v < N; v++) {
        int size = G[v].size();
        int cnt = 0;
        for(int nei : G[v]) {
            if(degree[nei] > 1) {
                cnt += 1;
            }
        }
        ans *= fact[size - cnt];
        ans %= MOD;
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
