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
    int64_t C;
    std::cin >> N >> C;

    std::vector<std::pair<int64_t, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }
    
    auto cmp = [&](auto& a, auto& b) {
        return C * (a.second + 1) - a.first < C * (b.second + 1) - b.first;
    };

    std::sort(A.begin() + 1, A.end(), cmp);

    int64_t sum = A[0].first;
    for(int i = 1; i < N; i++) {
        if(sum + A[i].first < (A[i].second + 1) * C) {
            std::cout << "No" << '\n';
            return;
        }
        sum += A[i].first;
    }

    std::cout << "Yes" << '\n';
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
