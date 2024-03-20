#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B, M;
    std::cin >> A >> B >> M;

    if(A > B) {
        std::swap(A, B);
    }

    int64_t x = (M + A) / A;
    int64_t y = (M + B) / B;
    std::cout << x + y << '\n';
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
