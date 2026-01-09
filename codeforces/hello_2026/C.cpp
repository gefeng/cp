#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    int ans = 0;
    auto solve = [&]() {
        for(int i = 0; i < K; i++) {
            int l = std::max(0, i - 1) + i;
            int s = 1;
            if(l <= M) {
                s += i;
                int rem = M - l;
                int have = i;

                if(have >= rem) {
                    s += std::min(rem, N - K); 
                } else {
                    if(have >= N - K) {
                        s += N - K;
                    } else {
                        int extra = std::max(0, rem - 2 * have) / 2;
                        s += std::min(N - K, extra + i);
                    }
                }
            }
            ans = std::max(ans, s);
        }
    };

    solve();
    K = N - K + 1;
    solve();

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
