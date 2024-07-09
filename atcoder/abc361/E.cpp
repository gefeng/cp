#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = (int64_t)2e18;

void dfs1(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, std::vector<int64_t>& dp1) {
    for(auto [nei, w] : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, dp1);
            dp1[v] = std::max(dp1[v], dp1[nei] + w);
        }
    } 
}

void dfs2(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int wp, std::vector<int64_t>& dp1, std::vector<std::pair<int64_t, int64_t>>& dp2) {
    int64_t max1 = 0;
    int64_t max2 = 0;
    for(auto [nei, w] : G[v]) {
        if(nei != p) {
            int64_t x = dp1[nei] + w;
            if(x > max1) {
                max2 = max1;
                max1 = x;
            } else if(x > max2) {
                max2 = x;
            }
        }
    }

    if(p != -1) {
        int64_t x = (max1 + wp == dp2[p].first ? dp2[p].second : dp2[p].first) + wp;
        if(x > max1) {
            max2 = max1;
            max1 = x;
        } else if(x > max2) {
            max2 = x;
        }
    }

    dp2[v].first = max1;
    dp2[v].second = max2;
    
    for(auto [nei, w] : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v, w, dp1, dp2);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    int64_t sum = 0;
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);

        sum += W * 2;
    }
     
    // std::vector<int64_t> dp1(N, 0);
    // std::vector<std::pair<int64_t, int64_t>> dp2(N, {0, 0});
    // dfs1(G, 0, -1, dp1);
    // dfs2(G, 0, -1, 0, dp1, dp2);
    // 
    // int64_t ans = INF;
    // for(int i = 0; i < N; i++) {
    //     ans = std::min(ans, sum - dp2[i].first); 
    // }
    
    auto bfs = [&](int root, std::vector<int64_t>& dist) {
        std::queue<int> q;
        q.push(root);
        dist[root] = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int v = q.front();
                q.pop();
                
                for(auto [nei, w] : G[v]) {
                    if(dist[nei] == -1) {
                        dist[nei] = dist[v] + w;
                        q.push(nei);
                    }
                }
            }
        } 
    };

    std::vector<int64_t> dist(N, -1);
    bfs(0, dist);
    int a = -1;
    int64_t max_d = 0;
    for(int i = 0; i < N; i++) {
        if(dist[i] > max_d) {
            max_d = dist[i];
            a = i;
        }
    }

    dist.assign(N, -1);
    bfs(a, dist);
    max_d = 0;
    for(int i = 0; i < N; i++) {
        max_d = std::max(max_d, dist[i]);
    }

    std::cout << sum - max_d << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
