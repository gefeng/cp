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

    if(N == 1) {
        std::cout << A[0] << '\n';
        return;
    }

    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, (int64_t)A[i]);
    }

    if(ans < 0) {
        std::cout << ans << '\n';
        return;
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i += 2) {
        if(A[i] >= 0) {
            sum += A[i];
        }
    }

    ans = std::max(ans, sum);
    
    sum = 0;
    for(int i = 1; i < N; i += 2) {
        if(A[i] >= 0) {
            sum += A[i];
        }
    }

    ans = std::max(ans, sum);

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
