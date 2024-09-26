#include <iostream>
#include <utility> 
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(1e9);

void run_case() {
    int N, D, K;
    std::cin >> N >> D >> K;

    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());
    
    int ans_1 = -1;
    int ans_2 = -1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int max_v = 0;
    int min_v = INF;
    for(int i = 1, j = 0; i <= N - D + 1; i++) {
        while(j < K && A[j].first <= i + D - 1) {
            pq.push(A[j++].second);
        } 

        while(!pq.empty() && pq.top() < i) {
            pq.pop();
        }

        if(pq.size() > max_v) {
            max_v = pq.size();
            ans_1 = i;
        } 

        if(pq.size() < min_v) {
            min_v = pq.size();
            ans_2 = i;
        }
    }

    std::cout << ans_1 << ' ' << ans_2 << '\n';
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
