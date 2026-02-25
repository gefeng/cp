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

    std::vector<int> psum(N + 1, 0);
    std::vector<int> cnt0(N + 1, 0);
    std::vector<int> nxt(N, -1);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] ^ A[i];
        cnt0[i + 1] = cnt0[i] + (A[i] == 0 ? 1 : 0);
    }

    std::map<int, int> eve;
    std::map<int, int> odd;
    for(int i = N - 1; i >= 0; i--) {
        int t = psum[i];
        if(i % 2 == 0) {
            nxt[i] = eve.find(t) == eve.end() ? N : eve[t];
            eve[psum[i + 1]] = i;
        } else {
            nxt[i] = odd.find(t) == odd.end() ? N : odd[t];
            odd[psum[i + 1]] = i;
        }
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        if(psum[R + 1] ^ psum[L]) {
            std::cout << -1 << '\n';
            continue;
        }
        int len = R - L + 1;
        if(cnt0[R + 1] - cnt0[L] == len) {
            std::cout << 0 << '\n';
            continue;
        }

        if(len % 2 == 1) {
            std::cout << 1 << '\n';
        } else {
            if(A[L] == 0 || A[R] == 0) {
                std::cout << 1 << '\n';
            } else {
                if(nxt[L] > R) {
                    std::cout << -1 << '\n';
                } else {
                    std::cout << 2 << '\n';
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
