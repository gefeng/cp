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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int P, X;
            std::cin >> P >> X;
            P--;
            A[P] = X;
        } else {
            int L, R;
            std::cin >> L >> R;
            L--;
            R--;

            int res = 0;
            int len = R - L + 1;
            if(len % 2 == 0) {
                res = std::max(A[L + len / 2 - 1], A[L + len / 2]);
            } else {
                if(len == 1) {
                    res = A[L];
                } else {
                    res = std::max(std::min(A[L + len / 2], A[L + len / 2 + 1]), std::min(A[L + len / 2], A[L + len / 2 - 1]));
                }
            }
            std::cout << res << '\n';
        }
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
