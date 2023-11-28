#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;

    auto solve = [](int a, int b, int c) {
        if(a > b) {
            std::swap(a, b);
        }
        b -= a;
        a = 0;
        return b % 2 == 0 ? 1 : 0;
    };

    std::array<int, 3> ans = {solve(B, C, A), solve(A, C, B), solve(A, B, C)};
    for(int i = 0; i < 3; i++) {
        std::cout << ans[i] << " \n"[i == 2];
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
