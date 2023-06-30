#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)1e18;

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<LL> A(N, INF);
    for(int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;
        A[P] = X;
    }

    std::vector<std::tuple<int, int, LL>> B(K);
    for(int i = 0; i < K; i++) {
        int P1, P2, D;
        std::cin >> P1 >> P2 >> D;
        P1 -= 1;
        P2 -= 1;
        if(P1 > P2) {
            std::swap(P1, P2);
        }

        B[i] = {P1, P2, D};
    }

    std::vector<std::pair<LL, LL>> range(N, {-INF, INF});
    for(auto [i, j, d] : B) {
        if(A[i] == INF && A[j] == INF) {
            continue; 
        }

        if(A[i] != INF && A[j] != INF) {
            LL x = abs(1LL * A[i] - A[j]); 
            if(x > d) {
                std::cout << "NO" << '\n';
                return;
            }
        } else if(A[i] == INF) {
            LL l = 1LL * A[j] - d;
            LL r = 1LL * A[j] + d;

            if(r < range[i].first || l > range[i].second) {
                std::cout << "NO" << '\n';
                return;
            }

            range[i].first = std::max(range[i].first, l); 
            range[i].second = std::min(range[i].second, r);
        } else if(A[j] == INF) {
            LL l = 1LL * A[i] - d;
            LL r = 1LL * A[i] + d;

            if(r < range[j].first || l > range[j].second) {
                std::cout << "NO" << '\n';
                return;
            }

            range[j].first = std::max(range[j].first, l); 
            range[j].second = std::min(range[j].second, r);
        }
    }

    for(auto [i, j, d] : B) {
        if(A[i] == INF && A[j] == INF) {
            if(range[i].first == -INF || range[j].first == -INF) {
                continue;
            }

            if(range[i].first <= range[j].first && range[j].first <= range[i].second) {
                continue;
            }

            if(range[j].first <= range[i].first && range[i].first <= range[j].second) {
                continue;
            }
            
            LL min_d = 0LL;
            if(range[i].first < range[j].first) {
                min_d = range[j].first - range[i].second;
            } else {
                min_d = range[i].first - range[j].second;
            }

            if(min_d > d) {
                std::cout << "NO" << '\n';
                return;
            }
        }
    }

    std::cout << "YES" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
