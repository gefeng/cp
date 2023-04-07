#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL K, N;
    std::cin >> N >> K;

    if(N % 2 == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    if(K % 2 == 0) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
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
