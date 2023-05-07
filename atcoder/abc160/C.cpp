#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K, N;
    std::cin >> K >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = K;
    for(int i = 0; i < N; i++) {
        int l = A[(i - 1 + N) % N];
        int r = A[(i + 1) % N];
        
        ans = std::min(ans, K - ((A[i] - l + K) % K));
        ans = std::min(ans, K - (r - A[i]));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
