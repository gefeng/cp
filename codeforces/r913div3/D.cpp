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

    std::vector<int> L(N);
    std::vector<int> R(N);
    for(int i = 0; i < N; i++) {
        std::cin >> L[i] >> R[i];
    }

    int lo = 0;
    int hi = (int)1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int pl = 0;
        int pr = 0;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int l = pl - mid;
            int r = pr + mid;

            if(r < L[i] || l > R[i]) {
                ok = false;
                break;
            } 
            
            pl = std::max(l, L[i]);
            pr = std::min(r, R[i]);
        }

        if(ok) {
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
