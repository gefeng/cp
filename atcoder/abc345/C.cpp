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

    std::array<int, 26> cnt = {};
    int64_t ans = 0;
    int tot = 0;
    for(int i = S.size() - 1; i >= 0; i--) {
        cnt[S[i] - 'a'] += 1;
        tot += 1;
        ans += tot - cnt[S[i] - 'a']; 
    }

    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 1) {
            ans += 1; 
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
