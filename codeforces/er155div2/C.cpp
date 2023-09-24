#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    std::vector<int64_t> p(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * i % MOD;
    }

    int min_o = 0;
    int sum = 0;
    int64_t cnt = 1;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }

        min_o += i - j - 1;
        if(i - j > 1) {
            sum += i - j - 1;
            cnt *= i - j;
            cnt %= MOD;
        }
    }

    cnt *= p[sum];
    cnt %= MOD;

    std::cout << min_o << ' ' << cnt << '\n';
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
