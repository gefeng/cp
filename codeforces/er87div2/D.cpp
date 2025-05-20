#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

constexpr int MAX = int(1e6);

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    std::vector<int> B(Q);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        std::cin >> B[i];
    }

    auto check = [&](int x) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] <= x) {
                cnt += 1;
            }
        }

        for(int i = 0; i < Q; i++) {
            if(B[i] > 0) {
                if(B[i] <= x) {
                    cnt += 1;
                }
            } else {
                if(-B[i] <= cnt) {
                    cnt -= 1;
                }
            }
        }
        return cnt > 0;
    };

    int lo = 1;
    int hi = MAX;
    int ans = 0;

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
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
    
    run_case();
}
