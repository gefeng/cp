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
    bool unique = true;
    for(int i = 0; i < n; i++) {
        if(S[i] != S[0]) {
            unique = false;
        }
    }

    if(unique) {
        std::cout << S << '\n';
        return;
    }

    std::string ans = "";
    for(int i = 0; i < n; i++) {
        if(ans.empty() || S[i] != ans.back()) {
            ans.push_back(S[i]);
        } else {
            ans.push_back(S[i] == '0' ? '1' : '0');
            i -= 1;
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
