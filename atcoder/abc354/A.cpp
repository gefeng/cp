#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H;
    std::cin >> H;
    
    int64_t h = 0;
    int64_t d = 1;
    int ans = 0;
    while(h <= H) {
        h += d;
        d *= 2;
        ans += 1;
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
