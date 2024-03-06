#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = (int64_t)998244353;

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
    int N, X;
    std::cin >> N >> X;
    
    std::map<int, int64_t> m;
    std::vector<int> divisors;
    for(int f = 1; f * f <= X; f++) {
        if(X % f == 0) {
            divisors.push_back(f);
            if(X / f != f) {
                divisors.push_back(X / f);
            }
        } 
    }

    std::sort(divisors.begin(), divisors.end());
    
    for(int d : divisors) {
        int64_t res = 0;
        if(d == 1) {
            res = N % MOD;
        } else {
            int cnt = 0;
            for(int x : divisors) {
                if(d % x == 0) {
                    cnt += 1;
                }
            }

            int64_t s = (q_pow(cnt, N) - 1 + MOD) % MOD;
            int64_t t = q_pow(cnt - 1, MOD - 2);
            res = cnt * (s * t % MOD) % MOD;
            
            for(int x : divisors) {
                if(d % x == 0 && x < d) {
                    res -= m[x];
                    res += MOD;
                    res %= MOD;
                }
            }
        }

        m[d] = res;
    }

    std::cout << m[X] << '\n';
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
