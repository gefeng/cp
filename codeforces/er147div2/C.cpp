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
        int tot = 0;
        //bool valid = false;
        for(int i = 0; i < n; i++) {
            if(S[i] != c) {
                cnt += 1;
            } 
            if(S[i] == c || i == n - 1) {
                int step = 0;
                while(cnt) {
                    cnt /= 2;
                    step += 1;
                }
                tot = std::max(tot, step);
            }
        }

        ans = std::min(ans, tot);
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
