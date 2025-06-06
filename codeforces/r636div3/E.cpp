#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

void run_case() {
    int N, M, A, B, C;
    std::cin >> N >> M >> A >> B >> C;
    A -= 1;
    B -= 1;
    C -= 1;

    std::vector<int> P(M);
    for(int i = 0; i < M; i++) {
        std::cin >> P[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    auto bfs = [&](int st) {
        std::vector<int> dist(N, INF); 
        std::queue<int> q;
        
        q.push(st);
        dist[st] = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int v = q.front();
                q.pop();
                for(int nei : G[v]) {
                    if(dist[nei] == INF) {
                        dist[nei] = dist[v] + 1;
                        q.push(nei);
                    }
                }
            }
        }

        return dist;
    };

    std::vector<int> d_a = bfs(A);
    std::vector<int> d_b = bfs(B);
    std::vector<int> d_c = bfs(C);

    std::sort(P.begin(), P.end());
    std::vector<int64_t> psum(M + 1, 0);
    for(int i = 0; i < M; i++) {
        psum[i + 1] = psum[i] + P[i];
    }
    
    int64_t ans = int64_t(2e18);
    for(int v = 0; v < N; v++) {
        int tot = d_a[v] + d_b[v] + d_c[v];
        if(tot <= M) {
            int64_t cost = psum[d_b[v]] * 2 + psum[tot] - psum[d_b[v]];
            ans = std::min(ans, cost);
        }
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
