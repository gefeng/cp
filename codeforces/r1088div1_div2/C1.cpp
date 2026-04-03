#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int, int>> range(N + 1, {-1, -1});
    std::vector<int> order(N + 1, 0);
    std::iota(order.begin(), order.end(), 0);
    for(int i = 0; i < N; i++) {
        int l1 = std::max(0, i - K + 1);
        int r1 = std::min(N - 1, l1 + K - 1);
        int r2 = std::min(N - 1, i + K - 1);
        int l2 = std::max(0, r2 - K + 1);
        range[A[i]] = {l2, r1};
    }

    std::ranges::sort(order, [&](int i, int j) {
                if(range[i].first == range[j].first) {
                    return range[i].second < range[j].second;
                }
                return range[i].first < range[j].first;
            });

    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        if(B[i] != -1) {
            if(seen[B[i]]) {
                std::cout << "NO" << '\n';
                return;
            }
            seen[B[i]] = 1;
            auto [l, r] = range[B[i]];
            if(i < l || i > r) {
                std::cout << "NO" << '\n';
                return;
            }
        }
    }

    for(int i = 1, j = 0; i <= N; i++) {
        while(j < N && B[j] != -1) {
            j++;
        }
        int x = order[i];
        if(seen[x]) {
            continue;
        }
        if(j == N || j < range[x].first || j > range[x].second) {
            std::cout << "NO" << '\n';
            return;
        }
        B[j] = x;
    }

    for(int i = 0; i < N; i++) {
        if(B[i] == -1) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
