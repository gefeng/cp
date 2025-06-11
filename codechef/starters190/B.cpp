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

    int64_t score = 0;
    for(int i = 1; i < N; i++) {
        score += std::min(A[i - 1], A[i]);
    }

    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;
        
        if(P) {
            score -= std::min(A[P - 1], A[P]);
        }
        if(P + 1 < N) {
            score -= std::min(A[P], A[P + 1]);
        }

        A[P] = X;
        
        if(P) {
            score += std::min(A[P - 1], A[P]);
        }
        if(P + 1 < N) {
            score += std::min(A[P], A[P + 1]);
        }

        std::cout << score << '\n';
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
