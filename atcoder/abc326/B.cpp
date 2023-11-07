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

    int cur = N;
    while(true) {
        std::vector<int> digits;
        int x = cur;
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        if(digits.size() == 3 && digits[1] * digits[2] == digits[0]) {
            std::cout << cur << '\n';
            return;
        }

        cur += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
