#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        int P;
        std::cin >> P;
        A[i] = int(std::pow(10, P));
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(i == N - 1) {
            ans += int64_t(K + 1) * A[i]; 
        } else {
            int64_t d = A[i + 1] - A[i];
            int64_t use = std::min(int64_t(K), d / A[i]);
            if(use == K && (use + 1) * A[i] != A[i + 1]) {
                ans += (use + 1) * A[i];
                break;
            }
            K -= use;
            ans += use * A[i];
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
