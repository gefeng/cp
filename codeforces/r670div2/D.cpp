#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t d = 0;
    std::vector<int64_t> diff(N, 0);
    for(int i = 1; i < N; i++) {
        diff[i] = A[i] - A[i - 1];
        d += std::max(0LL, diff[i]);
    }

    std::cout << std::max((A[0] + d) / 2, A[0] + d - (A[0] + d) / 2) << '\n';

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;
        L -= 1;
        R -= 1;

        if(L) {
            d -= std::max(0LL, diff[L]);
            diff[L] += X;
            d += std::max(0LL, diff[L]);
        } else {
            A[0] += X;
        }

        if(R + 1 < N) {
            d -= std::max(0LL, diff[R + 1]);
            diff[R + 1] -= X;
            d += std::max(0LL, diff[R + 1]);
        }

        std::cout << std::max((A[0] + d) / 2, A[0] + d - (A[0] + d) / 2) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
