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
    int ans = n;
    for(char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] == c) {
                cnt += 1;
            } 
        }

        if(cnt == 0) {
            continue;
        }

        int tot = cnt;
        cnt = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cnt += S[r] == c ? 1 : 0;
            while(r - l + 1 > tot) {
                cnt -= S[l] == c ? 1 : 0;
                l += 1;
            }

            if(r - l + 1 == tot) {
                ans = std::min(ans, tot - cnt);
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
