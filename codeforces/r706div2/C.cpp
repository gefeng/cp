#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A;
    std::vector<int> B;
    for(int i = 0; i < N << 1; i++) {
        int X, Y;
        std::cin >> X >> Y;

        if(X == 0) {
            A.push_back(Y);
        } else {
            B.push_back(X);
        }
    }

    std::sort(A.begin(), A.end(), [](int x, int y) {
                return std::abs(x) < std::abs(y);  
            });
    std::sort(B.begin(), B.end(), [](int x, int y) {
                return std::abs(x) < std::abs(y);  
            });

    double ans = 0.0;
    for(int i = 0; i < N; i++) {
        ans += sqrtl(int64_t(A[i]) * A[i] + int64_t(B[i]) * B[i]);
    }

    std::cout << std::setprecision(20) << ans << '\n';
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
