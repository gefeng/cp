#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::unordered_map<int64_t, int>> m(10);
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        for(int64_t d = 10, j = 0; d <= static_cast<int64_t>(1e10); d *= 10, j++) {
            int64_t r = (d % M) * (A[i] % M) % M;
            m[j][r] += 1;
        }

        int t = (M - (A[i] % M)) % M;
        int c = 0;
        int x = A[i];
        while(x) {
            x /= 10;
            c += 1;
        }
        ans += m[c - 1][t]; 
    }    

    m = std::vector<std::unordered_map<int64_t, int>>(10);
    
    for(int i = N - 1; i >= 0; i--) {
        int t = (M - (A[i] % M)) % M;
        int c = 0;
        int x = A[i];
        while(x) {
            x /= 10;
            c += 1;
        }
        ans += m[c - 1][t]; 
        for(int64_t d = 10, j = 0; d <= static_cast<int64_t>(1e10); d *= 10, j++) {
            int64_t r = (d % M) * (A[i] % M) % M;
            m[j][r] += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
