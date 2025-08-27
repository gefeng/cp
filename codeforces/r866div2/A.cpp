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
    for(int i = 1; i < n; i++) {
        if(S[i] == '_' && S[i - 1] == '_') {
            ans += 1;
        }
    }

    if(S.front() == '_') {
        ans += 1;
    }
    if(S.back() == '_') {
        ans += 1;
    }

    if(n == 1 && S[0] == '^') {
        ans += 1; 
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
