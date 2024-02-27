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
    int N, L, D;
    std::cin >> N >> L >> D;

    std::vector<double> dp1(N + 1, 0.0);
    std::vector<double> ds1(N + 2, 0.0); 

    dp1[0] = 1.0;
    ds1[1] = 1.0;     

    for(int i = 1; i <= N; i++) {
        int l = std::max(0, i - D);
        int r = std::min(L - 1, i - 1);

        if(l <= r) {
            dp1[i] = (ds1[r + 1] - ds1[l]) / D;
        }
        ds1[i + 1] = ds1[i] + dp1[i];
    }

    std::vector<double> dp2(N + 1, 0.0);
    std::vector<double> ds2(N + 2, 0.0);

    for(int i = N; i >= 0; i--) {
        double stop = 1.0 - (ds1[N + 1] - ds1[std::max(L, i)]);
        double keep_rolling = (ds2[N - i] - ds2[std::max(0, N - i - D)]) / D;
        dp2[i] = std::max(stop, keep_rolling);
        ds2[N - i + 1] = ds2[N - i] + dp2[i]; 
    }

    std::cout << dp2[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
