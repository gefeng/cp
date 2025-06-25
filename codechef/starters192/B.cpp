#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int X, Y, Z, C;
    std::cin >> X >> Y >> Z >> C;

    if(X == Y) {
        std::cout << 0 << '\n';
        return;
    }

    if(gcd(X, Z) == lcm(Y, Z) || gcd(Y, Z) == lcm(X, Z)) {
        std::cout << C << '\n';
        return;
    }
    
    int ans = C * 2;
    if(X > Y && X % Y == 0) {
        for(int f = 1; f * f <= X; f++) {
            if(X % f == 0) {
                if(f % Y == 0) {
                    ans = std::min(ans, std::abs(Z - f) + C);
                }
                if((X / f) % Y == 0) {
                    ans = std::min(ans, std::abs(Z - X / f) + C);
                }
            }
        }
    } else if(X < Y && Y % X == 0) {
        for(int f = 1; f * f <= Y; f++) {
            if(Y % f == 0) {
                if(f % X == 0) {
                    ans = std::min(ans, std::abs(Z - f) + C);
                }
                if((Y / f) % X == 0) {
                    ans = std::min(ans, std::abs(Z - Y / f) + C);
                }
            }
        }
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
