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

    std::vector<int> a(A);
    std::vector<int64_t> psum(N + 1, 0);
    std::sort(a.begin(), a.end());
    
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + a[i - 1];
    }

    std::vector<int64_t> ans(N);
    for(int i = 0; i < N; i++) {
        auto it = upper_bound(a.begin(), a.end(), A[i]);
        
        int64_t l = it - a.begin();
        int64_t r = a.end() - it;

        ans[i] = l * A[i] - psum[l] + psum[N] - psum[N - r] - r * A[i] + N;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
