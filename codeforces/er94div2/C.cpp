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
    
    int X;
    std::cin >> X;

    int n = S.size();
    std::vector<int> is_zero(n, 0);
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            if(i - X >= 0) {
                is_zero[i - X] = 1;
            }
            if(i + X < n) {
                is_zero[i + X] = 1;
            }
        } 
    }

    for(int i = 0; i < n; i++) {
        if(S[i] == '1') {
            if((i - X >= 0 && !is_zero[i - X]) || (i + X < n && !is_zero[i + X])) {
                continue;
            }
            std::cout << -1 << '\n';
            return;
        }
    }

    std::string ans(n, '1');
    for(int i = 0; i < n; i++) {
        if(is_zero[i]) {
            ans[i] = '0';
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
