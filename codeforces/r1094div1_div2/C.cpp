#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    std::ranges::sort(a);
    
    int med = a[N / 2];
    
    std::vector<int> b(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] > med) {
            b[i] = 1;
        } else if(A[i] < med) {
            b[i] = -1;
        }
    }
    
    std::vector<int> dp(N + 1, -1);
    dp[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        int c_med = 0;
        for(int j = i; j > 0; j--) {
            sum += b[j - 1];
            if(b[j - 1] == 0) {
                c_med++;
            }
            
            if(std::abs(sum) <= c_med && (i - j + 1) % 2 == 1 && dp[j - 1] != -1) {
                dp[i] = std::max(dp[i], dp[j - 1] + 1);
            }
        }
    }

    std::cout << dp[N] << '\n';
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
