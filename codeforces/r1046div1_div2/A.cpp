#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    auto is_valid = [](int x, int y) {
        if(x > y) {
            std::swap(x, y);
        }
        return y <= x * 2 + 2;
    };

    if(!is_valid(A, B) || C < A || D < B || !is_valid(C - A, D - B)) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
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
