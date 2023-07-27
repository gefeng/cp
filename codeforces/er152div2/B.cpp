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

    auto cmp = [](const auto& a, const auto& b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;

        pq.emplace(X, i);
    }

    std::vector<int> ans;
    while(!pq.empty()) {
        auto [h, i] = pq.top();
        pq.pop();

        if(h <= K) {
            ans.push_back(i + 1);
        } else {
            if(h % K == 0) {
                pq.emplace(K, i);
            } else {
                pq.emplace(h % K, i);
            }
        }
    } 

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
