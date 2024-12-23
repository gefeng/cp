#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    int64_t X, Y;
    std::cin >> N >> X >> Y;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t l = sum - A[i] - Y;
        int64_t r = sum - A[i] - X;
        
        auto it_l = std::lower_bound(A.begin() + i + 1, A.end(), l);
        auto it_r = std::upper_bound(A.begin() + i + 1, A.end(), r);
        ans += it_r - it_l;
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
