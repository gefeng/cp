#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    auto is_prime = [](int x) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        } 

        return true;
    };

    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            int x = (S[i] - '0') * 10 + S[j] - '0';
            if(is_prime(x)) {
                std::cout << x << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
