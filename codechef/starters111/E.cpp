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

    std::vector<int> A(N - 1);
    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
        seen[A[i]] = 1;
    }

    int cur = 0;
    for(int i = 1; i <= N; i++) {
        if(!seen[i]) {
            cur = i;
            break;
        }
    }

    int64_t ans = 0;
    for(int i = N - 2; i >= 0; i--) {
        ans += std::max(std::min(A[i], cur), i + 2); 
        cur = std::max(cur, A[i]);
    }

    ans += std::max(cur, 1);
    
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
