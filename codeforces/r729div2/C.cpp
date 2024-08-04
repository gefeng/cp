#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    } 
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int64_t N;
    std::cin >> N;
    
    int64_t ans = (N + 1) / 2 * 2;
    ans %= MOD;
    
    int64_t have = N / 2;
    int64_t x = 3; 
    int64_t y = 2;
    while(have) {
        y = lcm(y, x);
        
        int64_t cnt = N / y;
        ans += (have - cnt) * x % MOD;
        ans %= MOD;
        
        x += 1;
        have = cnt;
    } 

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
