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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = INF;
    int64_t sum = A[0];
    int min_eve = A[0];
    int min_odd = int(2e9);
    for(int i = 1; i < N; i++) {
        int64_t cost = 0;
        if(i % 2 == 1) {
            cost = sum - min_eve + int64_t(min_eve) * (N - (i + 1) / 2 + 1);
        } else {
            cost = sum - min_odd + int64_t(min_odd) * (N - i / 2 + 1);
        }
        cost += int64_t(A[i]) * (N - i / 2);

        ans = std::min(ans, cost);

        if(i % 2 == 0) {
            min_eve = std::min(min_eve, A[i]);
        } else {
            min_odd = std::min(min_odd, A[i]);
        }

        sum += A[i];
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
