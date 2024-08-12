#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int> X(N);
    std::vector<int> Y(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    auto solve = [&](std::vector<int>& pos) {
        int64_t sum = 0;
        int64_t l = 0;
        int64_t r = 0;
        std::vector<int64_t> psum(N + 1, 0);
        for(int i = 1; i <= N; i++) {
            psum[i] = psum[i - 1] + pos[i - 1];
        }
        
        sum = psum[N];
        l = sum - D < 0 ? (sum - D) / N : (sum - D + N - 1) / N;
        r = sum + D < 0 ? -(std::abs(sum + D) + N - 1) / N : (sum + D) / N;
    
        std::vector<int> a;
        for(int x = l; x <= r; x++) {
            auto it = std::upper_bound(pos.begin(), pos.end(), x);
            
            int cnt_l = it - pos.begin();
            int cnt_r = pos.end() - it;
            
            a.push_back(int64_t(cnt_l) * x - psum[cnt_l] + psum[N] - psum[it - pos.begin()] - int64_t(cnt_r) * x);
        }  
        std::sort(a.begin(), a.end());
        return a;
    };

    std::vector<int> a = solve(X);
    std::vector<int> b = solve(Y);
    
    int64_t ans = 0;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        auto it = std::upper_bound(b.begin(), b.end(), D - a[i]);
        ans += it - b.begin();
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
