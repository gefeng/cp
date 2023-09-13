#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, K, A, B;
    std::cin >> N >> K >> A >> B;
    A -= 1;
    B -= 1;

    std::vector<std::pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        std::cin >> P[i].first >> P[i].second;
    }

    auto dist = [&](int i, int j) {
        return (int64_t)abs(P[i].first - P[j].first) + abs(P[i].second - P[j].second);
    };

    int64_t ans = dist(A, B);

    if(K > 0) {
        int64_t cost = 0;

        if(A >= K) {
            int64_t min_cost = INF;
            for(int i = 0; i < K; i++) {
                min_cost = std::min(min_cost, (int64_t)abs(P[A].first - P[i].first) + abs(P[A].second - P[i].second));
            } 

            cost += min_cost;
        }
        
        if(B >= K) {
            int64_t min_cost = INF;
            for(int i = 0; i < K; i++) {
                min_cost = std::min(min_cost, (int64_t)abs(P[B].first - P[i].first) + abs(P[B].second - P[i].second));
            } 

            cost += min_cost;
        }

        ans = std::min(ans, cost);
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
