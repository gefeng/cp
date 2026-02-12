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
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int l = 0;
    int r = N - 1;
    int64_t ans = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    while(l < r) {
        if(B[l] <= B[r]) {
            ans += B[l++];
        } else {
            ans += B[r--];
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
