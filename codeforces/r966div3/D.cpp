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

    std::string S;
    std::cin >> S;
    
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    int64_t ans = 0;
    int l = 0;
    int r = N - 1;
    while(l < r) {
        while(l < r && S[l] == 'R') {
            l += 1;
        }
        while(l < r && S[r] == 'L') {
            r -= 1;
        }

        if(l < r) {
            ans += psum[r + 1] - psum[l];
            l += 1;
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
