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
        std::cout << (N == 1 ? "FastestFinger" : "Ashishgup") << '\n';
        return;
    }

    if(N == 2) {
        std::cout << "Ashishgup" << '\n';
        return;
    }

    int x = N;
    while(x % 2 == 0) {
        x /= 2;
    }
    if(x == 1) {
        std::cout << "FastestFinger" << '\n';
        return;
    }

    auto is_prime = [](int x) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    x = N / 2;
    std::cout << (is_prime(x) ? "FastestFinger" : "Ashishgup") << '\n';
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
