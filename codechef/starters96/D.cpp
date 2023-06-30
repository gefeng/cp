#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)1e18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<LL> psum_odd(N + 1, 0);
    std::vector<LL> psum_eve(N + 1, 0);

    for(int i = 1; i <= N; i += 1) {
        psum_odd[i] = psum_odd[i - 1] + (i % 2 == 0 ? A[i - 1] : 0);
        psum_eve[i] = psum_eve[i - 1] + (i % 2 == 1 ? A[i - 1] : 0);
    }

    if(N % 2 == 0) {
        if(psum_odd[N] != psum_eve[N]) {
            std::cout << "NO" << '\n';
            return;
        }

        LL l = -INF;
        LL r = INF;
        for(int i = 1; i < N; i++) {
            LL alt_sum = psum_odd[i + 1] - psum_odd[1] - (psum_eve[i + 1] - psum_eve[1]);
            
            if(i & 1) {
                r = std::min(r, alt_sum);
            } else {
                l = std::max(l, alt_sum);
            }
        }

        if(l <= r && r >= 0) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    } else {
        LL sum = A[0] + psum_odd[N] - psum_odd[1] - (psum_eve[N] - psum_eve[1]);
        
        if(sum < 0 || (sum & 1)) {
            std::cout << "NO" << '\n';
            return;
        }

        LL b0 = sum / 2;
        
        LL pre = b0;
        for(int i = 1; i < N; i++) {
            LL cur = A[i] - pre; 
            if(cur < 0) {
                std::cout << "NO" << '\n';
                return;
            }
            pre = cur;
        }

        std::cout << "YES" << '\n';
    }
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
