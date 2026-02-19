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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + A[i];
        psum2[i + 1] = psum2[i] ^ A[i];
    }
    
    std::vector<int> nxt(N, N);
    std::vector<int> pre(N, -1);
    for(int i = 0; i < N; i++) {
        if(i && A[i - 1] != 0) {
            pre[i] = i - 1;
        } else {
            pre[i] = i == 0 ? -1 : pre[i - 1];
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(i + 1 < N && A[i + 1] != 0) {
            nxt[i] = i + 1;
        } else {
            nxt[i] = i == N - 1 ? N : nxt[i + 1];
        }
    }

    for(int _ = 0; _ < Q; _++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int64_t s = psum1[R + 1] - psum1[L];
        int64_t xs = psum2[R + 1] ^ psum2[L];
        
        if(s == 0) {
            std::cout << L + 1 << ' ' << L + 1 << '\n';
            continue;
        }

        int64_t t = s - xs;
        int i = R;
        int l = L;
        int r = R;
        while(i >= L) {
            int j = L;
            if(A[i] == 0) {
                i = pre[i];
                if(i < j) {
                    break;
                }
            }
            if(psum1[i + 1] - psum1[j] - (psum2[i + 1] ^ psum2[j]) != t) {
                break;
            }
            while(j <= i) {
                if(A[j] == 0) {
                    j = nxt[j];
                    if(j > i) {
                        break;
                    }
                }
                if(psum1[i + 1] - psum1[j] - (psum2[i + 1] ^ psum2[j]) == t) {
                    if(i - j + 1 < r - l + 1) {
                        l = j;
                        r = i;
                    }
                } else {
                    break;
                }
                j += 1;
            }
            i -= 1;
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
