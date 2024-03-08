#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 18;

void run_case() {
    int64_t N;
    std::cin >> N;

    std::array<int, 5> a = {0, 2, 4, 6, 8};
    int64_t ans = 0;
    int64_t p = 1;
    N -= 1;
    while(N) {
        int d = a[N % 5];
        ans += d * p;
        p *= 10; 
        N /= 5;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
