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
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int64_t cnt = 0;
    int64_t min_s = INF;
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        min_s = std::min(min_s, int64_t(A[i]));
        cnt += 1;
        if(min_s * cnt >= X) {
            ans += 1;
            cnt = 0;
            min_s = INF;
        }
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
