#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, K;
    std::cin >> X >> K;

    auto get_digits = [](int64_t x) {
        int64_t min_d = 10;
        int64_t max_d = 0;
        while(x) {
            min_d = std::min(min_d, x % 10);            
            max_d = std::max(max_d, x % 10);
            x /= 10;
        } 
        return std::pair<int, int>(min_d, max_d);
    };

    while(K > 1) {
        auto [a, b] = get_digits(X);
        if(a == 0) {
            break;
        }

        X += a * b;
        K -= 1;
    }

    std::cout << X << '\n';
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
