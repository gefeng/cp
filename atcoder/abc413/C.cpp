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
    int Q;
    std::cin >> Q;

    std::deque<std::pair<int64_t, int64_t>> deq;
    
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int64_t C, X;
            std::cin >> C >> X;
            deq.emplace_back(X, C);
        } else {
            int64_t K;
            std::cin >> K; 

            int64_t sum = 0;
            while(!deq.empty()) {
                auto [x, c] = deq.front();
                deq.pop_front();
                if(c <= K) {
                    K -= c;
                    sum += x * c;
                } else {
                    c -= K;
                    sum += x * K;
                    K = 0;
                    deq.emplace_front(x, c);
                    break;
                }
            }

            std::cout << sum << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
