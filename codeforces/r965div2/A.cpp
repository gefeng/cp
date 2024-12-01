#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e9);

void run_case() {
    int X, Y, K;
    std::cin >> X >> Y >> K;

    if(K % 2 == 1) {
        for(int l = 0, r = K - 1; l < r; l++, r--) {
            std::cout << MAX - l << ' ' << MAX - l << '\n';
            std::cout << -(MAX - l) << ' ' << -(MAX - l) << '\n';
        }
        std::cout << X * K << ' ' << Y * K << '\n';
    } else {
        for(int l = 0, r = K - 1; r - l > 1; l++, r--) {
            std::cout << MAX - l << ' ' << MAX - l << '\n';
            std::cout << -(MAX - l) << ' ' << -(MAX - l) << '\n';
        }

        std::cout << X * K / 2 - 1 << ' ' << Y * K / 2 - 1 << '\n';
        std::cout << X * K / 2 + 1 << ' ' << Y * K / 2 + 1 << '\n';
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
