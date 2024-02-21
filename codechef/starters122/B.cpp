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
    
    int64_t ans = 0;
    int hb = -1;
    int lb = -1;
    for(int i = 30; i >= 0; i--) {
        if(N & (1 << i)) {
            hb = hb == -1 ? i : hb;
            lb = i;
        }
    }

    if(hb == -1 || lb == hb) {
        std::cout << ans << '\n';
        return;
    }

    for(int i = lb + 1; i < hb; i++) {
        if(N & (1 << i)) {
            continue;
        }
        ans |= 1 << i;
    }

    int64_t cost = 0;
    for(int i = 0; i < 30; i++) {
        hb = -1;
        lb = -1;
        for(int j = 30; j >= 0; j--) {
            if(N & (1 << j)) {
                hb = hb == -1 ? j : hb;
                lb = j;
            }
        }

        bool ok = true;
        for(int j = hb; j >= lb; j--) {
            if(!(N & (1 << j))) {
                ok = false;
                break;
            }
        }

        if(ok) {
            break;
        }

        cost += 1 << lb;
        N += 1 << lb;
    }

    ans = std::min(ans, cost);

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
