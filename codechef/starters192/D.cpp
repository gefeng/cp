#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p_2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }

    int p = N - 1;
    int m = 1;
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] < A[i + 1]) {
            p = i;
            m += 1;
        } else {
            break;
        }
    }

    if(m == N) {
        std::cout << p_2[N] << '\n';
        return;
    }

    int64_t ans = 0;
    int64_t x = p_2[m];
    int64_t y = p_2[m - 1];
    std::set<int> s;
    for(int i = 0; i <= p - 2; i++) {
        ans += s.size() == A[p] - 1 ? y : x;
        ans %= MOD;
        if(A[i] < A[p]) {
            s.insert(A[i]); 
        } 
    }
    
    ans += p_2[m - 1];
    ans %= MOD;

    ans += p_2[N - p];
    ans %= MOD;

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
