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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        if(i == 0) {
            int pre = gcd(A[i], A[i + 1]);
            if(pre == A[i]) {
                ok = false;
            }
        } else if(i == N - 1) {
            int pre = gcd(A[i - 1], A[i]);
            if(pre == A[i]) {
                ok = false;
            }
        } else {
            int l = gcd(A[i - 1], A[i]);
            int r = gcd(A[i + 1], A[i]);
            if(l == A[i] || r == A[i]) {
                ok = false;
            }
            int64_t x = static_cast<int64_t>(l) * r / gcd(l, r);
            if(x >= A[i]) {
                ok = false;
            }
        }
        ans += ok ? 1 : 0;
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
