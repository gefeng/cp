#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    //ai - bi > -(aj - bj)
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }
    
    std::sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
                return x.first - x.second < y.first - y.second;
            });

    int p = -1;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        auto [x, y] = A[i];
        if(x - y <= 0) {
            continue;
        }

        if(p == -1) {
            p = i;
        } 
        while(p - 1 >= 0 && (A[p - 1].second - A[p - 1].first) < x - y) {
            p -= 1;
        }

        ans += i - p;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
