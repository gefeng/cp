#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int MAX = static_cast<int>(1e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool sorted = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            sorted = false;
        }
    }
    if(sorted) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> a(A);
    std::ranges::sort(a);

    int lo = 0;
    int hi = MAX;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = true;
        for(int i = 0; i < N; i++) {
            if(A[i] != a[i]) {
                if(A[i] - mid < a[0] && A[i] + mid > a.back()) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
