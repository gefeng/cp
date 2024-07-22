#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int64_t l = 0;
    int64_t r = 0;
    for(int i = 0; i < N; i++) {
        l += A[i].first;
        r += A[i].second;
    }

    if(0 >= l && 0 <= r) {
        std::cout << "Yes" << '\n';
        
        std::vector<int> ans(N);
        for(int i = 0; i < N; i++) {
            ans[i] = A[i].second;
        }

        for(int i = 0; i < N; i++) {
            int64_t d = std::min(int64_t(A[i].second - A[i].first), r);
            ans[i] -= d;
            r -= d;
            std::cout << ans[i] << " \n"[i == N - 1];
        } 
    } else {
        std::cout << "No" << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
