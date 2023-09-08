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

    std::string S;
    std::cin >> S;
    std::vector<int> psum(N + 1, 0);
    int xor_sum_one = 0;
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] ^ A[i - 1];
        if(S[i - 1] == '1') {
            xor_sum_one ^= A[i - 1];
        }
    } 

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;
            xor_sum_one ^= psum[R + 1] ^ psum[L];
        } else {
            int G;
            std::cin >> G;
            std::cout << (G == 0 ? (psum[N] ^ xor_sum_one) : xor_sum_one) << ' ';
        }
    }

    std::cout << std::endl;
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
