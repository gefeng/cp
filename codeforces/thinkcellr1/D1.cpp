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

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int> a(N - i, 0);
        int64_t cnt = 0;
        for(int j = i; j < N; ) {
            if(S[j] == '1') {
                cnt += 1;
                ans += cnt * std::min(3, N - j);
                j += 3;
            } else {
                ans += cnt;
                j += 1;
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
