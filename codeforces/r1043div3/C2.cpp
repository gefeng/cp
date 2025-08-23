#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N <= K) {
        std::cout << 3LL * N << '\n';
        return;
    }

    std::vector<int64_t> p3(21, 1);
    for(int i = 1; i <= 20; i++) {
        p3[i] = p3[i - 1] * 3;
    }
    
    std::vector<int64_t> deal(20, 0);
    int64_t sum = 0;
    for(int i = 19; i >= 0; i--) {
        deal[i] += N / p3[i]; 
        N %= p3[i];
        sum += deal[i];
    }

    if(sum > K) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 19; i > 0; i--) {
        if(deal[i]) {
            int64_t x = std::min(deal[i], (K - sum) / 2);
            deal[i - 1] += x * 3;
            deal[i] -= x;
            sum = sum - x + x * 3;
        }
    }

    int64_t ans = deal[0] * 3;
    for(int i = 1; i < 20; i++) {
        ans += (p3[i + 1] + i * p3[i - 1]) * deal[i];
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
