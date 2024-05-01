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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> psum1(N + 1, 0);
    std::vector<int> psum2(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum1[i] = psum1[i - 1] + (A[i - 1] == 1 ? 1 : 0);
        psum2[i] = psum2[i - 1] + (A[i - 1] == 2 ? 1 : 0);
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R, K;
        std::cin >> L >> R >> K;
        L -= 1;
        R -= 1;

        int a = psum1[R + 1] - psum1[L];
        int b = psum2[R + 1] - psum2[L];
        int c = R - L + 1 - a - b;

        if(a > b) {
            std::swap(a, b);
        }

        int d = std::min(b - a, std::min(c, K));
        a += d;
        K -= d;
        c -= d;

        if(c && K) {
            d = std::min(c, K);
            a += d / 2;
            b += (d + 1) / 2;
            c -= d;
            K -= d;
        }

        if(K) {
            d = std::min(K, (b - a) / 2);
            a += d;
            b -= d;
            K -= d;
        }
        
        std::cout << int64_t(a) * b << '\n';
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
