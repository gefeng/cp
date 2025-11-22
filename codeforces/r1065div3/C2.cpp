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

    for(int b = 20; b >= 0; b--) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] & (1 << b)) {
                cnt += 1;
            }
            if(B[i] & (1 << b)) {
                cnt += 1;
            }
        }
        if(cnt % 2 == 1) {
            int last = -1;
            for(int i = N - 1; i >= 0; i--) {
                int b1 = A[i] & (1 << b) ? 1 : 0;
                int b2 = B[i] & (1 << b) ? 1 : 0;
                if(b1 != b2) {
                    last = i;
                    break;
                }
            }
            std::cout << (last % 2 == 0 ? "Ajisai" : "Mai") << '\n';
            return;
        }
    }

    std::cout << "Tie" << '\n';
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
