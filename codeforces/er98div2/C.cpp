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
    int s1 = 0;
    int s2 = 0;
    int ans =0;

    for(int i = 0; i < n; i++) {
        if(S[i] == '(') {
            s1 += 1;
        } else if(S[i] == '[') {
            s2 += 1;
        } else if(S[i] == ')') {
            if(s1) {
                s1 -= 1;
                ans += 1;
            }    
        } else {
            if(s2) {
                s2 -= 1;
                ans += 1;
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
