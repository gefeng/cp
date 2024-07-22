#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    std::string S, T;
    std::cin >> S >> T;
    
    int n = S.size();
    int m = T.size();

    int ans = INF;
    for(int i = 0; i <= m; i++) {
        int len = i; 
        int j = 0;
        int k = i;
        while(true) {
            if(j == n) {
                len += m - k;
                break;
            }
            if(k == m) {
                len += n - j;
                break;
            }
            if(S[j] == T[k]) {
                j += 1;
                k += 1;
            } else {
                j += 1;
            }
            len += 1;
        }
        ans = std::min(ans, len);
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
