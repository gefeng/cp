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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int max_v = std::max(A[i], A[j]);
            int min_v = std::min(A[i], A[j]);
            
            if(max_v < 200) {
                if(max_v <= (K - min_v) * 2) {
                    ans = std::max(ans, B[i] + B[j]);
                }
            } else {
                if(max_v - 100 + min_v <= K) {
                    ans = std::max(ans, B[i] + B[j]);
                }
            }
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
