#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs1(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int>& dp) {
    if(A[v]) {
        dp[v] += 1;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        dfs1(G, A, nei, v, dp);
        dp[v] += dp[nei];
    }
}

void dfs2(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, bool keep_p, std::vector<int>& dp, int& ans) {
    int cnt = 0;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
    
        if(dp[nei]) {
            cnt += 1;
        }
    }
    
    if(cnt > 1 || A[v] || (keep_p && cnt != 0)) {
        keep_p = true;
        ans += 1;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs2(G, A, nei, v, keep_p, dp, ans);
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> A(N, 0);
    for(int i = 0; i < K; i++) {
        int V;
        std::cin >> V;
        V -= 1;
        A[V] = 1;
    }

    int ans = 0;
    std::vector<int> dp(N, 0);
    dfs1(G, A, 0, -1, dp);
    dfs2(G, A, 0, -1, false, dp, ans);
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
