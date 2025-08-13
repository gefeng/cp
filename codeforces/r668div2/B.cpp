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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t bal = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] >= 0) {
            if(i < N - 1) {
                bal += A[i];
            }
        } else {
            int64_t d = std::min(static_cast<int64_t>(std::abs(A[i])), bal);
            bal -= d;
            ans += std::abs(A[i]) - d;
        }
    }

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
