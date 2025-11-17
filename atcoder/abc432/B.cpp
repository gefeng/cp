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
    int X;
    std::cin >> X;

    std::vector<int> digits;
    while(X) {
        digits.push_back(X % 10);
        X /= 10;
    }

    std::ranges::sort(digits);
    if(digits[0] == 0) {
        for(int i = 0; i < digits.size(); i++) {
            if(digits[i]) {
                std::swap(digits[i], digits[0]);
                break;
            }
        }
    }

    int ans = 0;
    for(int i = digits.size() - 1, j = 1; i >= 0; i--, j *= 10) {
        ans += j * digits[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
