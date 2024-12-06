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
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                if(a.first == b.first) {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });

    std::vector<int> ans;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int max_p = -1;

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i += 1;
        }

        int local_max = -1;
        for(int k = j; k < i; k++) {
            if(A[k].second < max_p) {
                ans.push_back(A[k].first + 1);
                pq.push(A[k].first + 1);
            } else {
                if(!pq.empty() && A[k].first > pq.top()) {
                    ans.push_back(A[k].first + 1);
                    pq.push(A[k].first + 1);
                } else {
                    ans.push_back(A[k].first);
                    local_max = std::max(local_max, A[k].second);
                }
            }
        }

        max_p = std::max(max_p, local_max);
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
