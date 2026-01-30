#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    if(n < 3) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += S[i] - '0';
    }
    // std::ranges::count_if(S, [](char c) { return c == '1'; });
    // std::cout << cnt << '\n';
    std::cout << (cnt == n - cnt ? cnt - 1 : std::min(cnt, n - cnt)) << '\n';
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
