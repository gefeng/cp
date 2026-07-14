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
    
    if(N == 2) {
        std::cout << -1 << '\n';
        return;
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int64_t> ans(N);
    for(int i = 0; i < 3; i++) {
        ans[i] = i + 1;
    }

    int64_t now = 6;
    for(int i = 3; i < N; i++) {
        ans[i] = now;
        now *= 2;
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
