#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = int(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int sum = std::accumulate(A.begin(), A.end(), 0);
    int ans = INF;
    for(int i = 0; i < (1 << N); i++) {
        int x = 0;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                x += A[j];
            }
        }

        ans = std::min(ans, std::max(x, sum - x));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
