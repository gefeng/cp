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
    
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1; i < n; i++) {
        if(S[i - 1] == 'a' && S[i] == 'b') {
            cnt1 += 1;
        } 
        if(S[i - 1] == 'b' && S[i] == 'a') {
            cnt2 += 1;
        }
    }

    if(cnt1 > cnt2) {
        S[0] = 'b';
    } else if(cnt2 > cnt1) {
        S[n - 1] = 'b';
    }

    std::cout << S << '\n';
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
