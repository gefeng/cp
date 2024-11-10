#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int64_t>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first;
        A[i].first -= 1;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> A[i].second;
    }

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    if(A[0].first != 0) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < M; i++) {
        int nxt = i == M - 1 ? N : A[i + 1].first;
        int64_t need = nxt - A[i].first - 1;
        
        if(A[i].second - 1 < need) {
            std::cout << -1 << '\n';
            return;
        }
        
        int64_t x = A[i].second - 1;
        int64_t len = nxt - A[i].first;
        
        ans += (x + x - len + 1) * len / 2;
        
        if(i == M - 1) {
            if(A[i].first == N - 1) {
                if(A[i].second != 1) {
                    std::cout << -1 << '\n';
                    return;
                }
            } else {
                if(x - len + 1 != 0) {
                    std::cout << -1 << '\n';
                    return;
                } 
            }
        } else {
            A[i + 1].second += x - len + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
