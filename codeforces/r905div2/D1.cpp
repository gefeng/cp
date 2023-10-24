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
    A[0] = 1;
    for(int i = 1; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int lo = 0;
    int hi = N;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = true;
        for(int i = 0; i < N - mid; i++) {
            if(A[i] >= B[i + mid]) {
                ok = false;
                break;
            }
        }

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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
