#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 60;

void run_case() {
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> p_2(MAX + 1, 1);
    for(int i = 1; i <= MAX; i += 1) {
        p_2[i] = p_2[i - 1] * 2;
    }

    int64_t ans = 0;
    for(int i = 1; i <= MAX; i++) {
        int64_t x = N / p_2[i];
        if(x == 0) {
            break;
        }
        int64_t sqr = int64_t(sqrtl(x));
        ans += (sqr + 1) / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
