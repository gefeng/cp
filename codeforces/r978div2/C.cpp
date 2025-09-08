#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

int dfs(int N, std::vector<std::string>& A, int c, int s, std::vector<std::vector<int>>& dp) {
    if(c == N) {
        return 0;
    } 
    if(dp[c][s] != -1) {
        return dp[c][s];
    }

    int res = -INF;
    int score = 0;
    if(s == 0) {
        if(c + 2 < N) {
            score = 0;
            for(int i = 0; i < 2; i++) {
                int cnt = 0;
                for(int j = 0; j < 3; j++) {
                    cnt += A[i][c + j] == 'A' ? 1 : 0;
                }
                score += cnt / 2;
            }
            int ret = dfs(N, A, c + 3, 0, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
        if(c + 1 < N) {
            score = 0;
            int cnt = 0;
            for(int i = 0; i < 2; i++) {
                cnt += A[i][c] == 'A' ? 1 : 0;
            }
            cnt += A[0][c + 1] == 'A' ? 1 : 0;
            score = cnt / 2;
            int ret = dfs(N, A, c + 1, 1, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }

            score = 0;
            cnt = 0;
            for(int i = 0; i < 2; i++) {
                cnt += A[i][c] == 'A' ? 1 : 0;
            }
            cnt += A[1][c + 1] == 'A' ? 1 : 0;
            score = cnt / 2;
            ret = dfs(N, A, c + 1, 2, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
    } else if(s == 1) {
        if(c + 1 < N) {
            int cnt = A[1][c] == 'A' ? 1 : 0;
            for(int i = 0; i < 2; i++) {
                cnt += A[i][c + 1] == 'A' ? 1 : 0;
            }
            score = cnt / 2;
            int ret = dfs(N, A, c + 2, 0, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
        if(c + 3 < N) {
            int cnt = 0;
            for(int i = 0; i < 3; i++) {
                cnt += A[0][c + i + 1] == 'A' ? 1 : 0;
            }
            score = cnt / 2;
            cnt = 0;
            for(int i = 0; i < 3; i++) {
                cnt += A[1][c + i] == 'A' ? 1 : 0;
            }
            score += cnt / 2;
            int ret = dfs(N, A, c + 3, 1, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
    } else {
        if(c + 1 < N) {
            int cnt = A[0][c] == 'A' ? 1 : 0;
            for(int i = 0; i < 2; i++) {
                cnt += A[i][c + 1] == 'A' ? 1 : 0;
            }
            score = cnt / 2;
            int ret = dfs(N, A, c + 2, 0, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
        if(c + 3 < N) {
            int cnt = 0;
            for(int i = 0; i < 3; i++) {
                cnt += A[0][c + i] == 'A' ? 1 : 0;
            }
            score = cnt / 2;
            cnt = 0;
            for(int i = 0; i < 3; i++) {
                cnt += A[1][c + i + 1] == 'A' ? 1 : 0;
            }
            score += cnt / 2;
            int ret = dfs(N, A, c + 3, 2, dp);
            if(ret != -INF) {
                res = std::max(res, ret + score);
            }
        }
    }
    
    return dp[c][s] = res;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> A(2);
    for(int i = 0; i < 2; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(3, -1));

    std::cout << dfs(N, A, 0, 0, dp) << '\n';
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
