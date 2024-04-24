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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    for(int i = 0; i < N - 1; i++) {
        A[i] += (A.back() - A[i]) / K * K;
    }

    std::sort(A.begin(), A.end());

    int64_t ans = A.back() - A[0];

    int64_t max_v = 0;
    for(int i = 0; i < N - 1; i++) {
        A[i] += (A.back() - A[i] + K - 1) / K * K;
        
        max_v = std::max(max_v, A[i]);
    
        ans = std::min(ans, max_v - A[i + 1]);
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
