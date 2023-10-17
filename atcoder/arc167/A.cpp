#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int64_t ans = 0;
    int i = 0;
    
    while(N - i != M) {
        i += 2;
        M -= 1;
    }

    for(int l = 0, r = i - 1; l < r; l += 1, r -= 1) {
        ans += (int64_t)(A[l] + A[r]) * (A[l] + A[r]);
    }

    for(int j = i; j < N; j++) {
        ans += (int64_t)A[j] * A[j];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
