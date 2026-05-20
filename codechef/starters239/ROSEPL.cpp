#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t t = A[i] / K;
        
        int64_t d = std::min(t * (K + 1), M);
        int64_t x = d / (K + 1) * K + (d % (K + 1));
        ans += x;
        A[i] -= x;
        M -= d;
    }

    if(M) {
        std::ranges::sort(A, std::greater<int>());
        for(int i = 0; i < N; i++) {
            if(A[i] && M) {
                int64_t d = std::min(static_cast<int64_t>(A[i]) + 1, M);
                int64_t x = d > A[i] ? d - 1 : d;
                M -= d;
                ans += x;
            }
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
