#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    int64_t cnt_bad = 0;
    for(int k = L + 2; k <= R; k++) {
        int64_t cnt = 0;
        for(int f = 1; f * f <= k; f++) {
            if(k % f == 0) {
                if(f >= L && f < k) {
                    cnt += 1;
                }
                if(k / f != f && k / f >= L && k / f < k) {
                    cnt += 1;
                }
            }
        }
        cnt_bad += cnt * (cnt - 1) / 2;
    } 

    for(int k = L + 2; k <= R; k++) {
        std::vector<int> divisors;
        for(int f = 1; f * f <= 2 * k; f++) {
            if(k * 2 % f == 0) {
                if(f >= L && f < k) {
                    divisors.push_back(f);
                }
                if(k * 2 / f != f && k * 2 / f >= L && k * 2 / f < k) {
                    divisors.push_back(k * 2 / f);
                }
            }
        }
        std::ranges::sort(divisors);

        int n = divisors.size();
        for(int i = 0; i < n; i++) {
            auto it = std::lower_bound(divisors.begin() + i + 1, divisors.end(), k - divisors[i] + 1);
            cnt_bad += divisors.end() - it;
        }
    }

    int64_t tot = R - L + 1;
    int64_t ans = tot * (tot - 1) * (tot - 2) / 6 - cnt_bad;
    
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
