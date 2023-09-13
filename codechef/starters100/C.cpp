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

    std::sort(A.begin(), A.end(), std::greater<int>());
    
    std::vector<int> ans(N);
    for(int i = 0, j = 1; i < N / 2; i++, j += 2) {
        ans[j] = A[i];
    }

    for(int i = N / 2, j = 0; i < N; i++, j += 2) {
        ans[j] = A[i];
    }

    for(int i = 1; i < N - 1; i++) {
        if((ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) || (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])) {
            continue;
        }

        std::cout << -1 << '\n';
        return;
    }
    
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
