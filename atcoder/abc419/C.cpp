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
    int N;
    std::cin >> N;
    
    std::vector<int> X(N);
    std::vector<int> Y(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::ranges::sort(X);
    std::ranges::sort(Y);

    int mx1 = (X.back() + X.front()) / 2;
    int my1 = (Y.back() + Y.front()) / 2;
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int dx = std::abs(X[i] - mx1);
        int dy = std::abs(Y[i] - my1);
        ans = std::max(ans, std::max(dx, dy));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
