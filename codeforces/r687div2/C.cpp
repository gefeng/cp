#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, P, K;
    std::cin >> N >> P >> K;
    P -= 1;

    std::string S;
    std::cin >> S;

    int64_t X, Y;
    std::cin >> X >> Y;

    std::vector<int64_t> dp(N, INF);
    for(int i = P; i < N; i++) {
        if(N - (i - P) < P) {
            continue;
        }
        if(S[i] == '0') {
            dp[i] = (i - P) * Y + X;
        } else {
            dp[i] = (i - P) * Y;
        }
    }

    for(int i = 0; i < N; i++) {
        if(i - K >= 0 && dp[i - K] != INF) {
            if(S[i] == '0') {
                dp[i] = std::min(dp[i], dp[i - K] + X);
            } else {
                dp[i] = std::min(dp[i], dp[i - K]);
            }
        }
    }

    int64_t ans = INF;
    for(int i = N - K; i < N; i++) {
        ans = std::min(ans, dp[i]); 
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
