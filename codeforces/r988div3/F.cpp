#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = int(1e9);

void run_case() { 
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> H(N);
    std::vector<int> P(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = -1;
    
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        std::map<int64_t, int> diff;

        for(int i = 0; i < N; i++) {
            int64_t t = (H[i] + mid - 1) / mid;
            int64_t l = P[i] - M + t;
            int64_t r = P[i] + M - t;
            if(l <= r) {
                diff[l] += 1;
                diff[r + 1] -= 1;
            }
        }

        bool ok = false;
        int64_t k = 0;
        for(auto [v, f] : diff) {
            k += f;
            if(k >= K) {
                ok = true;
                break;
            }
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
