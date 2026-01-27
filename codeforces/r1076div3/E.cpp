#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        seen[A[i]] = 1;
    }

    std::vector<int> dp(N + 1, INF);
    for(int i = 1; i <= N; i++) {
        if(seen[i]) {
            dp[i] = 1;
        } else {
            for(int f = 1; f * f <= i; f++) {
                if(i % f == 0) {
                    if(seen[f] && dp[i / f] != INF) {
                        dp[i] = std::min(dp[i], dp[i / f] + 1); 
                    }
                    if(seen[i / f] && dp[f] != INF) {
                        dp[i] = std::min(dp[i], dp[f] + 1); 
                    }
                }
            }
        }

        std::cout << (dp[i] == INF ? -1 : dp[i]) << " \n"[i == N];
    }
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
