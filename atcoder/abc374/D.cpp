#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>

constexpr int INF = int(2e9);

void run_case() {
    int N, S, T;
    std::cin >> N >> S >> T;

    std::vector<std::array<int, 4>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> A[i][j];
        }
    }

    auto get_dist = [](int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }; 

    std::vector<int> permutation(N, 0);
    std::iota(permutation.begin(), permutation.end(), 0);

    double ans = INF;
    do {
        for(int m = 0; m < (1 << N); m++) {
            double move = 0;
            double print = 0;
            std::pair<int, int> pre = {0, 0};
            for(int i = 0; i < N; i++) {
                int j = permutation[i];
                if(m & (1 << i)) {
                    move += get_dist(pre.first, pre.second, A[j][2], A[j][3]); 
                    pre = {A[j][0], A[j][1]};
                } else {
                    move += get_dist(pre.first, pre.second, A[j][0], A[j][1]);
                    pre = {A[j][2], A[j][3]};
                }
                print += get_dist(A[j][0], A[j][1], A[j][2], A[j][3]);
            }
            ans = std::min(ans, move / S + print / T);
        }
    } while(std::next_permutation(permutation.begin(), permutation.end()));

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
