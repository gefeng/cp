#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int(2e9);

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto overlap = [](int64_t l, int64_t r, int64_t x, int64_t y) {
        if(l > x) {
            std::swap(l, x);
            std::swap(r, y);
        }   
        return x >= l && x <= r;
    };

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t h = 0;

    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        bool ok = true;
        std::vector<std::pair<int64_t, int64_t>> a(N);
        for(int i = 0; i < N; i++) {
            if(A[i].first + A[i].second < mid) {
                ok = false; 
                break;
            }

            int64_t x = A[i].first + A[i].second - mid;
            int64_t d = std::min(x, A[i].first);
            a[i].first = A[i].first - d;
            
            d = std::min(x, A[i].second);
            a[i].second = A[i].first - (x - d);
        }

        int64_t l = a[0].first;
        int64_t r = a[0].second;
        for(int i = 1; i < N; i++) {
            int64_t nl = a[i].first;
            int64_t nr = a[i].second;

            if(overlap(l - X, r + X, nl, nr)) {
                l = std::max(l - X, nl);
                r = std::min(r + X, nr);
            } else {
                ok = false;
                break;
            }
        }

        if(ok) {
            h = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i].first + A[i].second - h; 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
