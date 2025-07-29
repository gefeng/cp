#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.second < y.second;
            });
    
    std::vector<std::pair<int, int>> a;
    a.emplace_back(0, 2);
    for(int i = 0; i < M; i++) {
        if(i + 1 < M && A[i].second == A[i + 1].second) {
            a.emplace_back(A[i].second, 2);
            i += 1;
        } else {
            a.emplace_back(A[i].second, A[i].first - 1);
        }
    }
    a.emplace_back(N + 1, 2);

    int n = a.size();
    for(int i = 1; i < n; i++) {
        auto [c1, s1] = a[i - 1]; 
        auto [c2, s2] = a[i];
        
        if((s1 == 2 && s2 == 2) || (s1 == 2 && s2 == 0) || (s1 == 2 && s2 == 1)) {
            continue;
        }
        
        if((s1 == 0 && s2 == 2) || (s1 == 1 && s2 == 2)) {
            std::cout << "NO" << '\n';
            return;
        }

        if((s1 == 0 && s2 == 0) || (s1 == 1 && s2 == 1)) {
            if((c2 - c1) % 2 == 0) {
                std::cout << "NO" << '\n';
                return;
            }
            a[i].second = 2;
        }

        if((s1 == 0 && s2 == 1) || (s1 == 1 && s2 == 0)) {
            if((c2 - c1) % 2 == 1) {
                std::cout << "NO" << '\n';
                return;
            }
            a[i].second = 2;
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
