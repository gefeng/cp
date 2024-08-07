#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(4e4);
constexpr int64_t MOD = int64_t(1e9) + 7;

std::vector<int> all;
std::vector<int64_t> dp;

void run_case() {
    int N;
    std::cin >> N;

    std::cout << dp[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    auto is_pal = [](int x) {
        std::vector<int> digits;
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        for(int l = 0, r = digits.size() - 1; l < r; l++, r--) {
            if(digits[l] != digits[r]) {
                return false;
            }
        }
        return true;
    };

    for(int i = 1; i <= MAX; i++) {
        if(is_pal(i)) {
            all.push_back(i);
        }
    }

    int size = all.size();
    dp.resize(MAX + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < size; i++) {
        for(int j = 1; j <= MAX; j++) {
            if(j >= all[i]) {
                dp[j] += dp[j - all[i]];
                dp[j] %= MOD;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
