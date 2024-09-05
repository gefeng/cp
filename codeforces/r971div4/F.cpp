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
    std::vector<int64_t> psum(N * 2 + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        A.push_back(A[i]);
    }

    for(int i = 0; i < N * 2; i++) {
        psum[i + 1] = psum[i] + A[i];
    }
    
    auto query = [&](int64_t i) {
        if(i < 0) {
            return int64_t(0);
        }
        int64_t res = psum[N] * (i / N); 
        res += psum[i / N + (i % N) + 1] - psum[i / N]; 
        return res;
    };

    for(int i = 0; i < Q; i++) {
        int64_t L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        std::cout << query(R) - query(L - 1) << '\n';
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
