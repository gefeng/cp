#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 7;

int dfs(int N, int H, int W, std::vector<int>& A, std::vector<std::vector<int>>& G, std::vector<std::vector<std::pair<int, int>>>& pos, 
        int i, int r, int c, std::vector<std::vector<std::vector<int>>>& dp) {
    if(r == H || c == W || i == N) {
        return 0;
    }
    
    if(dp[i][r][c] != -1) {
        return dp[i][r][c];
    }

    int v = A[i];
    int res = 0;
    for(auto [nr, nc] : pos[v]) {
        if(nr >= r && nc >= c) {
            int ret = dfs(N, H, W, A, G, pos, i + 1, nr + 1, nc + 1, dp);     
            if(ret == 0) {
                res = 1;
            }
        }
    } 

    return dp[i][r][c] = res;
}

void run_case() {
    int N, H, W;
    std::cin >> N >> H >> W;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    std::vector<std::vector<int>> max_c(MAX + 1, std::vector<int>(H, -1));
    std::vector<std::vector<std::pair<int, int>>> pos(MAX + 1);
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> G[i][j];
            int v = G[i][j];
            max_c[v][i] = std::max(max_c[v][i], j);
        }
    }

    for(int v = 1; v <= MAX; v++) {
        for(int r = 0; r < H; r++) {
            if(max_c[v][r] != -1) {
                pos[v].emplace_back(r, max_c[v][r]);
            }
        }
    }

    std::vector<std::vector<std::vector<int>>> dp(N, std::vector<std::vector<int>>(H, std::vector<int>(W, -1)));
    int ans = dfs(N, H, W, A, G, pos, 0, 0, 0, dp);

    std::cout << (ans ? "T" : "N") << '\n';
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
