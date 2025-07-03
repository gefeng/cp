#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    if((L << 1) <= R) {
        std::cout << L << ' ' << (L << 1) << '\n';
    } else {
        std::cout << -1 << ' ' << -1 << '\n';
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
