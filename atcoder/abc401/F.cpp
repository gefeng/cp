#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs_1(std::vector<std::vector<int>>& G, int v, int p, int d, std::vector<int>& dist) {
    dist[v] = d;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs_1(G, nei, v, d + 1, dist);
        }
    }
}

void dfs_2(std::vector<std::vector<int>>& G, int v, int p, std::vector<std::pair<int, int>>& lp) {
    for(int nei : G[v]) {
        if(nei != p) {
            dfs_2(G, nei, v, lp);
            if(lp[nei].first + 1 > lp[v].first) {
                lp[v].second = lp[v].first;
                lp[v].first = lp[nei].first + 1;
            } else if(lp[nei].first + 1 > lp[v].second) {
                lp[v].second = lp[nei].first + 1;
            }
        }
    }
}

void dfs_3(std::vector<std::vector<int>>& G, int v, int p, std::vector<std::pair<int, int>>& lp) {
    if(p != -1) {
        int best_p = lp[p].first == lp[v].first + 1 ? lp[p].second + 1 : lp[p].first + 1;
        if(best_p > lp[v].first) {
            lp[v].second = lp[v].first;
            lp[v].first = best_p;
        } else if(best_p > lp[v].second) {
            lp[v].second = best_p;
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs_3(G, nei, v, lp);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> G_1(N);

    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G_1[U].push_back(V);
        G_1[V].push_back(U);
    }

    int M;
    std::cin >> M;
    std::vector<std::vector<int>> G_2(M);

    for(int i = 0; i < M - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G_2[U].push_back(V);
        G_2[V].push_back(U);
    }
    
    std::vector<int> dist_1(N, 0);
    std::vector<int> dist_2(M, 0);
    int x = -1;
    int max_d = -1;
    int d_1 = 0;
    int d_2 = 0;
    dfs_1(G_1, 0, -1, 0, dist_1);

    for(int i = 0; i < N; i++) {
        if(dist_1[i] > max_d) {
            max_d = dist_1[i]; 
            x = i;
        }
    }

    dfs_1(G_1, x, -1, 0, dist_1);
    for(int i = 0; i < N; i++) {
        d_1 = std::max(d_1, dist_1[i]);
    }

    dfs_1(G_2, 0, -1, 0, dist_2);
    x = -1;
    max_d = -1;
    for(int i = 0; i < M; i++) {
        if(dist_2[i] > max_d) {
            max_d = dist_2[i];
            x = i;
        }
    }

    dfs_1(G_2, x, -1, 0, dist_2);
    for(int i = 0; i < M; i++) {
        d_2 = std::max(d_2, dist_2[i]);
    }

    std::vector<std::pair<int, int>> lp_1(N, {0, 0});
    std::vector<std::pair<int, int>> lp_2(M, {0, 0});
    std::vector<int64_t> psum(M + 1, 0);
    dfs_2(G_1, 0, -1, lp_1);
    dfs_2(G_2, 0, -1, lp_2);

    dfs_3(G_1, 0, -1, lp_1);
    dfs_3(G_2, 0, -1, lp_2);
    
    std::sort(lp_2.begin(), lp_2.end());
    for(int i = 0; i < M; i++) {
        psum[i + 1] = psum[i] + lp_2[i].first;
    }

    int64_t ans = 0;
    int d = std::max(d_1, d_2);
    for(int i = 0; i < N; i++) {
        int x = lp_1[i].first;
        
        int p = std::upper_bound(lp_2.begin(), lp_2.end(), d - x - 1, [](int v, const auto& a) {
                    return v < a.first;
                }) - lp_2.begin();
        
        int64_t l = p;
        int64_t r = M - p;
        ans += d * l;
        ans += (x + 1) * r + psum[M] - psum[p];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
