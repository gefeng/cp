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
    std::cin >> N;;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int>> college(N);
    for(int i = 0; i < N; i++) {
        college[A[i]].push_back(B[i]);
    }
    
    std::vector<int64_t> ans(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::sort(college[i].begin(), college[i].end(), std::greater<int>());
         
        int n = college[i].size();
        std::vector<int64_t> psum(n + 1, 0);
        for(int j = 0; j < n; j++) {
            psum[j + 1] = psum[j] + college[i][j];
        }

        for(int k = 1; k <= n; k++) {
            int r = n % k;
            ans[k] += psum[n - r];
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
