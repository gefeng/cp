#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int64_t ans = 0;
    std::array<int, 2> cnt{};
    for(int i = 0; i < N; i++) {
        cnt[S[i] - '0']++;
    }

    for(int i = 0; i < 2; i++) {
        int64_t d = std::min(cnt[i ^ 1], K);
        int64_t x = d + cnt[i];
        int64_t y = cnt[i ^ 1] - d;
        ans = std::max(ans, (1 + x) * x / 2 + (1 + y) * y / 2);
    }

    std::cout << ans + 1 << '\n';
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
