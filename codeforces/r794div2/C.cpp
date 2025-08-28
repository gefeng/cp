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

    std::ranges::sort(A);

    std::vector<int> ans(N, 0);
    int p = 0;
    for(int i = 0; i < N; i += 2) {
        ans[i] = A[p++];
    }

    for(int i = 1; i < N; i += 2) {
        ans[i] = A[p++];
    }

    for(int i = 0; i < N; i++) {
        int l = i == 0 ? ans.back() : ans[i - 1];
        int r = i == N - 1 ? ans[0] : ans[i + 1];
        if((ans[i] < l && ans[i] < r) || (ans[i] > l && ans[i] > r)) {
            continue;
        }
        std::cout << "No" << '\n';
        return;
    }
    
    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
