#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A, std::greater<int>());

    int n = std::min(30, N);
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
       
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = A[i];
        }

        int cost = 0;
        while(true) {
            int max_v = -1;
            int p = -1;
            for(int i = 0; i < n; i++) {
                if(a[i] > max_v) {
                    max_v = a[i];
                    p = i;
                }
            }

            if(max_v >= X) {
                break;
            }

            int hb1 = -1;
            int hb2 = -1;
            for(int b = 29; b >= 0; b--) {
                if(X & (1 << b)) {
                    hb1 = b;
                    break;
                }
            }
            for(int b = 29; b >= 0; b--) {
                if(max_v & (1 << b)) {
                    hb2 = b;
                    break;
                }
            }
            if(hb1 > hb2) {
                cost += (1 << hb1) - max_v;
                a[p] = 0;
            } else {
                a[p] ^= (1 << hb1);
            }
            X ^= 1 << hb1;
        }
        std::cout << cost << '\n';
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
