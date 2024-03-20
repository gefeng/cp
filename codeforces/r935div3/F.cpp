#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
        A[i].second -= 1;
    }

    std::set<std::pair<int, int>> kmax;
    std::set<std::pair<int, int>> have;
    for(int i = 0; i < N; i++) {
        have.insert(A[i]);
    }

    int64_t max_p = 0;
    int min_cnt = N + 1;
    for(int k = 1; k <= N; k++) {
        if(k >= 2) {
            std::pair<int, int> cur = A[A[k - 2].second];

            if(kmax.find(cur) != kmax.end()) {
                kmax.erase(cur);
            }

            if(have.find(cur) != have.end()) {
                have.erase(cur);
            }
        }

        while(kmax.size() < k && !have.empty()) {
            auto [x, y] = *have.rbegin();
            kmax.insert({x, y}); 
            have.erase({x, y});
        }

        if(kmax.size() == k) {
            int64_t p = (int64_t)kmax.begin()->first * k;
            if(p > max_p) {
                max_p = p;
                min_cnt = k;
            }
        }
    }

    std::cout << max_p << ' ' << min_cnt << '\n';
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
