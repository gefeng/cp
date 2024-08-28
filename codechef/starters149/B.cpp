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

    std::string S;
    std::cin >> S;

    int64_t sum = 0;
    int64_t ans = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] != S[i - 1]) {
            sum += 1;
        }
    }

    if(sum == 0) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t cnt = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        cnt += i - j - 1;
    }

    ans = cnt * sum + (sum - 1) * sum / 2;

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
