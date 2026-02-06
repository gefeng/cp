#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <bit>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int F;
    std::cin >> F;
    std::vector<int> A(F);
    std::vector<int> has_car(F, 1);
    std::vector<std::vector<int>> live(N);
    for(int i = 0; i < F; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        live[A[i]].push_back(i);
    }

    int K;
    std::cin >> K;
    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
        B[i] -= 1;
        has_car[B[i]] = 0;
    }

    std::vector<std::vector<int>> vis(1 << K, std::vector<int>(N, INF));
    std::vector<int> dist(N, INF);
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    vis[0][0] = 0;
    dist[0] = 0;

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [m, v] = q.front();
            q.pop();
             
            for(int u : G[v]) {
                dist[u] = std::min(dist[u], dist[v] + 1);
                int nm = m;
                for(int i = 0; i < K; i++) {
                    if(A[B[i]] == u) {
                        nm |= 1 << i;
                    }
                }
                if(vis[nm][u] > vis[m][v] + 1) {
                    vis[nm][u] = vis[m][v] + 1;
                    q.emplace(nm, u);
                }
            }
        }
    }

    std::vector<std::vector<int>> dp(1 << K, std::vector<int>(F, 0));
    for(int v = 1; v < N; v++) {
        for(int m = 0; m < (1 << K); m++) {
            if(!vis[m][v] || vis[m][v] != dist[v]) {
                continue;
            }
            for(int x : live[v]) {
                if(has_car[x]) {
                    dp[m][x] = 1;             
                }
            } 
        }
    }

    std::vector<int> ds(1 << K, 0);
    ds[0] = 1;
    for(int i = 0; i < F; i++) {
        std::vector<int> nds(ds);
        for(int sm = 0; sm < (1 << K); sm++) {
            if(dp[sm][i]) {
                for(int m = 0; m < (1 << K); m++) {
                    if(ds[m]) {
                        nds[m | sm] = 1;
                    }
                }
            }
        }
        ds = std::move(nds);
    }

    int ans = 0;
    for(unsigned int m = 0; m < (1 << K); m++) {
        if(ds[m]) {
            ans = std::max(ans, std::popcount(m));
        }
    }
    ans = K - ans;

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
