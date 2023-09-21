#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);
   
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> save(N, 1);
    for(int i = N - 2; i >= 0; i--) {
        if(B[i] % B[i + 1] == 0) {
            save[i] = save[i + 1] + 1;
        } else {
            save[i] = 1;
        }
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }


    int lo = 0;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = false;
        for(int i = 0; i < N; i++) {
            if(save[i] >= mid) {
                int r = std::min(save[i] + i, i + mid);
                int64_t sum = psum[r] - psum[i];
                if(sum <= K) {
                    ok = true;
                    break;
                }
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
