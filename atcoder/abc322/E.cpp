#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, K, P;
    std::cin >> N >> K >> P;

    std::vector<std::vector<int>> A(N, std::vector<int>(K, 0));
    std::vector<int> C(N);

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }
    
    int n = 1 << (3 * K);
    std::vector<int64_t> dp(n, INF);
    dp[0] = 0; 

    std::vector<int> a(K, n - 1);
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < 3; j++) {
            a[i] ^= 1 << (i * 3 + j);
        } 
    }

    for(int i = 0; i < N; i++) {
        std::vector<int64_t> ndp(n, INF);
        
        for(int j = 0; j < n; j++) {
            ndp[j] = dp[j];
        }

        for(int j = 0; j < n; j++) {
            if(dp[j] == INF) {
                continue;
            }

            int nj = j;
            for(int k = 0; k < K; k++) {
                int np = (j >> (k * 3)) & 7;
                np = std::min(P, np + A[i][k]);
                nj = (nj & a[k]) | (np << (k * 3));
            }
            ndp[nj] = std::min(ndp[nj], dp[j] + C[i]);
        }
        
        std::swap(dp, ndp);
    }

    int s = 0;
    for(int i = 0; i < K; i++) {
        s |= P << (i * 3);
    }

    std::cout << (dp[s] == INF ? -1 : dp[s]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
