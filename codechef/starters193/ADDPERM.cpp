#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <ranges>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ans(N, 0);
    std::iota(ans.begin(), ans.end(), 1);
    
    std::ranges::reverse(ans.begin(), ans.begin() + N - K + 1);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
