#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

int64_t dfs(std::vector<int64_t> a, int rev, int neg, std::vector<std::vector<std::vector<int64_t>>>& dp) {
    int n = a.size();
    if(n == 1) {
        return a[0];
    }

    if(dp[rev][neg][n] != -INF) {
        return dp[rev][neg][n];
    }

    int64_t sum = 0;
    if(rev) {
        std::reverse(a.begin(), a.end());
    }
    if(neg) {
        for(int i = 0; i < n; i++) {
            a[i] *= -1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    std::vector<int64_t> b(n - 1);
    for(int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            sum = std::max(sum, dfs(b, i, j, dp));
        }
    }

    return dp[rev][neg][n] = sum;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = -INF;
    for(int i = 0; i < 2; i++) {
        std::vector<std::vector<std::vector<int64_t>>> dp(2, std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(N + 1, -INF)));
        ans = std::max(ans, dfs(A, i, 0, dp));
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
