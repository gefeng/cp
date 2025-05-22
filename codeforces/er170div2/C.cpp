#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());
    
    auto solve = [&](int l, int r) {
        std::vector<int> freq;  
        for(int i = l; i <= r; ) {
            int j = i;
            while(i <= r && A[i] == A[j]) {
                i += 1;
            }
            freq.push_back(i - j);
        }

        int n = freq.size();
        std::vector<int> psum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + freq[i];
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            int j = std::min(n, i + K); 
            res = std::max(res, psum[j] - psum[i]);
        }
        return res;
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && A[i + 1] - A[i] <= 1) {
            i += 1;
        }
        ans = std::max(ans, solve(j, i));
    }

    std::cout << ans << '\n';
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
