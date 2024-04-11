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
    int64_t C;
    std::cin >> A >> B >> C;

    int64_t x = 0;
    int64_t y = 0;
    for(int i = 0; i < 60; i++) {
        if(C & (1LL << i)) {
            if(A >= B) {
                x |= 1LL << i;
                A -= 1;
            } else {
                y |= 1LL << i;
                B -= 1;
            }
        }
    }

    if(A != B || A < 0 || B < 0) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < 60; i++) {
        if(C & (1LL << i)) {
            continue;
        }

        if(A) {
            x |= 1LL << i;
            y |= 1LL << i;
            A -= 1;
            B -= 1;
        }
    }

    if(A) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
