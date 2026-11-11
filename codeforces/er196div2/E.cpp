#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);
constexpr int MAX = 5000;

// put x objects into y boxes
std::vector<std::vector<int64_t>> comb(MAX + 1, std::vector<int64_t>(MAX + 1, 0));

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;


    int64_t cost = 0;
    int64_t ways = 1;
    std::vector<int64_t> dp1(N + 1, 0);

    for(int i = 2; i <= N; i++) {
        if(i == 2 || i == 3) {
            dp1[i] = 1;
        } else {
            dp1[i] = (dp1[i - 2] + dp1[i - 3]) % MOD;
        }
    }

    std::array<int, 2> freq{}; // consecutive 0s and 1s
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && S[i + 1] != S[i]) {
            i++;
        }

        if(i != j) {
            cost += 2 * (i - j + 1);
            ways *= dp1[i - j + 1];
            ways %= MOD;
        } else {
            cost++;
            freq[S[i] - '0']++;
        }
    }

    for(int i = 0; i < 2; i++) {
        int64_t sum = 0;

        for(int j = 1; j <= freq[i]; j++) {
            sum += comb[freq[i]][j];
            sum %= MOD;
        }
        if(sum) {
            ways *= sum;
            ways %= MOD;
        }
    }

    std::cout << cost << ' ' << ways << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] * j % MOD) + comb[i - 1][j - 1];
            comb[i][j] %= MOD;
        }
    } 
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
