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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N + 1, INF);
    dp[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
        
        int v = A[i - 1];
        if(i + v <= N) {
            dp[i + v] = std::min(dp[i + v], dp[i - 1]);
        }
    }

    std::cout << dp[N] << '\n';
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
