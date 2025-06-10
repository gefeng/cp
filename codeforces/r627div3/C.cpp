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
    int lo = 1;
    int hi = n;
    int ans = n + 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
    
        int p = 0;
        while(p != n + 1) {
            if(p + mid >= n + 1) {
                p = n + 1;
                break;
            }

            bool end = true;
            int n_p = 0;
            for(int i = 1; i <= mid; i++) {
                if(S[p + i - 1] == 'R') {
                    n_p = p + i;
                    end = false;
                }
            }

            if(end) {
                break;
            }
            p = n_p;
        }

        if(p == n + 1) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
