#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, N;
    std::cin >> N >> X;

    std::vector<int> A(N + 1);
    int p = -1;
    for(int i = 1; i <= N; i++) {
        std::cin >> A[i];
        if(X == A[i]) {
            p = i;
        }
    }

    int lo = 1;
    int hi = N + 1;
    while(hi - lo > 1) {
        int m = (lo + hi) / 2;
        if(A[m] <= X) {
            lo = m;
        } else {
            hi = m;
        }
    }

    std::cout << 1 << '\n';
    std::cout << lo << ' ' << p << '\n';
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
