#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(std::vector<int>& digits, std::vector<int64_t>& p10, int sum_t, int cur, int bounded, int sum, int rem, 
        std::vector<std::vector<std::vector<std::vector<int64_t>>>>& dp) {
    if(cur == digits.size()) {
        return rem == 0 && sum == sum_t ? 1 : 0;
    } 

    if(dp[bounded][cur][sum][rem] != -1) {
        return dp[bounded][cur][sum][rem];
    }

    int64_t res = 0;
    if(bounded) {
        for(int d = 0; d <= digits[cur]; d++) {
            int nrem = (rem + (d * p10[digits.size() - cur - 1] % sum_t)) % sum_t;
            res += dfs(digits, p10, sum_t, cur + 1, d == digits[cur], sum + d, nrem, dp); 
        }    
    } else {
        for(int d = 0; d < 10; d++) {
            int nrem = (rem + (d * p10[digits.size() - cur - 1] % sum_t)) % sum_t;
            res += dfs(digits, p10, sum_t, cur + 1, bounded, sum + d, nrem, dp); 
        }
    }

    return dp[bounded][cur][sum][rem] = res;
}

void run_case() {
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> p10(16, 1); 
    for(int i = 1; i <= 15; i++) {
        p10[i] = p10[i - 1] * 10;
    }

    std::vector<int> digits;
    int64_t x = N;
    int max_sum = 0;
    while(x) {
        digits.push_back(x % 10);
        x /= 10;
        max_sum += 9;
    }
    std::reverse(digits.begin(), digits.end());


    int64_t ans = 0;
    for(int sum = 1; sum <= max_sum; sum++) {
        std::vector<std::vector<std::vector<std::vector<int64_t>>>> dp(2, 
                std::vector<std::vector<std::vector<int64_t>>>(digits.size(), 
                    std::vector<std::vector<int64_t>>(max_sum + 1, std::vector<int64_t>(max_sum, -1))));
        ans += dfs(digits, p10, sum, 0, 1, 0, 0, dp);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
