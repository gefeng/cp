#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t MAX = int64_t(1e15);

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto check = [&](int64_t t) {
        int64_t cnt = 0;
        int64_t sum = 0;
        std::vector<int> a(A);
        for(int i = 0; i < N; i++) {
            if(sum + a[i] < t) {
                sum += a[i];
            } else {
                cnt += 1;
                a[i] = sum + a[i] - t;
                sum = 0;
                if(a[i]) {
                    i -= 1;
                }
            }
            if(cnt > X) {
                break;
            }
        }
        if(cnt <= X && sum) {
            cnt += 1;
        }
        return cnt <= X;
    };

    int64_t lo = *std::max_element(A.begin(), A.end());
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        if(check(mid)) {
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
