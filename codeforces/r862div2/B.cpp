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
    
    bool first = true;
    for(int i = 1; i < N; i++) {
        if(S[i] < S[0]) {
            first = false;
            break;
        }
    }

    std::string ans = "";
    if(first) {
        ans = S;
        for(int i = N - 1; i >= 0; i--) {
            if(S[i] == S[0]) {
                ans = std::string(1, S[i]) + S.substr(0, i) + S.substr(i + 1, N - i - 1);
                break;
            }
        }
    } else {
        char c = S[0];
        for(int i = 1; i < N; i++) {
            c = std::min(c, S[i]);
        }

        for(int i = N - 1; i >= 0; i--) {
            if(S[i] == c) {
                ans = std::string(1, S[i]) + S.substr(0, i) + S.substr(i + 1, N - i - 1);
                break;
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
