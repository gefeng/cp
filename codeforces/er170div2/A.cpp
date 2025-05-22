#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;
    
    int n = S.size();
    int m = T.size();
    
    int ans = 0;
    int i = 0;
    for(; i < std::min(n, m); i++) {
        if(S[i] == T[i]) {
            ans += 1;
        } else {
            break;     
        }
    }

    if(i) {
        ans += 1;
    }
    
    ans += n - i + m - i;
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
