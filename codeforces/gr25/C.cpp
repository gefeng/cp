#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());    

    int64_t ans = 0;
    int need = (K + M - 1) / M;
    if(K % M != 0) {
        for(int i = 0; i < need; i++) {
            ans += (A[i] + ((int64_t)i * M)) * (i < need - 1 ? M : K % M);
        }
    } else {
        for(int i = 0; i < need; i++) {
            ans += (A[i] + ((int64_t)i * M)) * M;
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
