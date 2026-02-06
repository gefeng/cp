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
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> a;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            a.emplace_back(A[i - 1] - A[i], i);
        }
    }

    std::ranges::sort(a);

    std::vector<int> ans(N, 0);
    for(int i = 1, j = 0; i <= N; i++) {
        if(j < a.size() && a[j].first <= i) {
            ans[i - 1] = a[j].second;
            j += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
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
