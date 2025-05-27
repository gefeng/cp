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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ans += 1;
        } else {
            int d = S[i - 1] - S[i];
            if(d < 0) {
                d += 10;
            }
            
            ans += d + 1;
        }
    }

    ans += S.back() - '0';

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
