#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double EPS = 1e-9;
constexpr double INF = 1e18;

void run_case(int T) {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    auto is_overlap = [](double l1, double r1, double l2, double r2) {
        if(l2 - l1 < EPS) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }

        return l2 - r1 < EPS;
    };

    double l = 1.0 / B[0];
    double r = A[0] == 0 ? INF : 1.0 / A[0];
    for(int i = 2; i <= N; i++) {
        double x = (double)i / B[i - 1];
        double y = A[i - 1] == 0 ? INF : (double)i / A[i - 1];
        
        if(is_overlap(l, r, x, y)) {
            l = std::max(l, x);
            r = std::min(r, y);
        } else {
            l = -1;
            r = -1;
            break;
        }
    }

    std::cout << std::setprecision(20) << "Case #" << T << ": " << l << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
