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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = (A[0] + A.back()) / (N - 1);
    
    std::vector<int64_t> ans(N, 0);
    int64_t now = 0;
    for(int i = 0; i < N - 1; i++) {
        ans[i] = (sum - A[i] + A[i + 1]) / 2 - now;
        now += ans[i];
    }

    ans.back() = sum - now;

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
