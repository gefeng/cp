#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<int> A(X);
    for(int i = 0; i < X; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    for(int i = 0; i < X; i++) {
        int j = (i + 1) % X;
        
        int d = (A[j] - A[i] + N) % N;
        if(d == 2) {
            ans += 1;
        }
    }

    ans += X - 2;

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
