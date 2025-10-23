#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::map<int, int> ma;
    std::map<int, int> mb;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ma[A[i]] += 1;
        ans += A[i];
    }
    
    for(int i = 0; i < M; i++) {
        mb[B[i]] += 1;
        ans += B[i];
    }

    for(auto [x, f1] : ma) {
        if(mb.find(x) == mb.end()) {
            continue;
        }
        int f2 = mb[x];
        if(f1 + f2 > N) {
            ans -= static_cast<int64_t>(x) * (f1 + f2 - N) * 2;
        }
    }

    // std::priority_queue<std::pair<int, int>> pq1;
    // std::priority_queue<std::pair<int, int>> pq2;
    //
    // for(auto [x, f] : ma) {
    //     pq1.emplace(f, x);
    // }
    //
    // for(auto [x, f] : mb) {
    //     pq2.emplace(f, x);
    // }
    //
    // while(!pq1.empty() && !pq2.empty()) {
    //     auto [f1, x] = pq1.top();
    //     auto [f2, y] = pq2.top();
    //     pq1.pop();
    //     pq2.pop();
    //
    //     if(x == y) {
    //         if(pq1.empty() && pq2.empty()) {
    //             break;
    //         }
    //         if(pq2.empty() || (!pq1.empty() && pq1.top().first > pq2.top().first)) {
    //             auto [f3, z] = pq1.top();
    //             pq1.pop();
    //             pq1.emplace(f1, x);
    //             f1 = f3;
    //             x = z;
    //         } else {
    //             auto [f3, z] = pq2.top();
    //             pq2.pop();
    //             pq2.emplace(f2, y);
    //             f2 = f3;
    //             y = z;
    //         }
    //     }
    //
    //     ans += x + y;
    //     if(--f1 > 0) {
    //         pq1.emplace(f1, x);
    //     } 
    //     if(--f2 > 0) {
    //         pq2.emplace(f2, y);
    //     }
    // }

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
