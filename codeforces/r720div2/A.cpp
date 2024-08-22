#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    if(B == 1) {
        std::cout << "NO" << '\n';
        return;
    }


    int64_t x = A;
    int64_t y = int64_t(A) * (B - 1);
    int64_t z = x + y;

    if(x == y) {
        y = A * 3;
        z = x + y;
    }

    std::cout << "YES" << '\n' << x << ' ' << y << ' ' << z << '\n';
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
