#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e8;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    int64_t sum = 0;
    // A[j] + A[i] >= 1e8
    // f(j, i) = A[j] + A[i] - 1e8
    // else A[j] + A[i]

    for(int i = 0; i < N; i++) {
        ans += sum + (int64_t)A[i] * i;
        sum += A[i];
    }

    std::sort(A.begin(), A.end());
    
    for(int i = 0; i < N; i++) {
        auto it = std::lower_bound(A.begin(), A.begin() + i, MOD - A[i]); 
        int64_t cnt = A.begin() + i - it;
        ans -= MOD * cnt;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
