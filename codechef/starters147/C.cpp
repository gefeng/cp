#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    if(N <= M) {
        std::cout << -1 << '\n';
        return;
    }

    int lo = 1;
    int hi = N + M;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = false; 
        if(mid % 2 == 1) {
            ok = mid / 2 > M - 1;
        } else {
            ok = mid / 2 > M; 
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
