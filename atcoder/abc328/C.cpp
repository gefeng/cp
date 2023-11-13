#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    std::vector<int> psum(N + 1, 0);
    for(int i = 1; i < N; i++) {
        psum[i + 1] = psum[i] + (S[i] == S[i - 1] ? 1 : 0);
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;

        L -= 1;
        R -= 1;
        
        int res = psum[R + 1] - psum[L];
        if(L && S[L] == S[L - 1]) {
            res -= 1;
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
