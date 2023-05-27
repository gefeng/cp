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
    int ans = -1;
    std::array<int, 26> cnt = {};
    for(int i = 0, j = 0; j < n; j++) {
        int c = S[j] - 'a';
        
        cnt[c] += 1;

        if(j - i + 1 > 14) {
            cnt[S[i++] - 'a'] -= 1;
        }

        if(j - i + 1 == 14) {
            bool ok = true;
            for(int k = 0; k < 26; k++) {
                if(cnt[k] > 1) {
                    ok = false;
                    break;
                } 
            }

            if(ok) {
                ans = j + 1;
                break;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
