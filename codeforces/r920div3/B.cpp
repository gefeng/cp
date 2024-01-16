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

    std::string S, T;
    std::cin >> S >> T;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            continue;
        }

        if(S[i] == '1') {
            cnt1 += 1;
        } else {
            cnt2 += 1;
        }
    }

    int ans = 0;
    int d = std::min(cnt1, cnt2);
    ans += d;
    cnt1 -= d;
    cnt2 -= d;
    ans += cnt1 + cnt2;
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
