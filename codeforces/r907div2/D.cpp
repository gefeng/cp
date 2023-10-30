#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;
constexpr int MAX = 62;

std::vector<int64_t> p2;
std::vector<std::pair<int64_t, int64_t>> gx;

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;
    L -= 1;

    int64_t ans = 0;
    int64_t sum1 = 0;
    int64_t sum2 = 0;
    
    int size = gx.size();
    for(int i = 0; i < size; i++) {
        if(L < gx[i].first) {
            break; 
        }
        
        int64_t cnt = i + 1 < size ? std::min(L + 1, gx[i + 1].first) - gx[i].first : L + 1 - gx[i].first;
        
        sum1 += (cnt % MOD) * (gx[i].second % MOD) % MOD;
        sum1 %= MOD;
    }

    for(int i = 0; i < size; i++) {
        if(R < gx[i].first) {
            break; 
        }
        
        int64_t cnt = i + 1 < size ? std::min(R + 1, gx[i + 1].first) - gx[i].first : R + 1 - gx[i].first;
        
        sum2 += (cnt % MOD) * (gx[i].second % MOD) % MOD;
        sum2 %= MOD;
    }
    
    ans = (sum2 - sum1 + MOD) % MOD;
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    p2 = std::vector<int64_t>(MAX, 1);
    for(int i = 1; i < MAX; i++) {
        p2[i] = p2[i - 1] * 2; 
    } 

    for(int i = 2; i < MAX - 1; i++) {
        int64_t z = 1;
        int64_t x = i;
        
        while(x <= p2[i] / i) {
            x *= i;
            z += 1;
        }

        gx.emplace_back(p2[i], z);
        while(x <= (p2[i + 1] - 1) / i) {
            x *= i;
            z += 1;
            gx.emplace_back(x, z);
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
