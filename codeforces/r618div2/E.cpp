#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    std::vector<std::pair<int64_t, int>> stk;
    std::vector<double> ans(N, 0.0);
    for(int i = 0; i < N; i++) {
        int64_t sum = A[i];
        int cnt = 1;
        while(!stk.empty() && (sum + stk.back().first) * stk.back().second <= stk.back().first * (stk.back().second + cnt)) {
            sum += stk.back().first;
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(sum, cnt);
    }

    int n = stk.size();
    for(int i = 0, j = 0; i < n; i++) {
        auto [sum, len] = stk[i];
        double average = double(sum) / len;
        for(int k = 0; k < len; k++) {
            ans[j + k] = average;
        }
        j += len;
    }

    std::cout << std::setprecision(20);
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
