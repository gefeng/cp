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

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 1; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto cnt_remove = [&](int c) {
        std::vector<int> a(A);
        std::vector<int> b(B);
        a[0] = c;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        
        int lo = 0;
        int hi = N;
        int remove = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            bool ok = true;
            for(int i = 0; i < N - mid; i++) {
                if(a[i] >= b[i + mid]) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                remove = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }    

        return remove;
    };

    int min_remove = cnt_remove(1);

    int lo = 1;
    int hi = M;
    int x = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int res = cnt_remove(mid);
        
        if(res == min_remove) {
            x = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int64_t ans = (int64_t)min_remove * x + ((int64_t)min_remove + 1) * (M - x);
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
