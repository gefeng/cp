#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)2e18;

void run_case() {
    int Q;
    std::cin >> Q;

    auto overlap = [](LL x1, LL y1, LL x2, LL y2) {
        if(x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        return x2 <= y1;
    };

    std::vector<LL> ans(Q);
    LL l = -1LL;
    LL r = INF;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int A, B, N;
            std::cin >> A >> B >> N;

            LL nl = 0LL;
            LL nr = 0LL;
            if(N == 1) {
                nl = 1LL;
                nr = A;
            } else {
                nl = 1LL * A * (N - 1) - 1LL * B * (N - 2) + 1LL;
                nr = 1LL * A * (N - 1) - 1LL * B * (N - 1) + A;
            }

            if(l == -1LL || overlap(l, r, nl, nr)) {
                l = std::max(l, nl);
                r = std::min(r, nr);
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        } else {
            int A, B;
            std::cin >> A >> B;

            if(l == -1LL) {
                ans[i] = -1;
            } else {
                LL min_d = std::max(1LL, (l + A - 2LL * B - 1LL) / (A - B));
                LL max_d = std::max(1LL, (r + A - 2LL * B - 1LL) / (A - B));

                if(min_d == max_d) {
                    ans[i] = min_d;
                } else {
                    ans[i] = -1;
                }
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << " \n"[i == Q - 1];
    }
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
