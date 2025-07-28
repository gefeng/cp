#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int INF = int(2e9) + 10;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = *std::ranges::min_element(A);
    int hi = *std::ranges::max_element(A);
    int ans = 0;
    int x = -1;
    int y = -1;

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::vector<int> a(N, 0);
        for(int i = 0; i < N; i++) {
            if(A[i] >= mid) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }

        int lb = -1;
        int rb = -1;
        bool ok = false;
    
        std::vector<int64_t> psum(N + 1, 0);
        int min_s = 0;
        int j = -1;
        for(int l = 0, r = 0; r < N; r++) {
            psum[r + 1] = psum[r] + a[r];
            if(r - l + 1 > K) {
                if(psum[l + 1] < min_s) {
                    min_s = psum[l + 1];
                    j = l;
                }
                l += 1;
            }
            if(r - l + 1 == K) {
                if(psum[r + 1] >= min_s) {
                    lb = j + 1;
                    rb = r;
                    ok = true;
                    break;
                }
            }
        }

        if(ok) {
            ans = mid;
            x = lb;
            y = rb;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
     
    std::cout << ans << ' ' << x + 1 << ' ' << y + 1 << '\n';
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
