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

    std::sort(A.begin(), A.end());    
    
    int p = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] != 0) {
            p = i;
            break;
        }
    }

    if(p == -1) {
        std::cout << K << '\n';
        return;
    }

    if(N == 1) {
        std::cout << (K <= A[0] ? K - 1 : K) << '\n';
        return;
    }

    int g = A[p];
    for(int i = p + 1; i < N; i++) {
        g = gcd(g, A[i]);
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 0, x = 0; i < N; i++, x += g) {
        if(i + 1 < N) {
            if(cnt + g - 1 < K) {
                cnt += g - 1;
            } else {
                ans = x + K - cnt;
                break;
            }
        } else {
            ans = x + K - cnt;
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
