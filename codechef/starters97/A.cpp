#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // 1000
    // 100120012
    // 1000020 1000020
    int N, K;
    std::cin >> N >> K;

    // 100020
    // 1002 1

    // 102 102 k = 1 
    // 100020 1002 1002 k = 3
    // 1000020  
    // 1002       2 
    // 100020     3
    // 1000020    4
    // 100000200  5
    int64_t ans = 0;

    if(K == 1) {
        ans += (int64_t)3 * (N / 3) + (N % 3 == 0 ? 0 : 1);
    } else {
        int len = K + 2 + (K - 1) / 2;
        int rem = N % len;
        ans += (int64_t)3 * (N / len);

        if(rem != 0) {
            ans += rem < K + 2 ? 1 : 3;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
