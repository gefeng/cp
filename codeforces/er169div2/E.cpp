#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(1e7);

std::vector<int> dp(MAX + 1, 0);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum ^= dp[A[i]];
    } 

    std::cout << (sum ? "Alice" : "Bob") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp[1] = 1;
    for(int i = 3, x = 2; i <= MAX; i += 2) {
        if(dp[i] == 0) {
            dp[i] = x++; 
            for(int j = i + i; j <= MAX; j += i) {
                if(j % 2 == 0) {
                    continue;
                }
                dp[j] = dp[j] == 0 ? dp[i] : dp[j];
            }
        }
    } 
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
