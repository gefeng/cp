#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(2e5);

std::vector<int64_t> psum;

void run_case() {
    int L, R;
    std::cin >> L >> R;

    int64_t sum = psum[R] - psum[L - 1]; 
    int64_t ans = sum + psum[L] - psum[L - 1];
    std::cout << ans << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    psum.resize(MAX + 1, 0);
    for(int i = 1; i <= MAX; i++) {
        int x = i;
        int cnt = 0;
        while(x) {
            x /= 3;
            cnt += 1; 
        }
        psum[i] = psum[i - 1] + cnt;
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
