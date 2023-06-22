#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto cmp = [](const auto& a, const auto& b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };

    std::sort(A.begin(), A.end(), cmp);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    LL ans = 0LL;
    int cnt_on = 0;
    for(int i = 0; i < N; ) {
        if(cnt_on < A[i].first) {
            ans += A[i].second;
            cnt_on += 1;
            pq.emplace(A[i].first, 1);
            i += 1;
        }

        while(i < N && A[i].first <= cnt_on) {
            pq.emplace(A[i].first, 0);
            i += 1;
        }

        while(!pq.empty() && pq.top().first <= cnt_on) {
            if(pq.top().second) {
                cnt_on -= 1;
            }
            pq.pop();
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
