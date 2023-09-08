#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    if(L != R) {
        int sum = -1;
        for(int i = L; i <= R; i++) {
            if(i % 2 == 0 && i != 2) {
                sum = i;
                break;
            }
        }

        if(sum == -1) {
            std::cout << -1 << '\n';
        } else {
            std::cout << sum / 2 << ' ' << sum / 2 << '\n';
        }
    } else {
        bool is_prime = true;
        int factor = -1; 
        for(int f = 2; f * f <= L; f++) {
            if(L % f == 0) {
                is_prime = false;
                factor = f;
                break;
            }
        }

        if(is_prime) {
            std::cout << -1 << '\n';
        } else {
            std::cout << factor << ' ' << (L / factor - 1) * factor << '\n';
        }
    }
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
