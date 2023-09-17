#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == K) {
        std::sort(A.begin(), A.end());
        for(int i = 0; i < N; i++) {
            std::cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }

    int len = 1;
    int max_len = 1;
    for(int i = 1; i < N; i++) {
        if(A[i] > A[i - 1]) {
            len += 1;
        } else {
            len = 1;
        }

        max_len = std::max(max_len, len);
    }

    if(max_len >= K) {
        for(int i = 0; i < N; i++) {
            std::cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }

    std::vector<int> save_min(N, (int)1e9);
    for(int i = N - K; i < N; i++) {
        save_min[i] = std::min(save_min[i - 1], A[i]);
    }

    int p = N - K;
    for(int i = N - K - 1; i >= 0; i--) {
        if(A[i] < A[i + 1] && save_min[i + K - 1] > A[N - K - 1]) {
            p = i;
        }

        if(A[i] > A[i + 1]) {
            break;
        }
    }

    std::vector<int> ans(A);
    std::sort(ans.begin() + p, ans.begin() + p + K);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
