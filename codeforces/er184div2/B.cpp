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
    if(n == 1) {
        std::cout << 1 << '\n';
        return;
    }

    for(int i = 0; i < n - 1; i++) {
        if((S[i] == '>' && S[i + 1] == '<') || (S[i] == '*' && S[i + 1] == '<') || 
                (S[i] == '>' && S[i + 1] == '*') || (S[i] == '*' && S[i + 1] == '*')) {
            std::cout << -1 << '\n';
            return;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == '<') {
            continue;
        }
        ans = std::max(ans, n - i);
        break;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(S[i] == '>') {
            continue;
        }
        ans = std::max(ans, i + 1);
        break;
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
