#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    int64_t ans = 1;
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && S[i + 1] != S[i]) {
            i += 1;
        }

        int len = i - j + 1;
        if(len > 1) {
            ans *= (len + 1) / 2 - 1 + 1;
            ans %= MOD;
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
