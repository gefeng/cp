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
    
    std::vector<std::pair<int64_t, int64_t>> q;
    int64_t removed = 0;
    int head = 0;
    int tail = -1;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int L;
            std::cin >> L;
            if(tail < head) {
                q.emplace_back(0, L);
                tail += 1;
            } else {
                q.emplace_back(q.back().first + q.back().second, L);
                tail += 1;
            }
        } else if(T == 2) {
            removed += q[head].second;
            head += 1;
            if(tail < head) {
                removed = 0;
            }
        } else {
            int K;
            std::cin >> K;
            
            std::cout << q[head + K - 1].first - removed << '\n';
        }
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
