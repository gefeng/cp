#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;
    
    int64_t X, Y;
    std::cin >> X >> Y;
    
    int n = S.size();
    int64_t ans = 0;
    int64_t sum = 0;
    int64_t cnt_0 = 0;
    int64_t cnt_1 = 0;
    std::vector<int64_t> dp(n, 0);
    if(X <= Y) {
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] + (S[i + 1] == '0' ? 0 : 1);
        } 

        for(int i = 0; i < n; i++) {
            if(S[i] == '0') {
                sum += (i - cnt_0) * Y;
                cnt_0 += 1;
            } else {
                sum += cnt_0 * X;
            }
        }

        ans = sum;
        
        cnt_0 = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] == '?') {
                sum -= cnt_0 * X + (n - i - 1 - dp[i]) * Y; 
                sum += (i - cnt_0) * Y + dp[i] * X;
                cnt_0 += 1;
            } else if(S[i] == '0') {
                cnt_0 += 1;
            }
            ans = std::min(ans, sum);
        }
    } else {
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] + (S[i + 1] == '1' ? 0 : 1);
        }

        for(int i = 0; i < n; i++) {
            if(S[i] == '1') {
                sum += (i - cnt_1) * X;
                cnt_1 += 1;
            } else {
                sum += cnt_1 * Y;
            }
        }

        ans = sum;
        
        cnt_1 = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] == '?') {
                sum -= cnt_1 * Y + (n - i - 1 - dp[i]) * X;
                sum += (i - cnt_1) * X + dp[i] * Y;
                cnt_1 += 1;
            } else if(S[i] == '1') {
                cnt_1 += 1;
            }
            ans = std::min(ans, sum);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
