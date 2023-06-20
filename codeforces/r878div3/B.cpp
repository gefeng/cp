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
    int N, K;
    std::cin >> N >> K;

    // 1 2 4 8 16 32 ... 2^30
    
    int hb = -1;
    for(int i = 30; i >= 0; i--) {
        if(N & (1 << i)) {
            hb = i;
            break;
        }
    }

    if(K - 1 < hb) {
        std::cout << (int)pow(2, K) << '\n'; 
    } else {
        std::cout << N + 1 << '\n';
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
