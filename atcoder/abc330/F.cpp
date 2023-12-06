#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int> X(N);
    std::vector<int> Y(N);
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    int lo = 0;
    int hi = (int)1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = true;
        int64_t cnt = 0;
        for(int l = 0, r = N - 1; l < r; l += 1, r -= 1) {
            if(X[r] - X[l] > mid) {
                cnt += X[r] - X[l] - mid; 
            }
            if(Y[r] - Y[l] > mid) {
                cnt += Y[r] - Y[l] - mid; 
            }
        }

        ok = cnt <= K;
        
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
    std::cin.tie(nullptr);

    run_case();
}
