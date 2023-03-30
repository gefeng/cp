#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using LL = long long;

constexpr double EPS = 1e-12;

void run_case() {
    int N, M;
    LL K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    double lo = 0.0;
    double hi = 1.0;
    double ans = 0.0;
    while(lo <= hi - EPS) {
        double mid = (lo + hi) / 2.0;

        std::vector<double> v(N);
        for(int i = 0; i < N; i++) {
            v[i] = A[i].first - mid / (1.0 - mid) * A[i].second;
        } 

        sort(v.begin(), v.end());

        LL cnt = 0LL;
        for(auto& p : B) {
            double need = (double)p.first - mid / (1.0 - mid) * p.second;

            auto it = lower_bound(v.begin(), v.end(), -need);

            cnt += (LL)(v.end() - it);
        }
        if(cnt >= K) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    std::cout << std::setprecision(20) << ans * 100.0 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
