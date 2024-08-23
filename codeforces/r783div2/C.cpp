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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = INF;
    for(int prefix = 0; prefix <= N; prefix++) {
        int64_t cnt = 0;
        int64_t pre = 0;
        for(int i = prefix - 1; i >= 0; i--) {
            int64_t x = pre % A[i] == 0 ? pre / A[i] + 1 : (pre + A[i] - 1) / A[i];
            cnt += x;
            pre = x * A[i]; 
        }

        pre = 0;
        for(int i = prefix + 1; i < N; i++) {
            int64_t x = pre % A[i] == 0 ? pre / A[i] + 1 : (pre + A[i] - 1) / A[i];
            cnt += x;
            pre = x * A[i]; 
        }

        ans = std::min(ans, cnt);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
