#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL K;
    std::cin >> K;

    std::vector<int> digits;
    while(K) {
        digits.push_back(K % 9LL);
        K /= 9LL;
    }

    std::reverse(digits.begin(), digits.end());

    for(int i = 0; i < digits.size(); i++) {
        std::cout << (digits[i] >= 4 ? digits[i] + 1 : digits[i]);
    }

    std::cout << '\n';
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
