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
    int N, M, D;
    std::cin >> N >> M >> D;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int64_t sum = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > 0) {
            pq.emplace(A[i]);
            sum += A[i];
        }
        if(pq.size() > M) {
            int min_v = pq.top();
            pq.pop();

            sum -= min_v;
        }

        ans = std::max(ans, sum - (int64_t)D * (i + 1));
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
