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

    std::string A, B, C;
    std::cin >> A >> B >> C;

    std::array<int, 4> freq = {};
    for(int i = 0; i < N; i++) {
        if(B[i] != C[i]) {
            int mask = (B[i] - '0') | ((A[i] - '0') << 1);
            freq[mask] += 1;
        }
    }

    int64_t ans = 0;
    int d = std::min(freq[0], freq[1]);
    freq[0] -= d;
    freq[1] -= d;

    d = std::min(freq[2], freq[3]);
    freq[2] -= d;
    freq[3] -= d;

    if(freq[0] && freq[3]) {
        d = std::min(freq[0], freq[3]);
        freq[0] -= d;
        freq[3] -= d;
        ans += d;
    }
    if(freq[1] && freq[2]) {
        d = std::min(freq[1], freq[2]);
        freq[1] -= d;
        freq[2] -= d;
        ans += d;
    }

    for(int i = 0; i < 4; i++) {
        ans += freq[i];
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
