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
    int last = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(S[i] != '0') {
            last = i;
            break;
        }
    }
    
    int ans = n - 1 - last;
    for(int i = 0; i < last; i++) {
        if(S[i] != '0') {
            ans += 1;
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
