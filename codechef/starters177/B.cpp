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

    int64_t ans = 1;
    for(int i = 1; i <= N / 2; i++) {
        int64_t x = int64_t(i) * (N - i);
        ans += (x / 2 + 1) * 2 - (x % 2 == 0 ? 1 : 0);
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
