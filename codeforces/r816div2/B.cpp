#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t S;
    int N, K, B;

    std::cin >> N >> K >> B >> S;
    
    int64_t x = static_cast<int64_t>(K) * B;
    
    if(x > S) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int64_t> ans(N);
    int64_t sum = x;
    ans[0] = x;
    
    for(int i = 0; i < N; i++) {
        if(sum < S) {
            int64_t d = std::min(S - sum, static_cast<int64_t>(K - 1));
            sum += d;
            ans[i] += d;
        }
    }

    if(sum < S) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
