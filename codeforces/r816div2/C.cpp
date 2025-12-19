#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(N, 0);
    dp[N - 1] = 1;
    
    int64_t ans = 1;
    for(int i = N - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + (A[i] == A[i + 1] ? 0 : N - 1 - i) + 1;
        ans += dp[i];
    }

    for(int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        if(P + 1 < N && A[P + 1] == A[P]) {
            ans += N - P - 1;
        }

        if(P - 1 >= 0 && A[P - 1] == A[P]) {
            ans += static_cast<int64_t>(N - P) * P;
        } 
        if(P + 1 < N && A[P + 1] == A[P]) {
            ans += static_cast<int64_t>(N - P - 1) * P;
        }
        
        A[P] = X;

        if(P + 1 < N && A[P + 1] == A[P]) {
            ans -= N - P - 1;
        }

        if(P - 1 >= 0 && A[P - 1] == A[P]) {
            ans -= static_cast<int64_t>(N - P) * P;
        } 
        if(P + 1 < N && A[P + 1] == A[P]) {
            ans -= static_cast<int64_t>(N - P - 1) * P;
        }

        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
