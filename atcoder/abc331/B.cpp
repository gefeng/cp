#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(3);
    std::vector<int> cnt = {6, 8, 12};
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> dp(N + 1, INF);
    dp[0] = 0;
    
    for(int i = 0; i < N; i++) {
        if(dp[i] == INF) {
            continue;
        }

        for(int j = 0; j < 3; j++) {
            int k = std::min(i + cnt[j], N);    
            dp[k] = std::min(dp[k], dp[i] + A[j]);
        }
    }

    std::cout << dp[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
