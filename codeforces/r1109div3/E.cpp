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
    
    std::vector<int> a(N, 0);
    std::vector<int> b(N, 0);
    
    for(int i = 0, j = 0, k = 1; i < N; i++, j ^= 1, k ^= 1) {
        a[i] = S[i] - '0' == j ? 0 : 1;
        b[i] = S[i] - '0' == k ? 0 : 1;
    }

    std::vector<int> psum_a(N + 1, 0);
    std::vector<int> psum_b(N + 1, 0);
    
    for(int i = 0; i < N; i++) {
        if((i && a[i] == 1 && a[i - 1] == 0) || (i == 0 && a[i] == 1)) {
            psum_a[i + 1] = psum_a[i] + 1;
        } else {
            psum_a[i + 1] = psum_a[i];
        }

        if((i && b[i] == 1 && b[i - 1] == 0) || (i == 0 && b[i] == 1)) {
            psum_b[i + 1] = psum_b[i] + 1;
        } else {
            psum_b[i + 1] = psum_b[i];
        }
    }

    for(int i = 0; i < Q; i++) {
        int L, R, K;
        std::cin >> L >> R >> K;
        L--;
        R--;

        int x = psum_a[R + 1] - psum_a[L];
        int y = psum_b[R + 1] - psum_b[L];
        if(a[L] == 1 && (L - 1 >= 0 && a[L - 1] == 1)) {
            x++;
        } 
        if(b[L] == 1 && (L - 1 >= 0 && b[L - 1] == 1)) {
            y++;
        }
        std::cout << (std::min(x, y) <= K ? "YES" : "NO") << '\n';
    }
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
