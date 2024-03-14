#include <iostream>
#include <utility>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e18;

void run_case() {
    int64_t K;
    std::cin >> K;

    std::vector<int64_t> p9(20, 1);
    for(int i = 1; i < 20; i++) {
        p9[i] = p9[i - 1] * 9;
    } 
    
    auto count = [&](int64_t x) -> int64_t {
        int64_t res = 0;
        std::vector<int> digits;
        
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int n = digits.size();

        for(int i = 1; i <= n - 1; i++) {
            res += p9[i];
        }

        res += (digits[n - 1] - 1) * p9[n - 1];
        
        bool ok = true;
        for(int i = n - 2; i >= 0; i--) {
            res += digits[i] <= digits[i + 1] ? digits[i] * p9[i] : (digits[i] - 1) * p9[i];
            if(digits[i] == digits[i + 1]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            res += 1;
        }

        return res;
    };

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        if(count(mid) >= K) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
