#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int cnt = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] < 0) {
            cnt += 1;
        }
        sum += std::abs(A[i]);
    }

    if(cnt % 2 == 0) {
        std::cout << sum << '\n';
        return;
    }

    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, sum - 2 * std::abs(A[i]));
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
