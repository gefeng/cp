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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int64_t, int64_t>> dp(N);
    int64_t l = 1;
    int64_t r = INF;
    for(int i = N; i > 0; i--) {
        int64_t a = 0;
        int64_t b = 0;
        for(int j = i + i; j <= N; j += i) {
            a += dp[j - 1].first;
            b += dp[j - 1].second;
        }
        a = 1 - a;
        b = -b - A[i - 1];
        dp[i - 1] = {a, b};
        if(a == 0) {
            if(b < 0) {
                std::cout << -1 << '\n';
                return;
            }
        } else {
            if(a < 0) {
                if(b <= 0) {
                    std::cout << -1 << '\n';
                    return;
                }
                r = std::min(r, b / (-a));
            } else {
                if(b < 0) {
                    l = std::max(l, (-b + a - 1) / a);
                }
            }
        }

        if(l > r) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << l - A[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
