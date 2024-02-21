#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> dp(N + 1, 0);
    
    dp[1] = S[0] == '1' ? 1 : 0;

    if(N > 1) {
        dp[2] = S[1] == '1' ? 2 : dp[1];
    }
    
    for(int i = 3; i <= N; i++) {
        if(S[i - 1] == '0') {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 3] + i - 3 + 3;
        }
    }

    int64_t ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += dp[i];
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
