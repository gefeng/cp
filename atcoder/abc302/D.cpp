#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    LL D;
    std::cin >> D;

    std::vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<LL> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    LL ans = -1LL;
    for(int i = 0; i < N; i++) {
        auto it = upper_bound(B.begin(), B.end(), A[i] + D); 
        
        if(it != B.begin()) {
            it--;

            if(abs(*it - A[i]) <= D) {
                ans = std::max(ans, *it + A[i]);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
