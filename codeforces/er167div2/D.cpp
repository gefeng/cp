#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = (int)2e9;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(M);
    std::vector<int> best;
    std::vector<int> dp;
    int max_v = 0;
    int min_v = INF;
    int64_t ans = 0;

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        min_v = std::min(min_v, A[i]);
        max_v = std::max(max_v, A[i]);
    }

    best.resize(max_v + 1, INF);
    dp.resize(max_v + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        best[A[i]] = std::min(best[A[i]], A[i] - B[i]);
    }

    for(int i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    for(int i = 1; i <= max_v; i++) {
        best[i] = std::min(best[i], best[i - 1]);
        if(best[i] <= i) {
            dp[i] = dp[i - best[i]] + 1;
        }
    }

    for(int i = 0; i < M; i++) {
        if(C[i] > max_v) {
            int cnt = (C[i] - max_v) / best[max_v] + 1;
            C[i] -= cnt * best[max_v];
            ans += cnt;
        }   

        ans += dp[C[i]];
    }
    
    std::cout << ans * 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
