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
    int N;
    std::cin >> N;

    std::vector<int> ans(N, 0);
    
    for(int i = N - 1, j = 1; i >= 0; i -= 2, j++) {
        ans[i] = j;
    }

    for(int i = N - 2, j = N; i >= 0; i -= 2, j--) {
        ans[i] = j;
    }

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
