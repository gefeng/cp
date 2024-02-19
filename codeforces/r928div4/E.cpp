#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int cnt_odd = (N + 1) / 2;
    if(K <= cnt_odd) {
        std::cout << 2 * K - 1 << '\n';
        return;
    }

    int left = N - cnt_odd;
    K -= cnt_odd;

    int t = 2;
    while(true) {
        int cnt = (left + 1) / 2;
        if(K <= cnt) {
            std::cout << (2 * K - 1) * t << '\n';
            return;
        }

        K -= cnt;
        left -= cnt;

        t *= 2;
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
