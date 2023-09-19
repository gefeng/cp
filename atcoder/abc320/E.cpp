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

    std::vector<std::vector<int>> A(M, std::vector<int>(3, 0));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.first > b.first;
    };

    std::priority_queue<int, std::vector<int>, std::greater<int>> work; 
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, decltype(cmp)> wait(cmp);
    std::vector<int64_t> ans(N, 0);

    for(int i = 0; i < N; i++) {
        work.push(i);
    }

    for(auto& e : A) {
        while(!wait.empty() && wait.top().first <= e[0]) {
            work.push(wait.top().second);
            wait.pop();
        }     

        if(!work.empty()) {
            int p = work.top();
            work.pop();
            
            ans[p] += e[1];
            wait.emplace((int64_t)e[0] + e[2], p);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
