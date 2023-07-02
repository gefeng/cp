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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = (int64_t)1e18;
    std::vector<int> a;
    for(int i = 2; i < N; i++) {
        a.push_back(A[i]);
    }

    std::sort(a.begin(), a.end());
    
    for(int l = 0, r = M - 1; r < N - 2; r++, l++) {
        int64_t x = A[0] <= a[l] ? 0 : A[0] - a[l];
        int64_t y = A[1] >= a[r] ? 0 : a[r] - A[1];
        
        ans = std::min(ans, x + y);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
