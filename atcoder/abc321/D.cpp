#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, P;
    std::cin >> N >> M >> P;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int64_t> psum(M + 1, 0);
    for(int i = 0; i < M; i++) {
        psum[i + 1] = psum[i] + B[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        auto it = std::upper_bound(B.begin(), B.end(), P - A[i]);
        
        int l = it - B.begin();
        int r = B.end() - it;
        
        ans += (int64_t)l * A[i] + psum[l] + (int64_t)r * P; 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
