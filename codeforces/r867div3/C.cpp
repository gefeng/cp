#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    if(N == 4) {
        std::cout << 26 << '\n';
        return;
    }

    LL ans = 26LL + (5LL + 1LL * N) * (1LL * N - 4LL) + (1LL * N - 4LL);
    
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
