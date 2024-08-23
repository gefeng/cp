#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    if(N > M) {
        std::swap(N, M);
    }

    if(N == 1) {
        if(M == 1) {
            std::cout << 0 << '\n';
            return;
        }
        if(M == 2) {
            std::cout << 1 << '\n';
            return;
        }
        std::cout << -1 << '\n';
        return;
    }
    
    int ans = (N - 1) * 2;
    int x = M - N;
    
    ans += x % 2 == 0 ? x * 2 : x * 2 - 1;
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
