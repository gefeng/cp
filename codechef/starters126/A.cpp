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

    int ans = N - 2;
    for(int i = 1; i < N - 2; i++) {
        if(S[i] == S[i - 1] && S[i] == S[i + 2] && S[i + 1] != S[i]) {
            ans -= 1; 
        }
    }

    int cnt = 0;
    for(int i = 0; i < N - 2; i++) {
        if(S[i] == S[i + 1] && S[i] == S[i + 2]) {
            if(++cnt > 1) {
                ans -= 1;
            }
        } 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
