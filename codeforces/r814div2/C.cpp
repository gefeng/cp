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
    int N, Q;
    std::cin >> N >> Q;

    std::deque<std::pair<int, int>> deq;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        deq.emplace_back(A[i], i);
    }

    std::vector<std::tuple<int, int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        auto& [x, y, z] = B[i];
        std::cin >> x >> y;
        x -= 1;
        z = i;
    }
    
    std::ranges::sort(B, [](const auto& x, const auto& y) {
                return std::get<1>(x) < std::get<1>(y);
            });

    std::vector<int> wins(N + 1, 0);
    std::vector<int> ans(Q, 0);
    int t = 0;
    for(int i = 0; i < Q; i++) {
        auto [p, k, idx] = B[i];
        while(deq.front().first != N && t < k) {
            auto [x, a] = deq.front();
            deq.pop_front();
            auto [y, b] = deq.front();
            deq.pop_front();
            
            if(x > y) {
                wins[a] += 1;
                deq.emplace_front(x, a);
                deq.emplace_back(y, b);
            } else {
                wins[b] += 1;
                deq.emplace_front(y, b);
                deq.emplace_back(x, a);
            }
            t += 1;
        }
        if(deq.front().first == N) {
            ans[idx] = A[p] == N ? wins[p] + k - t : wins[p];
        } else {
            ans[idx] = wins[p];
        }
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << '\n';
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
