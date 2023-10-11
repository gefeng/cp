#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int64_t ans = 0;
    int cnt = 0;
    std::vector<int> flip(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        if((S[i - 1] - '0') % 2 == 0) {
            continue;
        }
        cnt += 1;
        flip[i] = 1;
        for(int j = i; j <= N; j += i) {
            S[j - 1] = S[j - 1] == '0' ? '1' : '0';    
        } 
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        if(flip[X]) {
            cnt -= 1;
        } else {
            cnt += 1;
        }

        flip[X] ^= 1;
        ans += cnt;
    }

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
