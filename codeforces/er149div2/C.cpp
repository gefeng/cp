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
    int p1 = 0;
    std::string ans(n, '*');
    while(p1 < n && S[p1] == '?') {
        ans[p1++] = '0';
    }

    if(p1 != n) {
        int p2 = n - 1;
        while(p2 >= 0 && S[p2] == '?') {
            ans[p2--] = '1';
        }

        char pre;
        for(int i = p1; i <= p2; i++) {
            if(S[i] == '?') {
                ans[i] = pre;
            } else {
                pre = S[i];
                ans[i] = S[i];
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
