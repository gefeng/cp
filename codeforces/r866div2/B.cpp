#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int64_t ans = 0;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }
        
        if(S[j] == '1') {
            int len = i - j + 1;
            int64_t x = len / 2;
            int64_t y = (len + 1) / 2;
            ans = std::max(ans, x * y);
        }
    }

    if(S[0] == '1' && S.back() == '1') {
        int len = 0;
        for(int i = 0; i < n && S[i] == '1'; i++) {
            len += 1;
        }
        for(int i = n - 1; i >= 0 && S[i] == '1'; i--) {
            len += 1;
        }
        if(len < n) {
            len += 1;
            int64_t x = len / 2;
            int64_t y = (len + 1) / 2;
            ans = std::max(ans, x * y);
        } else {
            ans = static_cast<int64_t>(n) * n;
        }
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
