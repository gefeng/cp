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
    int N, M;
    int64_t K;
    std::cin >> N >> M >> K;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::vector<std::tuple<int, int, int>> B(N);
    for(int i = 0; i < N; i++) {
        auto& [x, y, z] = B[i];
        std::cin >> x >> y >> z;
        K -= y;
    }

    std::ranges::sort(A);
    std::ranges::sort(B);
    
    auto cmp = [](auto& x, auto& y) {
        return std::get<2>(x) - std::get<1>(x) < std::get<2>(y) - std::get<1>(y);
    };
    
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(cmp)> pq(cmp);
    int ans = 0;
    int j = 0;
    for(int i = 0; i < M; i++) {
        while(j < N && std::get<0>(B[j]) <= A[i]) {
            pq.push(B[j++]);
        }

        if(!pq.empty()) {
            pq.pop();
            ans += 1;
        }
    }

    while(j < N) {
        pq.push(B[j++]);
    }

    std::vector<std::tuple<int, int, int>> a;
    while(!pq.empty()) {
        a.push_back(pq.top());
        pq.pop();
    }

    for(int i = a.size() - 1; i >= 0; i--) {
        auto [x, y, z] = a[i];
        if(K >= z - y) {
            ans += 1;
            K -= z - y;
        }
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
