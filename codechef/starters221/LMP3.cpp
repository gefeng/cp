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

    if(N % 2 == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int x = N;
    std::vector<int> digits;
    while(x) {
        if((x % 10) % 2 == 1) {
            std::cout << 1 << '\n';
            return;
        }
        digits.push_back(x % 10);
        x /= 10;
    }

    if(digits.size() == 1) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 1; i < digits.size(); i++) {
        if(digits[i] > digits[0]) {
            std::cout << 2 << '\n';
            return;
        }
    }

    std::cout << 3 << '\n';
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
