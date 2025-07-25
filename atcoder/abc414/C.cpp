#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MAX = int64_t(1e6);

void run_case() {
    int A;
    int64_t N;
    std::cin >> A >> N;

    std::vector<int> digits(15, 0);

    auto is_pal = [&](int64_t x) {
        int size = 0;
        while(x) {
            digits[size++] = x % A;
            x /= A;
        }

        int l = 0;
        int r = size - 1;
        while(l < r) {
            if(digits[l] != digits[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    };

    int64_t ans = 0;
    for(int64_t i = 1; i <= std::min(N, MAX); i++) {
        std::string l = std::to_string(i);
        std::string r = l;
        std::ranges::reverse(r);
        int64_t x = std::stol(l + r);
        
        if(x <= N && is_pal(x)) {
            ans += x; 
        }
        
        for(char d = '0'; d <= '9'; d++) {
            x = std::stol(l + std::string(1, d) + r);
            if(x <= N && is_pal(x)) {
                ans += x;
            }
        }

        if(i < 10 && is_pal(i)) {
            ans += i; 
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
