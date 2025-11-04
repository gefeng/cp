#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = 0;
    int hi = N - 1;
    int res = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int q = Q;
        bool ok = true;
        for(int i = mid; i < N; i++) {
            if(A[i] > q) {
                if(--q < 0) {
                    ok = false;
                    break;
                }
            } 
        }

        if(ok) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::string ans(N, '0');
    for(int i = 0; i < res; i++) {
        if(A[i] <= Q) {
            ans[i] = '1'; 
        }
    }
    for(int i = res; i < N; i++) {
        ans[i] = '1';
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
