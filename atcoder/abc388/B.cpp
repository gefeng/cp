#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    for(int k = 1; k <= D; k++) {
        int max_w = 0;
        for(auto [t, l] : A) {
            max_w = std::max(max_w, t * (l + k));
        }
        std::cout << max_w << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
