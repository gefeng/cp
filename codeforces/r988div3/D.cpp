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
    int N, M, L;
    std::cin >> N >> M >> L;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<std::pair<int, int>> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    int ans = 0;
    int64_t power = 1; 
    std::priority_queue<int> pq;
    for(int i = 0, j = 0; i < N; i++) {
        auto [l, r] = A[i];
        while(j < M && B[j].first < l) {
            pq.push(B[j].second);
            j += 1;
        }

        while(power < r - l + 2 && !pq.empty()) {
            power += pq.top();
            pq.pop();
            ans += 1;
        }

        if(power < r - l + 2) {
            std::cout << -1 << '\n';
            return;
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
