#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    int S;
    std::cin >> N >> S;

    auto digit_sum = [](int64_t x) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };

    int64_t ans = 0;
    int64_t d = 1;
    while(digit_sum(N) > S) {
        int64_t x = N / d; 
        int digit = x % 10;
        int need = (10 - digit) % 10;
        
        ans += need * d;
        N += need * d;
        d *= 10;
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
