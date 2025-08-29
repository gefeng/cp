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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += std::min(A[i], B[i]);
    }

    for(int i = 0; i < Q; i++) {
        char C;
        int P, V;
        std::cin >> C >> P >> V;
        P -= 1;
        if(C == 'A') {
            sum -= std::min(A[P], B[P]);
            A[P] = V;
            sum += std::min(A[P], B[P]);
        } else {
            sum -= std::min(A[P], B[P]);
            B[P] = V;
            sum += std::min(A[P], B[P]);
        }

        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
