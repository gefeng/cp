#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    std::string S;
    std::cin >> S;

    int64_t ans = 0;
    int n = S.size();
    
    for(int l = 0, r = 0; r < n; r++) {
        while(l < r && S[r] == S[r - 1]) {
            l++;
        }

        ans += r - l + 1;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
