#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e6;

void run_case() {
    int64_t N;
    std::cin >> N;

    auto is_pal = [](int64_t x) {
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

    for(int64_t i = MAX; i >= 1; i--) {
        if(i * i * i <= N && is_pal(i * i * i)) {
            std::cout << i * i * i << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
