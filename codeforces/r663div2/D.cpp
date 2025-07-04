#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

int dfs_1(int M, std::vector<std::string>& A, int c, int pre, std::vector<std::vector<int>>& dp) {
    if(c == M) {
        return 0;
    }

    if(dp[pre][c] != -1) {
        return dp[pre][c];
    }
    
    int res = INF;
    for(int i = 0; i < (1 << 2); i++) {
        int x = 0;
        for(int j = 0; j < 2; j++) {
            if(A[j][c] == '1') {
                x |= 1 << j;
            } 
        }
        bool ok = true;
        int cnt = __builtin_popcount(i) + __builtin_popcount(pre);
        if(c && cnt % 2 == 0) {
            ok = false;
        }

        if(!ok) {
            continue;
        }

        int cost = __builtin_popcount(x ^ i);
        int min_v = dfs_1(M, A, c + 1, i, dp);
        if(min_v != INF) {
            res = std::min(res, min_v + cost);
        }
    }
    return dp[pre][c] = res;
}

int dfs_2(int M, std::vector<std::string>& A, int c, int pre, std::vector<std::vector<int>>& dp) {
    if(c == M) {
        return 0; 
    }

    if(dp[pre][c] != -1) {
        return dp[pre][c];
    }
    
    int res = INF;
    for(int i = 0; i < (1 << 3); i++) {
        int x = 0;
        for(int j = 0; j < 3; j++) {
            if(A[j][c] == '1') {
                x |= 1 << j;
            } 
        }
        bool ok = true;
        int cnt = __builtin_popcount(i >> 1) + __builtin_popcount(pre >> 1);
        if(c && cnt % 2 == 0) {
            ok = false;
        }

        cnt = __builtin_popcount(i & 3) + __builtin_popcount(pre & 3);
        ok = ok && (c == 0 || cnt % 2 == 1);

        if(!ok) {
            continue;
        }

        int cost = __builtin_popcount(x ^ i);
        int min_v = dfs_2(M, A, c + 1, i, dp);
        if(min_v != INF) {
            res = std::min(res, min_v + cost);
        }
    }
    return dp[pre][c] = res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N >= 4 && M >= 4) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = INF;

    if(N > M) {
        std::vector<std::string> a(M, std::string(N, '0'));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                a[j][N - 1 - i] = A[i][j];
            }
        }
        A = std::move(a);
        std::swap(N, M);
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    if(N == 2) {
        std::vector<std::vector<int>> dp(4, std::vector<int>(M, -1));
        ans = dfs_1(M, A, 0, 0, dp);
    } else {
        std::vector<std::vector<int>> dp(8, std::vector<int>(M, -1));
        ans = dfs_2(M, A, 0, 0, dp);
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
