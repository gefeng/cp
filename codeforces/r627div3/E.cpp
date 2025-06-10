#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, H, L, R;
    std::cin >> N >> H >> L >> R;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(H, -1);
    dp[0] = 0;
    
    for(int i = 0; i < N; i++) {
        std::vector<int> n_dp(H, -1);
        
        for(int j = 0; j < H; j++) {
            if(dp[j] == -1) {
                continue;
            }
            
            for(int k = -1; k <= 0; k++) {
                int t = (j + A[i] + k) % H;
                n_dp[t] = std::max(n_dp[t], dp[j] + (t >= L && t <= R ? 1 : 0));
            }
        } 

        dp = std::move(n_dp);
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        ans = std::max(ans, dp[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
