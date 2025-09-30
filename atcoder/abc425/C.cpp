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

    std::vector<int> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    int shift = 0;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int C;
            std::cin >> C;
            shift += C;
            shift %= N;
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;
            
            int l = (L + shift) % N;
            int r = (R + shift) % N;
            
            int64_t sum = 0;
            if(l <= r) {
                sum = psum[r + 1] - psum[l];
            } else {
                sum = psum[N] - psum[l] + psum[r + 1];
            }
            std::cout << sum  << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
