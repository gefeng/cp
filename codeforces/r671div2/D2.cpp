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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    std::vector<int> ans(N, 0);
    int cnt = 0;
    int p = 0;
    for(int j = 1; j < N; p++, j += 2) {
        ans[j] = A[p];
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            ans[i] = A[p++];
        }
    }

    for(int i = 1; i < N - 1; i++) {
        if(ans[i] < ans[i + 1] && ans[i] < ans[i - 1]) {
            cnt += 1;
        }
    }

    std::cout << cnt << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
