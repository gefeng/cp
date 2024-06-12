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
    int H, N;
    std::cin >> H >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
    for(int i = 0; i < N; i++) {
        pq.emplace(0, i);
    }

    int64_t t = 0;
    while(H) {
        if(pq.top().first > t) {
            t = pq.top().first;
        }

        while(pq.top().first <= t && H) {
            auto [_, i] = pq.top();
            pq.pop();
            H = std::max(0, H - A[i]);
            pq.emplace(t + B[i], i); 
        } 
    }

    std::cout << t + 1 << '\n';
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
