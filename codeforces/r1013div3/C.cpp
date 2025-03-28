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

    if(N % 2 == 0) {
        std::cout << -1 << '\n';
        return;
    }

    // 1 2 3 4 5
    // 1 3 5 2 4
    // 4 1 3 5 2
    // 2 4 1 3 5
    // 5 2 4 1 3
    // 3 5 2 4 1

    std::vector<int> ans(N, 0);
    for(int i = 0, j = 1; i < N / 2 + 1; i++, j += 2) {
        ans[i] = j;
    } 
    
    for(int i = N / 2 + 1, j = 2; i < N; i++, j += 2) {
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
