#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + std::max((int64_t)0, (int64_t)(N - i) * (N - i - 1) / 2);
    }

    for(int i = 0; i < Q; i++) {
        int64_t K;
        std::cin >> K;
        
        int j = std::lower_bound(psum.begin(), psum.end(), K) - psum.begin() - 1;
        
        std::cout << A[j] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
