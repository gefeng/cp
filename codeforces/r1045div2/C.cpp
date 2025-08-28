#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i += 2) {
        if(i % 2 == 0) {
            int l = i == 0 ? INF : A[i - 1];
            int r = i == N - 1 ? INF : A[i + 1];
            int v = std::min(l, r);
            if(A[i] > v) {
                ans += A[i] - v;
                A[i] = v;
            }
        }
    }

    for(int i = 1; i < N; i += 2) {
        if(i != N - 1) {
            int sum = A[i - 1] + A[i + 1];
            if(A[i] < sum) {
                int d = sum - A[i];
                ans += d;
                A[i + 1] -= d;
            }
        }
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
