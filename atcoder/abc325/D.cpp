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
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());

    int64_t cur_t = 0;
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
    int ans = 0;
    for(int i = 0; i < N; ) {
        if(pq.empty() && A[i].first > cur_t) {
            cur_t = A[i].first;
        }
        while(i < N && A[i].first <= cur_t) {
            pq.push(A[i].second + A[i].first); 
            i += 1;
        }

        if(i < N) {
            while(cur_t < A[i].first && !pq.empty()) {
                int64_t t = pq.top();
                pq.pop();
                if(t >= cur_t) {
                    ans += 1;
                    cur_t += 1;
                }
            }
        } else {
            while(!pq.empty()) {
                int64_t t = pq.top();
                pq.pop();
                if(t >= cur_t) {
                    ans += 1;
                    cur_t += 1;
                }
            } 
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
