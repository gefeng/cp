#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(1e5);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> prefix_max(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        for(int l = 1; l <= std::min(K, x); ) {
            int r = x / (x / l);
            int q = x / l;
            int nl = r + 1;
            prefix_max[x / nl + 1] = std::max(prefix_max[x / nl + 1], q);
            l = nl;
        }
        prefix_max[0] = std::max(prefix_max[0], A[i] >= K ? A[i] / K : 0);
    }

    for(int i = 1; i <= MAX; i++) {
        prefix_max[i] = std::max(prefix_max[i - 1], prefix_max[i]);
    }

    int ans = MAX;
    for(int min_v = 0; min_v <= A[0]; min_v++) {
        ans = std::min(ans, prefix_max[min_v] - min_v);
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
