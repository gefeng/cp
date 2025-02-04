#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    std::vector<int64_t> C(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    auto cmp = [&](const auto& x, const auto& y) {
        auto [i, j, k] = x;
        auto [a, b, c] = y;
        int64_t v_1 = A[i] * B[j] + B[j] * C[k] + C[k] * A[i];
        int64_t v_2 = A[a] * B[b] + B[b] * C[c] + C[c] * A[a];

        return v_1 < v_2;
    };

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(cmp)> pq(cmp);
    std::set<std::tuple<int, int, int>> seen;
    pq.emplace(N - 1, N - 1, N - 1);
    seen.emplace(N - 1, N - 1, N - 1);

    std::tuple<int, int, int> now;

    while(K) {
        now = pq.top();
        pq.pop();
        auto [i, j, k] = now;
        K -= 1;

        if(i && seen.find({i - 1, j, k}) == seen.end()) {
            pq.emplace(i - 1, j, k);
            seen.emplace(i - 1, j, k);
        }

        if(j && seen.find({i, j - 1, k}) == seen.end()) {
            pq.emplace(i, j - 1, k); 
            seen.emplace(i, j - 1, k);
        }

        if(k && seen.find({i, j, k - 1}) == seen.end()) {
            pq.emplace(i, j, k - 1);
            seen.emplace(i, j, k - 1);
        }
    }

    auto [i, j, k] = now;
    std::cout << A[i] * B[j] + B[j] * C[k] + C[k] * A[i] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
