#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    } 

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    LL ans = 1LL;
    for(int i = N - 1, j = N - 1; j >= 0; ) {
        while(i >= 0 && A[i] > B[j]) {
            i -= 1;
        }

        LL have = N - i - 1;
        LL used = N - j - 1;

        if(have - used <= 0) {
            ans = 0LL;
            break;
        }
        
        ans *= (have - used + MOD) % MOD;
        ans %= MOD;

        j -= 1;
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
