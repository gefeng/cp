#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MAX = 2e15;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    LL sum = 0LL;
    for(int x : A) {
        sum += x;
    }

    LL lo = 0LL;
    LL hi = MAX;
    LL ans = 0LL;

    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;
        
        bool ok = true; 
        int cnt = 0;
        if(mid * K > sum) {
            ok = false;
        } else {
            LL left = mid;
            for(int x : A) {
                if(x > left) {
                    x -= left;
                    cnt += 1;
                    
                    LL max_v = mid - left;
                    left = mid;
                    left -= std::min(max_v, (LL)x);
                } else {
                    left -= x;
                    if(left == 0) {
                        cnt += 1;
                        left = mid;
                    }
                } 

            }

            if(cnt < K) {
                ok = false; 
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
