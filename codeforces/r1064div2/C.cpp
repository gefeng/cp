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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        a.push_back(std::max(A[i], A[(i + 1) % N]));
    }

    std::ranges::sort(a);
    
    int64_t ans = std::accumulate(a.begin(), a.end() - 1, static_cast<int64_t>(0));

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
