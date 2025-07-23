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

    if(N <= 3) {
        std::cout << N << '\n';
        return;
    }

    int ans = 3;
    int cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(S[r] == '1') {
            cnt += 1;
        }
        while(cnt > 1) {
            if(S[l] == '1') {
                cnt -= 1;
            }
            l += 1;
        }
        ans = std::max(ans, r - l + 1);
    }

    cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(S[r] == '0') {
            cnt += 1;
        }
        while(cnt > 1) {
            if(S[l] == '0') {
                cnt -= 1;
            }
            l += 1;
        }
        ans = std::max(ans, r - l + 1);
    }

    if(S.find("0101") != std::string::npos || S.find("1010") != std::string::npos) {
        ans = std::max(ans, 4);
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
