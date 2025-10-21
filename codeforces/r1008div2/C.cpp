#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N << 1);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<int64_t> ans(N * 2 + 1);
    int64_t sum = 0;
    for(int i = N - 1, j = 0; i < N * 2; i++, j += 2) {
        ans[j] = A[i];
        sum += A[i];
    }

    for(int i = 0, j = 1; i < N - 1; i++, j += 2) {
        ans[j] = A[i];
        sum -= A[i];
    }

    ans[N * 2 - 1] = sum;

    for(int i = 0; i < N * 2 + 1; i++) {
        std::cout << ans[i] << " \n"[i == N * 2];
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
