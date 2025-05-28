#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(4e18);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int64_t sum = 0;
    int64_t ans = INF;
    std::vector<int> st;
    for(int i = 0; i < N; i++) {
        if(A[i].first > A[(i - 1 + N) % N].second) {
            sum += A[i].first - A[(i - 1 + N) % N].second;
        }
    }

    for(int i = 0; i < N; i++) {
        int64_t cost = A[i].first + sum - (std::max(int64_t(0), A[i].first - A[(i - 1 + N) % N].second));
        ans = std::min(ans, cost);
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
