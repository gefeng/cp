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

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
    
        if(T == 1) {
            int P;
            std::cin >> P;
            P -= 1;
        
            psum[P + 1] = psum[P] + A[P + 1];
            std::swap(A[P], A[P + 1]);
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;
            std::cout << psum[R + 1] - psum[L] << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
