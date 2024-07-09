#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t MAX1 = (int64_t)1e6;
constexpr int64_t MAX2 = (int64_t)1e9;

void run_case() {
    int64_t N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t ub = (int64_t)sqrtl(N);

    int64_t ans = 1 + std::max((int64_t)0, ub - MAX1);
    std::set<int64_t> vis;
    for(int64_t a = 2; a <= std::min(MAX1, N); a++) {
        int64_t x = a * a;
        if(vis.find(x) != vis.end() || x > N) {
            continue; 
        }

        while(true) {
            vis.insert(x);
            ans += 1;
            if(x > MAX1 && x <= MAX2 && x * x <= N) {
                ans -= 1;
            }
            if(x <= N / a) {
                x *= a;
            } else {
                break;
            }
        } 
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
