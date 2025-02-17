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
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum_pos(N + 1, 0);
    std::vector<int64_t> psum_neg(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum_pos[i + 1] = psum_pos[i] + (A[i] >= 0 ? A[i] : 0); 
        psum_neg[i + 1] = psum_neg[i] + (A[i] < 0 ? -A[i] : 0);
    }

    int l = 0;
    int r = N - 1;
    int64_t sum = 0;
    int64_t ans = 0;
    
    while(true) {
        if(l == r) {
            sum += std::abs(A[l]);
            ans = std::max(ans, sum);
            break;
        }
        
        while(l <= r && A[l] >= 0) {
            sum += A[l++];
        }

        while(l <= r && A[r] < 0) {
            sum += -A[r--];
        }

        ans = std::max(ans, sum);
        
        if(l > r) {
            break;
        }

        int64_t lhs = psum_neg[r + 1] - psum_neg[l];
        int64_t rhs = psum_pos[r + 1] - psum_pos[l];
        ans = std::max(ans, sum + lhs);
        ans = std::max(ans, sum + rhs);

        while(l <= r && A[l] < 0) {
            l += 1;
        }
        while(l <= r && A[r] >= 0) {
            r -= 1;
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
