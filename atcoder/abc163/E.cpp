#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());

    std::vector<std::vector<LL>> dp(N + 1, std::vector<LL>(N + 1, 0LL)); // prefix i and put L of them to the front
    for(int i = 1; i <= N; i++) {
        int v = A[i - 1].first;
        int p = A[i - 1].second;
        for(int l = 0; l <= i; l++) {
            if(l > 0) {
                dp[i][l] = std::max(dp[i][l], dp[i - 1][l - 1] + 1LL * v * std::abs(p - l + 1));
            }

            if(l < i) {
                dp[i][l] = std::max(dp[i][l], dp[i - 1][l] + 1LL * v * std::abs(N - i + l - p));
            }
        }
    }

    LL ans = 0LL;
    for(int i = 0; i <= N; i++) {
        ans = std::max(ans, dp[N][i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
