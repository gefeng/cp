#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL N;
    std::cin >> N;

    int cnt = __builtin_popcountll(N);
    LL ans = 0LL;
    if(cnt > 3) {
        for(int i = 63, j = 0; i >= 0 && j < 3; i--) {
            if(N & (1LL << i)) {
                ans |= (1LL << i); 
                j += 1;
            }
        }
    } else if(cnt == 3) {
        ans = N;
    } else if(cnt == 2) {
        int last = -1;
        int first = -1;
        for(int i = 0; i < 64; i++) {
            if(N & (1LL << i)) {
                last = last == -1 ? i : last;
                first = i;
            }
        }

        if(last > 1) {
            ans = N;
            for(int i = 0; i < 3; i++) {
                ans ^= 1LL << (last - i);
            }
        } else {
            if(first > 2) {
                for(int i = 1; i <= 3; i++) {
                    ans ^= 1LL << (first - i);
                }
            } else {
                ans = -1LL;
            }
        }
    } else if(cnt == 1) {
        int j = -1;
        for(int i = 0; i < 64; i++) {
            if(N & (1LL << i)) {
                j = i;
            }
        }

        if(j > 2) {
            for(int i = 1; i <= 3; i++) {
                ans ^= 1LL << (j - i);
            }
        } else {
            ans = -1LL;
        }
    } else {
        ans = -1LL;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
