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

    if(S[0] == '0') {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 1;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '?') {
            if(i == 0) {
                ans *= 9;
            } else {
                ans *= 10;
            }
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
