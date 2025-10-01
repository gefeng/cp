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

    std::vector<int> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t ans = 0;
    if(K >= N) {
        int64_t d = K - N;
        ans = psum[N] + (d + N + d - 1) * N / 2;
    } else {
        for(int i = 0; i <= N - K; i++) {
            int64_t sum = psum[i + K] - psum[i] + static_cast<int64_t>(K - 1) * K / 2;
            ans = std::max(ans, sum);
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
