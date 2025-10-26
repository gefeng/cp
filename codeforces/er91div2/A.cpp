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

    int min_v = A.back();
    int min_p = N - 1;
    std::vector<int> dp(N, -1);
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] > min_v) {
            dp[i] = min_p;
        } else {
            min_v = A[i];
            min_p = i;
        }
    }

    min_v = A[0];
    min_p = 0;
    for(int i = 1; i < N - 1; i++) {
        if(A[i] > min_v && dp[i] != -1) {
            std::cout << "YES" << '\n';
            std::cout << min_p + 1 << ' ' << i + 1 << ' ' << dp[i] + 1 << '\n';
            return;
        }
        min_v = A[i];
        min_p = i;
    }

    std::cout << "NO" << '\n';
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
