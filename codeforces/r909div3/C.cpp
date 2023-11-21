#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = -INF;
    int64_t sum = 0;
    for(int l = 0, r = 0; r < N; r++) {
        sum += A[r]; 
        if(r > l && std::abs(A[r]) % 2 == std::abs(A[r - 1]) % 2) {
            sum = A[r];
        }

        ans = std::max(ans, sum);
        sum = std::max((int64_t)0, sum);
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
