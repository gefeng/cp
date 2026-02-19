#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + A[i];
        psum2[i + 1] = psum2[i] ^ A[i];
    }

    int64_t t = psum1[N] - psum2[N];
    int64_t sum = psum1[N];
    int64_t sum_xor = psum2[N];
    for(int _ = 0; _ < Q; _++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
    
        int l = 0;
        int r = N;
        int i = N - 1;
        while(i >= 0) {
            if(sum - sum_xor != t) {
                break; 
            }
            while(i >= 0 && A[i] == 0) {
                i -= 1;
            }
            if(i >= 0) {
                for(int j = 0; j <= i; j++) {
                    if((psum1[i + 1] - psum1[j]) - (psum2[i + 1] ^ psum2[j]) == t) {
                        if(i - j + 1 < r - l + 1) {
                            l = j;
                            r = i;
                        }
                    }
                }
                sum -= A[i];
                sum_xor ^= A[i];
                i -= 1;
            } else {
                if(r == N) {
                    l = 0;
                    r = 0;
                }
            }
        }

        std::cout << l + 1 << ' ' << r + 1 << '\n';
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
