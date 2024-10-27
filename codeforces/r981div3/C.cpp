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

    for(int l = N / 2 - 1, r = N % 2 == 1 ? N / 2 + 1 : N / 2; l >= 0 && r < N; l--, r++) {
        int d1 = 0;
        int d2 = 0;

        if(r - l > 1) {
            if(l + 1 < N && A[l + 1] == A[l]) {
                d1 += 1;
            }
            if(r && A[r - 1] == A[r]) {
                d1 += 1;
            }
            
            if(l + 1 < N && A[l + 1] == A[r]) {
                d2 += 1;
            }
            if(r && A[r - 1] == A[l]) {
                d2 += 1;
            }
        }

        if(d1 > d2) {
            std::swap(A[l], A[r]);
        }
    }

    int ans = 0;
    for(int i = 0; i < N - 1; i++) {
        if(A[i] == A[i + 1]) {
            ans += 1;
        }
    }

    std::cout << ans << '\n';
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
