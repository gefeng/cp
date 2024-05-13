#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;
    
    std::vector<int> A(K);
    std::vector<int> B(K);
    
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < Q; i++) {
        int D;
        std::cin >> D;

        int t = 0;
        if(D == N) {
            t = B.back();
        } else {
            auto it = std::upper_bound(A.begin(), A.end(), D);
            if(it == A.begin()) {
                t = (int64_t)D * B[0] / A[0];
            } else {
                int j = it - A.begin() - 1;
                t = B[j] + (int64_t)(D - A[j]) * (B[j + 1] - B[j]) / (A[j + 1] - A[j]);
            }
        }

        std::cout << t << " \n"[i == Q - 1];
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
