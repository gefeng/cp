#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e16;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t res = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t cur = mid;
        for(int x : A) {
            cur += x;
            if(cur < 0) {
                break;
            }
        }

        if(cur < 0) {
            lo = mid + 1;
        } else {
            res = mid;
            hi = mid - 1;
        }
    }

    int64_t ans = res;
    for(int x : A) {
        ans += x;
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
