#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

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
    std::vector<int64_t> best_suffix(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        best_suffix[i] = std::max(best_suffix[i - 1], best_suffix[i - 1] + A[N - i].second - A[N - i].first); 
    }

    std::priority_queue<int> pq;
    int64_t sum_a = 0;
    for(int i = 0; i <= N; i++) {
        if(i) {
            sum_a += A[i - 1].first;
            pq.push(A[i - 1].first);
        }
        while(pq.size() > K) {
            sum_a -= pq.top();
            pq.pop();
        }

        if(pq.size() == K) {
            ans = std::max(ans, best_suffix[N - i] - sum_a);
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
