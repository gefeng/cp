#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, Y;
    std::cin >> X >> Y;

    if(X > Y) {
        std::cout << -1 << '\n';
        return;
    }

    if(X == Y) {
        if(X == 0) {
            std::cout << 0 << '\n';
        } else {
            std::cout << 1 << '\n' << X << '\n';
        }
        return;
    }
    
    int64_t a = X;
    int64_t b = 0;
    int64_t c = 0; 

    int64_t rem = Y - X;
    for(int i = 60; i >= 0; i--) {
        if(X & (int64_t(1) << i)) {
            if((int64_t(1) << (i + 1)) <= rem) {
                b |= int64_t(1) << i;
                c |= int64_t(1) << i;
                rem -= int64_t(1) << (i + 1);
            }
        } else {
            if((int64_t(1) << (i + 1)) <= rem) {
                a |= int64_t(1) << i;
                b |= int64_t(1) << i;
                rem -= int64_t(1) << (i + 1);
            }
        }
    }

    if(rem) {
        std::cout << -1 << '\n';
        return;
    }

    if(c == 0) {
        std::cout << 2 << '\n';
        std::cout << a << ' ' << b << '\n';
        return;
    }

    std::cout << 3 << '\n';
    std::cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
