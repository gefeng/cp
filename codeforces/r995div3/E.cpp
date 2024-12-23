#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

    int64_t ans = 0;
    int64_t min_v = INF;
    std::priority_queue<int> pq;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].second == A[j].second) {
            pq.push(A[i].first);
            i += 1; 
        }
        
        while(pq.size() > K) {
            min_v = std::min(min_v, int64_t(pq.top()));
            pq.pop();
        }

        int64_t price = std::min(min_v, int64_t(A[j].second));
        if(i == N || price > A[i].second) {
            ans = std::max(ans, price * i);
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
