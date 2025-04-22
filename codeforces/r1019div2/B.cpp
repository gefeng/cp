#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    S = "0" + S;
    N += 1;

    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] != S[i - 1]) {
            ans += 1;
        } 
        ans += 1;
    }

    int pre = -1;
    for(int i = 1; i < N; i++) {
        if(S[i - 1] == '0' && S[i] == '1') {
            if(pre != -1) {
                std::cout << ans - 2 << '\n';
                return;
            }
            pre = i;
        }
    }

    pre = -1;
    for(int i = 1; i < N; i++) {
        if(S[i - 1] == '1' && S[i] == '0') {
            if(pre != -1) {
                std::cout << ans - 2 << '\n';
                return;
            }
            pre = i;
        }
    }

    pre = -1;
    for(int i = 1; i < N; i++) {
        if(S[i - 1] != S[i]) {
            if(pre != -1) {
                std::cout << ans - 1 << '\n';
                return;
            }
            pre = i;
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
