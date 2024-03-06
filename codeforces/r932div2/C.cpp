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
    int N, L;
    std::cin >> N >> L;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

    int ans = 0;
    for(int i = 0; i < N; i++) {
        std::priority_queue<int> pq;
        int64_t sum_a = A[i].first;
        if(sum_a <= L) {
            ans = std::max(1, ans);
        }

        for(int j = i + 1, k = i + 1; j < N; j++) {
            while(k < N && A[k].second <= A[j].second) {
                sum_a += A[k].first;
                pq.push(A[k].first);
                k += 1;
            } 

            while(sum_a + A[j].second - A[i].second > L && !pq.empty()) {
                sum_a -= pq.top();
                pq.pop();
            }

            if(pq.size() && sum_a + A[j].second - A[i].second <= L) {
                ans = std::max(ans, (int)pq.size() + 1);  
            }
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
