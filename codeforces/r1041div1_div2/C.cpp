#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>
#include <queue>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
        if(A[i].first > A[i].second) {
            std::swap(A[i].first, A[i].second);
        }
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i].second - A[i].first;
    }

    std::ranges::sort(A);
    
    bool overlap = false;
    for(int i = 1; i < N; i++) {
        if(A[i - 1].second < A[i].first) {
            continue;
        }
        
        overlap = true;
        break;
    }
    
    if(overlap) {
        std::cout << sum << '\n';
        return;
    }

    int64_t ans = INF;
    for(int i = 1; i < N; i++) {
        ans = std::min(ans, sum + (A[i].first - A[i - 1].second) * 2);
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
