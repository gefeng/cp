#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 3000;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = MAX;
    for(int mx = 1; mx <= MAX; mx++) {
        int max_v = -1;
        int min_v = MAX + 1;
        bool good = true;
        for(int i = 0; i < N; i++) {
            int x = A[i] / mx;
            int cand = -1;
            for(int d = -1; d <= 1; d++) {
                int y = x + d;
                if(y >= 1 && y <= K) {
                    int z = A[i] / y;
                    if(z <= mx) {
                        cand = std::max(cand, z);
                    }
                }
            }
            if(cand == -1) {
                if(A[i] / K <= mx) {
                    cand = A[i] / K;
                }
            }

            if(cand == -1) {
                good = false;
                break;
            }
            max_v = std::max(max_v, cand);
            min_v = std::min(min_v, cand);
        }
        if(good) {
            ans = std::min(ans, max_v - min_v);
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
