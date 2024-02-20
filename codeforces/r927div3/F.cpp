#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    std::map<int, int> m;
    std::vector<int> dp(N + 1, 0);
    for(int i = 1, j = 0; i <= N; i++) {
        while(j < M && A[j].first <= i) {
            pq.emplace(A[j].first, A[j].second); 
            m[A[j].first] += 1;
            j += 1;
        } 

        while(!pq.empty() && pq.top().second < i) {
            int l = pq.top().first;
            if(--m[l] == 0) {
                m.erase(l);
            }
            pq.pop();
        }

        dp[i] = dp[i - 1];
        
        if(!m.empty()) {
            int pre = m.begin()->first - 1;
            dp[i] = std::max(dp[i], dp[pre] + (int)pq.size());
        } 
    }

    std::cout << dp[N] << '\n';
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
