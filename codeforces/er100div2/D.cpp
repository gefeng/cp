#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> have((N << 1) + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        have[A[i]] = 1;
    }

    std::vector<int> missing;
    for(int i = 1; i <= (N << 1); i++) {
        if(!have[i]) {
            missing.push_back(i);
        }
    }

    int ans = 0;
    int prefix = 0;
    int suffix = 0;
    int lo = 1;
    int hi = N;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = true;
        for(int i = N - mid, j = 0; i < N; i++, j++) {
            if(A[i] < missing[j]) {
                ok = false;
                break;
            } 
        }

        if(ok) {
            suffix = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    lo = 1;
    hi = N;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = true;
        for(int i = 0, j = N - mid; i < mid; i++, j++) {
            if(A[i] > missing[j]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            prefix = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if(prefix + suffix >= N) {
        ans = prefix - (N - suffix) + 1;
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
