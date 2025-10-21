#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

constexpr int INF = int(2e9);

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int> acc(1 << M, 0);
    for(int i = 1; i < (1 << M); i++) {
        int x = (1 << 30) - 1;
        for(int j = 0; j < M; j++) {
            if(i & (1 << j)) {
                x &= B[j];
            }
        }
        acc[i] = x;
    }

    std::vector<int> d(N * M);
    for(int i = 0; i < N; i++) {
        std::vector<int> dp(M + 1, INF);
        dp[0] = A[i];
        for(int j = 1; j < (1 << M); j++) {
            int k = __builtin_popcount(j);
            dp[k] = std::min(dp[k], A[i] & acc[j]);
        }
        
        for(int j = 1; j <= M; j++) {
            d.push_back(dp[j - 1] - dp[j]);
        }
    }

    std::sort(d.begin(), d.end(), std::greater<int>());

    int64_t ans = std::accumulate(A.begin(), A.end(), int64_t(0));
    
    for(int i = 0; i < K; i++) {
        ans -= d[i];
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
