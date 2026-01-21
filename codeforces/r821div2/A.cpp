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
    int K, N;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> max_v(K, 0);
    for(int i = 0; i < N; i++) {
        max_v[i % K] = std::max(max_v[i % K], A[i]);
    }

    int64_t ans = std::accumulate(max_v.begin(), max_v.end(), static_cast<int64_t>(0));

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
