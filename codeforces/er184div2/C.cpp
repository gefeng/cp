#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t ans = accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    int64_t sum = 0;
    int64_t min_v = 0; 
    for(int i = 0; i < N; i++) {
        sum += i + 1 + i + 1 - A[i];
        ans = std::max(ans, sum - min_v + psum[N]);
        min_v = std::min(min_v, sum);
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
