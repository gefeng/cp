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

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(B.begin(), B.end());
    
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            A[i] = std::min(B[0] - A[i], A[i]);
        } else {
            auto it = std::lower_bound(B.begin(), B.end(), A[i] + A[i - 1]);
            if(it == B.end()) {
                if(A[i] < A[i - 1]) {
                    std::cout << "No" << '\n';
                    return;
                }
            } else {
                if(A[i] >= A[i - 1]) {
                    A[i] = std::min(A[i], *it - A[i]);
                } else {
                    A[i] = *it - A[i];
                }
            }
        }
    }

    std::cout << "Yes" << '\n';
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
