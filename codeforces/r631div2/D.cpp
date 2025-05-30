#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int D, M;
    std::cin >> D >> M;

    int hb = 0;
    for(int i = 29; i >= 0; i--) {
        if(D & (1 << i)) {
            hb = i;
            break;
        }
    }
    
    int64_t ans = 0;
    for(int len = 1; len <= hb + 1; len++) {
        std::vector<int64_t> dp(hb + 1, 0);
        
        for(int i = 0; i <= hb; i++) {
            dp[i] = i == hb ? D - (1 << i) + 1 : (1 << i);
            dp[i] %= M;
        }
        
        for(int i = 2; i <= len; i++) {
            std::vector<int64_t> n_dp(hb + 1, 0);
            
            for(int j = i - 2; j <= hb; j++) {
                for(int k = j + 1; k <= hb; k++) {
                    n_dp[k] += dp[j] * (k == hb ? D - (1 << k) + 1 : (1 << k)) % M;
                    n_dp[k] %= M;
                }
            }
            
            dp = std::move(n_dp);
        }

        int64_t cnt = 0;
        for(int i = 0; i <= hb; i++) {
            cnt += dp[i]; 
            cnt %= M;
        }
        ans += cnt;
        ans %= M;
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
