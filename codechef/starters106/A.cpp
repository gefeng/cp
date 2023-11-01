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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(A[r] & 1) {
            cnt += 1;
        }

        if(r - l + 1 > K) {
            cnt -= A[l] & 1;
            l += 1;
        }

        if(r - l + 1 == K) {
            ans += cnt ? 1 : 0;
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
