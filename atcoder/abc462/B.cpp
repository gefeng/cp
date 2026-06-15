#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ans(N);
    
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;

        for(int j = 0; j < K; j++) {
            int P;
            std::cin >> P;
            P--;
            ans[P].push_back(i);
        }
    }

    for(int i = 0; i < N; i++) {
        std::ranges::sort(ans[i]);
        int n = ans[i].size();
        std::cout << n << ' ';
        for(int j = 0; j < n; j++) {
            std::cout << ans[i][j] + 1 << " \n"[j == n - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
