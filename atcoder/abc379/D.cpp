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
    
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
    int64_t t = 0;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            pq.emplace(t); 
        } else if(T == 2) {
            int64_t X;
            std::cin >> X;

            t += X;
        } else {
            int64_t H;
            std::cin >> H;

            int64_t res = 0;
            while(!pq.empty()) {
                if(t - pq.top() >= H) {
                    pq.pop();
                    res += 1;
                } else {
                    break;
                }
            }

            std::cout << res << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
