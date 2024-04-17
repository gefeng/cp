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
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if(N == 1) {
        std::cout << sum << '\n';
        return;
    }

    int64_t ans = std::abs(sum);
    std::vector<int64_t> max_s(N + 1, 0);
    sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        max_s[i + 1] = std::max(max_s[i], sum);
    }
    
    int64_t min_s = INF;
    sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(i) {
            int64_t t = sum - max_s[i - 1];
            min_s = std::min(min_s, t);
        }
    }
    
    if(min_s < 0) {
        ans = sum - min_s * 2;
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
