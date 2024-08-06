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

    std::array<int, 4> cnt = {};
    for(int i = 0; i < N * 4; i++) {
        if(S[i] == '?') {
            continue;
        } 
        cnt[S[i] - 'A'] += 1;
    }

    int ans = 0;
    for(int i = 0; i < 4; i++) {
        ans += std::min(N, cnt[i]);
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
