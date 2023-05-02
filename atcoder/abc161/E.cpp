#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, C;
    std::cin >> N >> K >> C;

    std::string S;
    std::cin >> S;

    std::vector<int> dp1(N + 1, 0LL);
    std::vector<int> dp2(N + 1, 0LL);
    
    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == 'x') {
            dp1[i] = dp1[i - 1]; 
        } else {
            dp1[i] = 1LL;
            if(i - C - 1 >= 0) {
                dp1[i] = std::max(dp1[i], dp1[i - C - 1] + 1);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(S[N - i] == 'x') {
            dp2[i] = dp2[i - 1];
        } else {
            dp2[i] = 1;
            if(i - C - 1 >= 0) {
                dp2[i] = std::max(dp2[i], dp2[i - C - 1] + 1);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(S[i] == 'x') {
            continue;
        }

        int sum = dp1[i + 1] + dp2[N - i] - 1;

        if(sum >= K && dp1[i] + dp2[N - i - 1] < K) {
            std::cout << i + 1 << '\n'; 
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
