#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(A[i] != A[0]) {
            unique = false;
        }
    }

    int ans = 0;
    if(unique) {
        if(A[0] == K) {
            ans = 0;
        } else {
            ans = 1;
        }
    } else {
        bool mul_of_k = true;
        for(int i = 0; i < N; i++) {
            if(gcd(K, A[i]) != K) {
                mul_of_k = false;
                break;
            }
        }

        if(mul_of_k) {
            ans = 1;
        } else {
            int l = 0;
            int r = N - 1;
            ans = 1;
            while(l < N && A[l] == K) {
                l += 1;
            }
            while(r >= 0 && A[r] == K) {
                r -= 1;
            }
            for(int i = l; i <= r; i++) {
                if(A[i] != A[l]) {
                    ans = 2;
                    break;
                }
            }
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
