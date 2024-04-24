#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + int64_t(7);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int64_t ans = 0;
    int64_t cnt_one = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            cnt_one += 1;
        } else {
            break;
        }
    }

    ans = cnt_one;
    for(int i = cnt_one; i < N; i++) {
        if(ans <= 1) {
            ans += A[i];
        } else {
            ans *= A[i];
        }
        ans %= MOD;
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
