#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> X(N);
    std::vector<int> Y(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> Y[i];
    }

    std::ranges::sort(X);

    std::vector<int> suffix(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        int j = std::ranges::upper_bound(X, X[i] + K) - X.begin();
        suffix[i] = i == N - 1 ? j - i : std::max(suffix[i + 1], j - i);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int j = std::ranges::upper_bound(X, X[i] + K) - X.begin();
        ans = std::max(ans, j - i + (j == N ? 0 : suffix[j]));
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
