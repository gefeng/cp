#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A;
    std::cin >> A;

    int64_t b = A * 2;    
    int64_t c = A;
    while(true) {
        c *= A;
        if(c > b) {
            break;
        }
    }

    std::cout << b << ' ' << c << '\n';
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
