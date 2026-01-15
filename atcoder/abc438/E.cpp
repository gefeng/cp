#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<std::vector<int>> dp(30, std::vector<int>(N, 0));    
    std::vector<std::vector<int64_t>> ds(30, std::vector<int64_t>(N, 0));    
    
    for(int i = 0; i < N; i++) {
        dp[0][i] = A[i];
        ds[0][i] = i + 1;
    }

    for(int i = 1; i < 30; i++) {
        for(int v = 0; v < N; v++) {
            int u = dp[i - 1][v];
            dp[i][v] = dp[i - 1][u];
            ds[i][v] = ds[i - 1][v] + ds[i - 1][u];
        }
    }

    for(int _ = 0; _ < Q; _++) {
        int T, B;
        std::cin >> T >> B;

        int64_t sum = 0;
        int v = B - 1;
        for(int i = 29; i >= 0; i--) {
            if(T & (1 << i)) {
                sum += ds[i][v];
                v = dp[i][v];
            } 
        }

        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
