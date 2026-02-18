#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    if(N == 2) {
        std::cout << A.back() << '\n';
        return;
    }

    int64_t ans = 0;
    for(int i = N - 1; i >= 0; i -= 2) {
        if(i) {
            int cost = std::max(A[i], A[i - 1]);
            ans += cost;
            A[i - 1] -= cost;
            A[i] -= cost;
        } else {
            ans += A[i]; 
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
