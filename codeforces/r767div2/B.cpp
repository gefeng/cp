#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R, K;
    std::cin >> L >> R >> K;

    if(L == R) {
        std::cout << (L == 1 ? "NO" : "YES") << '\n';
        return;
    }
    
    int cnt = 0;
    if(L % 2 == 1 && R % 2 == 1) {
        cnt = (R - L + 1 + 1) / 2;
    } else if(L % 2 == 1 || R % 2 == 1) {
        cnt = (R - L + 1) / 2;
    } else {
        cnt = (R - L + 1) / 2;
    }

    std::cout << (K >= cnt ? "YES" : "NO") << '\n';
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
