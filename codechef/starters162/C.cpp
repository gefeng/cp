#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int L, R, X;
    std::cin >> L >> R >> X;
    
    auto gen = [&]() {
        std::vector<int> all;
        for(int i = X - 1; i >= L; i--) {
            all.push_back(i ^ X);
        }

        all.push_back(0);

        for(int i = X + 1; i <= R; i++) {
            all.push_back(i ^ X);
        }

        std::sort(all.begin(), all.end());

        int n = all.size();
        int mex = 0;
        for(int i = 0; i < n; i++) {
            if(mex == all[i]) {
                mex++;
            } else {
                break;
            }
        }
        std::cout << mex << '\n';
    };

    if(X < L || X > R) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = INF;
    int now = 0;
    for(int i = 30; i >= 0; i--) {
        if(L & (1 << i)) {
            int x = now;
            for(int j = i - 1; j >= 0; j--) {
                if(X & (1 << j)) {
                    x |= 1 << j;
                }
            }
            if(x < L) {
                ans = std::min(ans, x ^ X);            
            }

            now |= 1 << i;
        }   
    }

    now = 0;
    for(int i = 30; i >= 0; i--) {
        if(!(R & (1 << i))) {
            int x = now | (1 << i);
            for(int j = i - 1; j >= 0; j--) {
                if(X & (1 << j)) {
                    x |= 1 << j;
                }
            }
            if(x > R) {
                ans = std::min(ans, x ^ X);
            }
        } else {
            now |= 1 << i;
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
