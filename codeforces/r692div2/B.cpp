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
    std::cin >> N;

    auto check = [](int64_t x) {
        int64_t y = x;
        while(y) {
            int d = y % 10;
            if(d && x % d != 0) {
                return false;
            }
            y /= 10;
        }
        return true;
    };

    while(!check(N)) {
        N += 1;
    }

    std::cout << N << '\n';
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
