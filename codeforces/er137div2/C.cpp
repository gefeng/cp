#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int pre = -1;
    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        int min_v = INF;
        while(i < N && S[i] == S[j]) {
            if(S[j] == '1') {
                ans += A[i];
            }
            min_v = std::min(min_v, A[i]);
            i += 1;
        }

        if(S[j] == '1') {
            ans += std::max(0, pre - min_v);
            pre = -1;
        } else {
            pre = A[i - 1];
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
