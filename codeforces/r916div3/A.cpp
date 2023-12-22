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

    std::array<int, 26> cnt = {};
    for(int i = 0; i < N; i++) {
        cnt[S[i] - 'A'] += 1; 
    }

    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= i + 1) {
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
