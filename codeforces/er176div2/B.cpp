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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;

    if(K == 1) {
        ans = A[0] + A.back();
        for(int i = 1; i < N - 1; i++) {
            ans = std::max(ans, int64_t(A[i]) + std::max(A[0], A.back()));
        }
    } else {
        std::sort(A.begin(), A.end(), std::greater<int>());
        for(int i = 0; i < K + 1; i++) {
            ans += A[i];
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
