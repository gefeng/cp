#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    int min_v = N;
    for(int x : A) {
        min_v = std::min(min_v, x);
    }

    int lo = 0;
    int hi = min_v;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int left = N - mid;
        int bad = A[0] - mid;
        int good = left - bad;
        for(int i = 1; i < M; i++) {
            int x = A[i] - mid;
            x = std::max(0, x - good);
            bad = std::min(bad, x);
            good = left - bad;
        }

        if(bad) {
            lo = mid + 1;
        } else {
            ans = mid;
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
