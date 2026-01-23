#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double INF = 2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    std::ranges::sort(A);

    std::vector<int> suffix(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        suffix[i] = std::max(suffix[i - 1], A[N - i].first + A[N - i].second);
    }

    double min_t = INF;
    double ans = 0.0;
    int prefix = -static_cast<int>(2e9);
    for(int i = 0; i < N; i++) {
        double l = i == 0 ? prefix : prefix + A[i].first;
        double r = suffix[N - i] - A[i].first;

        double t = std::max(l, r);
        if(t < min_t) {
            min_t = t;
            ans = A[i].first;
        }

        prefix = std::max(prefix, A[i].second - A[i].first); 

        if(i + 1 < N) { 
            double x = (suffix[N - i - 1] - prefix) / 2.0;
            if(x >= A[i].first && x <= A[i + 1].first) {
                t = std::max(prefix + x, suffix[N - i - 1] - x);
                if(t < min_t) {
                    min_t = t;
                    ans = x;
                }
            }
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
