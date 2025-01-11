#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;

    auto count = [](int64_t r) {
        if(r < 10) {
            return int64_t(0);
        }

        int64_t res = 0;
        std::vector<int> digits;
        
        while(r) {
            digits.push_back(r % 10);
            r /= 10;
        }

        int n = digits.size();

        for(int len = 2; len < n; len++) {
            for(int d = 1; d < 10; d++) {
                int64_t cnt = 1;
                for(int i = 0; i < len - 1; i++) {
                    cnt *= d;
                }
                res += cnt;
            }
        }

        for(int d = 1; d < digits.back(); d++) {
            int64_t cnt = 1;
            for(int i = 0; i < n - 1; i++) {
                cnt *= d; 
            }
            res += cnt;
        }

        std::reverse(digits.begin(), digits.end());
        for(int pref = 1; pref <= n; pref++) {
            bool ok = true;
            for(int i = 1; i < pref; i++) {
                if(digits[i] >= digits[0]) {
                    ok = false;
                    break;
                } 
            }
            if(ok) {
                if(pref == n) {
                    res += 1;
                } else {
                    for(int d = 0; d < std::min(digits[0], digits[pref]); d++) {
                        int64_t cnt = 1;
                        for(int j = pref + 1; j < n; j++) {
                            cnt *= digits[0]; 
                        }
                        res += cnt;
                    } 
                }
            }
        }

        return res;
    };

    std::cout << count(R) - count(L - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
