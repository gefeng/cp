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
    int p = 0;
    while(p < n && S[p] == '1') {
        p += 1; 
    }

    if(p == n) {
        std::cout << 1 << '\n';
        return;
    }

    ans += p == 0 ? 0 : 1;
    while(p < n && S[p] == '0') {
        p += 1;
    }

    if(p == n) {
        std::cout << ans + 1 << '\n';
        return;
    }

    ans += 1;
    while(p < n && S[p] == '1') {
        p += 1;
    }

    for(int i = p; i < n; ) {
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }
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
