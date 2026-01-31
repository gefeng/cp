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

    int c0 = 0;
    int c1 = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(A[i] == 0) {
                c0 += 1;
            } else {
                c1 += 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(B[i] == 0) {
                if(c0) {
                    c0 -= 1;
                    ans = 1;
                }
            } else {
                if(c1) {
                    c1 -= 1;
                    ans = 1;
                }
            }
        }
    }

    ans += std::max(c0, c1);

    std::cout << ans << '\n';
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
