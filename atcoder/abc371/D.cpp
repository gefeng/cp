#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + B[i - 1];
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        
        auto it = std::lower_bound(A.begin(), A.end(), L);
        if(it == A.end()) {
            std::cout << 0 << '\n';
            continue;
        }

        int l = it - A.begin();
        int r = std::upper_bound(A.begin(), A.end(), R) - A.begin();
   
        std::cout << psum[r] - psum[l] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
