#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A;
    std::vector<int64_t> B;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        if(X < 0) {
            B.push_back(X);
        } else {
            A.push_back(X);
        }
    }

    std::ranges::sort(A);
    std::ranges::sort(B, std::greater<int64_t>());

    int n = A.size();
    int m = B.size();
    int64_t ans = -INF;
    int64_t now = 1;
    for(int i = 0; i < 5 && n - 1 - i >= 0; i++) {
        now *= A[n - 1 - i];
        int k = 4 - i;
        if(m - k >= 0) {
            int64_t p = now;
            if(k % 2 == 0) {
                for(int j = 0; j < k; j++) {
                    p *= B[m - 1 - j];
                }
            } else {
                for(int j = 0; j < k; j++) {
                    p *= B[j];
                }
            }
            ans = std::max(ans, p);
        }
    }
    
    if(m > 4) {
        now = 1;
        for(int i = 0; i < 5; i++) {
            now *= B[i];
        }
        ans = std::max(ans, now);
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
