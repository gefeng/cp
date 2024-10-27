#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int LOG = 30;

int dfs1(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& farthest, std::vector<int>& sec_farthest, 
        std::vector<int>& depth) {
    int d_1 = 0;
    int d_2 = 0;
    if(p != -1) {
        depth[v] = depth[p] + 1;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            int max_d = dfs1(G, nei, v, farthest, sec_farthest, depth);
            if(max_d > d_1) {
                d_2 = d_1;
                d_1 = max_d;
            } else if(max_d > d_2) {
                d_2 = max_d;
            }
        }
    }
    
    farthest[v] = d_1;
    sec_farthest[v] = d_2;
    
    return d_1 + 1;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& farthest, std::vector<int>& sec_farthest, 
        std::vector<std::vector<int>>& up, std::vector<std::vector<int>>& dp) {
    if(p != -1) {
        up[0][v] = p;
        dp[0][v] = 1 + (farthest[p] == farthest[v] + 1 ? sec_farthest[p] : farthest[p]);
        for(int i = 1; i <= LOG; i++) {
            up[i][v] = up[i - 1][up[i - 1][v]];
            dp[i][v] = std::max(dp[i - 1][v], dp[i - 1][up[i - 1][v]] + (1 << (i - 1)));
        }
    } else {
        dp[0][v] = farthest[v];
        for(int i = 1; i <= LOG; i++) {
            dp[i][v] = farthest[v];
        }
    }


    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v, farthest, sec_farthest, up, dp);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> farthest(N, 0);
    std::vector<int> sec_farthest(N, 0);
    std::vector<int> depth(N, 0);
    dfs1(G, 0, -1, farthest, sec_farthest, depth);
    //std::cout << farthest[0] << ' ' << sec_farthest[0] << '\n';

    std::vector<std::vector<int>> up(LOG + 1, std::vector<int>(N, 0));
    std::vector<std::vector<int>> dp(LOG + 1, std::vector<int>(N, 0));
    dfs2(G, 0, -1, farthest, sec_farthest, up, dp);

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int V, K;
        std::cin >> V >> K;
        V -= 1;
        
        int res = farthest[V];
        int jump = std::min(depth[V], K);
        int v = V;
        int d = 0;
        for(int j = LOG; j >= 0; j--) {
            if(jump & (1 << j)) {
                res = std::max(res, dp[j][v] + d);
                v = up[j][v];
                d += 1 << j;
            }
        }
        
        std::cout << res << " \n"[i == Q - 1];
    }
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
