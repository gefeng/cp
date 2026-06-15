#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, X, Y;
    std::cin >> A >> B >> X >> Y;
    
    X = std::abs(X);
    Y = std::abs(Y);
    
    if(A > B) {
        std::swap(X, Y);
        std::swap(A, B);
    }

    int64_t ans = 0;
    int64_t d = std::min(X, Y);
    
    ans = d * 2 * A;
    
    int64_t left = std::max(X, Y) - d;

    if(d == Y) {
        if(left % 2 == 0) {
            ans += std::min(A * 2 * left, left / 2 * (A + B));
        } else {
            ans += std::min(left * A * 2 - A, (left + 1) / 2 * A + left / 2 * B);
        }
    } else {
        if(left % 2 == 0) {
            ans += std::min(A * 2 * left, left / 2 * (A + B));
        } else {
            ans += std::min(A * 2 * left + A, (left + 1) / 2 * B + left / 2 * A);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
