#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N, K, D;
    std::cin >> N >> K >> D;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    int64_t ans = 0;
    for(int s = 0, j = 0; s < std::min(N * 2 + 1, D); s++, j = (j + 1) % K) {
        int64_t score = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == i + 1) {
                score += 1;
            }
        }

        score += (D - (s + 1)) / 2;
        ans = std::max(ans, score);

        int prefix = B[j];
        for(int i = 0; i < prefix; i++) {
            A[i] += 1;
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
