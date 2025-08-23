#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int64_t K;
    std::cin >> K;

    int64_t cnt_d = 1;
    int64_t cnt_n = 9;
    int64_t first = 1;
    int64_t ans = 0; 
    std::vector<int64_t> dp(20, 0);
    dp[1] = 45;
    for(int64_t i = 2, j = 10; i < 20; i++, j *= 10) {
        dp[i] = dp[i - 1] * 9 + 45 * j + dp[i - 1];;
    }

    while(K - cnt_n * cnt_d > 0) {
        K -= cnt_n * cnt_d; 
        cnt_d += 1;
        cnt_n *= 10;
        first *= 10;
    }

    ans += dp[cnt_d - 1];
    
    auto count = [&](int64_t x) {
        int64_t sum = 0;
        while(true) {
            if(x < 10) {
                sum += (1 + x) * x / 2;
                break;
            } 
            int64_t p10 = 1;
            int d = 1;
            while(p10 * 10 <= x) {
                p10 *= 10;
                d += 1;
            }
            
            int64_t c = x / p10 - 1;
            sum += ((1 + c) * c / 2) * p10 + c * dp[d - 1];
            sum += dp[d - 1];
            sum += (x % p10 + 1) * (x / p10);
            
            x %= p10;
        }

        return sum;
    };

    int64_t which = K / cnt_d;
    if(which) {
        int64_t x = first + which - 1;
        ans += count(x) - count(first - 1);
    }

    if(K % cnt_d != 0) {
        int64_t last = first + (K + cnt_d - 1) / cnt_d - 1;
        int64_t rem = K % cnt_d;
        std::vector<int> digits;
        while(last) {
            digits.push_back(last % 10);
            last /= 10;
        }
        std::ranges::reverse(digits);
        for(int i = 0; i < rem; i++) {
            ans += digits[i];
        }
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
