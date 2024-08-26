#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        A[i].resize(L, 0);
        for(int j = 0; j < L; j++) {
            std::cin >> A[i][j];
        }
    }

    int k = 0;
    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; i++) {
        std::sort(A[i].begin(), A[i].end());
        int mex1 = 0;
        int mex2 = 0;
        int size = A[i].size(); 
        
        for(int j = 0; j < size; ) {
            int k = j;
            while(j < size && A[i][j] == A[i][k]) {
                j += 1;
            }
            if(A[i][k] == mex1) {
                mex1 += 1;
            } else {
                break;
            }
        }

        for(int j = 0; j < size; ) {
            int k = j;
            while(j < size && A[i][j] == A[i][k]) {
                j += 1;
            }
            if(A[i][k] == mex2) {
                mex2 += 1; 
            } else {
                if(mex2 == mex1) {
                    mex2 += 1;
                }
                if(A[i][k] == mex2) {
                    mex2 += 1; 
                } else {
                    break;
                }
            }
        }

        if(mex1 == mex2) {
            mex2 += 1;
        }

        a.emplace_back(mex1, mex2);
        k = std::max(k, mex2);
    }

    std::vector<std::vector<int>> g(k + 1);
    std::vector<std::vector<int>> rg(k + 1);
    std::vector<int> dp(k + 1, 0); 
    int max_v = -1;
    for(auto [u, v] : a) {
        max_v = std::max(max_v, u);
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for(int i = 0; i <= k; i++) {
        dp[i] = std::max(i, max_v);
    }

    for(int i = k; i >= 0; i--) {
        for(int j : rg[i]) {
            dp[j] = std::max(dp[j], std::max(i, dp[i]));
        }
    }

    for(int i = 0; i <= k; i++) {
        if(g[i].size() > 1) {
            max_v = std::max(max_v, dp[i]);
        }
    }

    for(int i = 0; i <= k; i++) {
        dp[i] = std::max(dp[i], max_v);
    }

    int64_t ans = 0;
    for(int i = 0; i <= std::min(k, M); i++) {
        ans += dp[i];
    }

    if(M > k) {
        ans += int64_t(k + 1 + M) * (M - k) / 2;
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
