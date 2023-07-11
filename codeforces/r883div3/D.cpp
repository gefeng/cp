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
    int N, D, H;
    std::cin >> N >> D >> H;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::reverse(A.begin(), A.end());
    
    double ans = ((double)D * H) / 2.0;
    for(int i = 1; i < N; i++) {
        if(A[i - 1] - A[i] < H) {
            double h = H - A[i - 1] + A[i];
            double d = h / H * D;
            
            ans += ((double)D * H) / 2.0 - (d * h) / 2.0; 
        } else {
            ans += ((double)D * H) / 2.0;
        }
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
