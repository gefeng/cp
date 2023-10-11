#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case(int T) {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    double ans = 0;
    double l = 0.0;
    double r = 0.0;
    if(N != 5) {
        l = (double)(A[0] + A[1]) / 2.0;
        r = (double)(A[N - 2] + A[N - 1]) / 2.0;
        ans = std::max(ans, r - l);
    } else {
        l = (double)(A[0] + A[1]) / 2.0;
        r = (double)(A[N - 3] + A[N - 1]) / 2.0;
        ans = std::max(ans, r - l);
         
        l = (double)(A[0] + A[2]) / 2.0;
        r = (double)(A[N - 2] + A[N - 1]) / 2.0;
        ans = std::max(ans, r - l);
    }
    
    std::cout << std::setprecision(20) << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
