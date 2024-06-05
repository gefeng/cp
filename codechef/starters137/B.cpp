#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> P(N);
    std::vector<int> H(N);
    for(int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + H[i - 1];
    }

    std::vector<int64_t> suffix_max(N + 1, -INF); 
    suffix_max[0] = 0;
    
    for(int i = N - 1; i >= 0; i--) {
        suffix_max[N - i] = std::max(suffix_max[N - i - 1], psum[i + 1] - P[i]);
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        auto it = std::upper_bound(P.begin(), P.end(), (int64_t)P[i] + K * 2);
        int j = std::prev(it) - P.begin();
        
        if(suffix_max[N - 1 - j] <= psum[j + 1] - psum[i]) {
            std::cout << "Yes" << '\n';
            return;
        }
        
        sum += H[i];
        if(P[i] < sum) {
            break;
        }
    }

    std::cout << "No" << '\n';
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
