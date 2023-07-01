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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i].second;
    }

    auto cmp1 = [](const auto& a, const auto& b) {
        return a.first < b.first;
    };

    auto cmp2 = [](const auto& a, const auto& b) {
        if(a.second == b.second) {
            return a.first < b.first; 
        }
        return a.second < b.second;
    };

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), cmp1);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp2)> pq(cmp2);

    int64_t ans = 0;
    for(int i = 0, j = 0; i < N; i++) {
        while(j < M && B[j].first <= A[i]) {
            pq.emplace(B[j].first, B[j].second);
            j += 1;
        } 

        if(!pq.empty()) {
            std::pair<int, int> best = pq.top();
            pq.pop();
            ans += std::max(0, A[i] - best.second);
        } else {
            ans += A[i];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
