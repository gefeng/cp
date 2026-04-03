#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < K; i++) {
        bool unique = true;
        for(int j = i; j < N; j += K) {
            if(A[j] != A[i]) {
                unique = false;
            }
        }
        if(!unique) {
            for(int j = i; j < N; j += K) {
                if(B[j] == -1) {
                    B[j] = A[j];
                } else {
                    if(B[j] != A[j]) {
                        std::cout << "NO" << '\n';
                        return;
                    }
                }
            }
        } else {
            int v = -1;
            for(int j = i; j < N; j += K) {
                if(B[j] != -1) {
                    v = B[j];
                }
            }
            if(v != -1) {
                for(int j = i; j < N; j += K) {
                    if(B[j] != -1 && B[j] != v) {
                        std::cout << "NO" << '\n';
                        return;
                    }
                    B[j] = v;
                }
            }
        }
    }

    std::vector<int> cnt(N + 1, 0);
    for(int i = 0; i < K; i++) {
        cnt[A[i]] += 1;
    }

    int bal = 0;
    for(int i = 0; i < K; i++) {
        if(B[i] != -1) {
            if(--cnt[B[i]] < 0) {
                std::cout << "NO" << '\n';
                return;
            }
        } else {
            bal++;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(cnt[i] && bal < cnt[i]) {
            std::cout << "NO" << '\n';
            return;
        }
        bal -= cnt[i];
        cnt[i] = 0;
    }

    std::cout << (bal == 0 ? "YES" : "NO") << '\n';
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
