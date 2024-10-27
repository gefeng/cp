#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    int t = 1;
    int x = 0;
    int ans = 0;
    while(std::abs(x) <= N) {
        x = t % 2 == 1 ? x - (2 * t - 1) : x + 2 * t - 1;
        ans = t;
        t += 1;
    }

    std::cout << (ans % 2 == 1 ? "Sakurako" : "Kosuke") << '\n';
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
