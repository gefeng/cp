#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::string S, T;
    std::cin >> S >> T;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            cnt += 1;
        }
    }

    if(cnt % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    if(cnt > 2) {
        std::cout << static_cast<int64_t>(Y) * (cnt / 2) << '\n';
        return;
    }

    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            if(pre != -1) {
                if(pre + 1 == i) {
                    std::cout << std::min(X, Y * 2) << '\n';
                } else {
                    std::cout << Y << '\n';
                }
                return;
            }
            pre = i;
        }
    }

    std::cout << 0 << '\n';
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
