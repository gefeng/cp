#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int64_t MOD = int64_t(998244353);

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

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
    int64_t D;
    std::cin >> D;

    std::vector<int64_t> pf;
    for(int64_t f = 2; f * f <= D; f++) {
        if(D % f == 0) {
            while(D % f == 0) {
                D /= f;
            }
            pf.push_back(f);
        }
    }
    if(D > 1) {
        pf.push_back(D);
    }

    std::vector<int64_t> fact(100, 1);
    std::vector<int64_t> invf(100, 1);
    
    for(int i = 1; i < 100; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    auto get_dist = [&](int64_t s, int64_t t) {
        int64_t x = s / t; 
        int64_t res = 1;
        std::vector<int> a;
        for(int64_t p : pf) {
            if(x % p == 0) {
                int cnt = 0;
                while(x % p == 0) {
                    cnt += 1;
                    x /= p;
                }
                a.push_back(cnt);
            }
        } 

        int sum = std::accumulate(a.begin(), a.end(), 0);
        res = fact[sum];

        for(int f : a) {
            res *= invf[f];
            res %= MOD;
        }

        return res;
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int64_t U, V;
        std::cin >> U >> V;
        
        if(U == V) {
            std::cout << 1 << '\n';
            continue;
        }

        int64_t g = gcd(U, V);
        
        int64_t res = get_dist(U, g);
        res *= get_dist(V, g);
        res %= MOD;

        std::cout << res << '\n';
    }    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
