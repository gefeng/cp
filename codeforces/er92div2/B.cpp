#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K, Z;
    std::cin >> N >> K >> Z;

    std::vector<int> A(N);
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    int ans = psum[K + 1];
    int prefix = A[0];
    for(int i = 1; i < N; i++) {
        prefix += A[i];
        for(int j = 1; j <= Z; j++) {
            int score = j * A[i - 1] + (j - 1) * A[i] + prefix;
            if(j + j - 1 + i <= K) {
                score += psum[K - j * 2 + 1] - psum[i];
                ans = std::max(ans, score);
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
