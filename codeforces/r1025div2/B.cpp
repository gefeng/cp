#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M, A, B;
    std::cin >> N >> M >> A >> B;

    auto solve = [](int n, int m) {
        int res = 0;
        while(n > 1) {
            res += 1;
            n = (n + 1) / 2;
        }
        while(m > 1) {
            res += 1;
            m = (m + 1) / 2;
        }
        return res;
    };

    int ans = INF; 
    if(A - 1 > 0) {
        ans = std::min(ans, solve(N - (A - 1), M));
    }
    
    if(A + 1 <= N) {
        ans = std::min(ans, solve(A, M));
    }

    if(B - 1 > 0) {
        ans = std::min(ans, solve(N, M - (B - 1)));
    }

    if(B + 1 <= M) {
        ans = std::min(ans, solve(N, B));
    }

    std::cout << ans + 1 << '\n';
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
