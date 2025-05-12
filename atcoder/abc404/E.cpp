#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N - 1);
    std::vector<int> B(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    std::vector<int> dp(N - 1, INF); 

    dp[0] = 1;
    ans = B[0];
    for(int i = 1; i < N - 1; i++) {
        if(i - A[i] < 0) {
            dp[i] = 1;
        } else {
            for(int j = 1; j <= A[i]; j++) {
                if(i - j >= 0) {
                    if(B[i - j]) {
                        dp[i] = 1;
                    } else {
                        dp[i] = std::min(dp[i], dp[i - j] + 1);
                    }
                }
            }
        }
        if(B[i]) {
            ans += dp[i];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
