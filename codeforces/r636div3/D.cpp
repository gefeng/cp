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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> a;
    std::vector<int> cnt(K * 2 + 1, 0);
    for(int i = 0; i < (N >> 1); i++) {
        a.emplace_back(A[i], A[N - 1 - i]);
        if(A[i] > A[N - 1 - i]) {
            std::swap(a[i].first, a[i].second);
        }
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                return x.first + x.second < y.first + y.second; 
            });


    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_1;
    std::priority_queue<int> pq_2;
    for(int s = 2, i = 0; s <= (K << 1); s++) {
        while(i < (N >> 1) && a[i].first + a[i].second < s) {
            pq_1.push(a[i++].second); 
        }
        while(!pq_1.empty() && pq_1.top() + K < s) {
            pq_1.pop();
        }
        cnt[s] += pq_1.size() + ((i - pq_1.size()) << 1);
        while(i < (N >> 1) && a[i].first + a[i].second == s) {
            pq_1.push(a[i++].second);
        }
    }
    
    for(int s = (K << 1), i = (N >> 1) - 1; s >= 2; s--) {
        while(i >= 0 && a[i].first + a[i].second > s) {
            pq_2.push(a[i--].first);
        }
        while(!pq_2.empty() && pq_2.top() + 1 > s) {
            pq_2.pop();
        }
        cnt[s] += pq_2.size() + (((N >> 1) - 1 - i - pq_2.size()) << 1);
        while(i >= 0 && a[i].first + a[i].second == s) {
            pq_2.push(a[i--].first);
        }
    }

    int ans = N;
    for(int i = 2; i <= (K << 1); i++) {
        ans = std::min(ans, cnt[i]);
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
