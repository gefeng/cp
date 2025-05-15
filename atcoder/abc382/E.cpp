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
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<double> dp_1(N + 1, 0.0);
    dp_1[0] = 1.0;
    for(int i = 1; i <= N; i++) {
        std::vector<double> ndp_1(N + 1, 0.0);
        double p = A[i - 1] / 100.0;
        for(int j = 0; j <= i; j++) {
            if(j + 1 <= i) {
                ndp_1[j + 1] += dp_1[j] * p;
            }
            if(j < i) {
                ndp_1[j] += dp_1[j] * (1.0 - p);
            }
        }
        std::swap(dp_1, ndp_1);
    } 
    
    std::vector<double> dp_2(X + 1, 0);
    for(int i = 1; i <= X; i++) {
        double e = 0.0;
        for(int j = 0; j <= N; j++) {
            if(i - j >= 0 && i - j < X) {
                e += dp_2[i - j] * dp_1[j];
            } 
        }
        dp_2[i] = (e + 1) / (1.0 - dp_1[0]);
    }

    std::cout << std::setprecision(20) << dp_2[X] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
