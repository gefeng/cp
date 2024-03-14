#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto is_collinear = [](std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) {
        int64_t x1 = a.first - b.first;
        int64_t y1 = a.second - b.second;
        int64_t x2 = c.first - b.first;
        int64_t y2 = c.second - b.second;
        
        return x1 * y2 - x2 * y1 == 0;
    };

    int max_v = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j) {
                int cnt = 2;
                for(int k = 0; k < N; k++) {
                    if(k != i && k != j) {
                        if(is_collinear(A[i], A[j], A[k])) {
                            cnt += 1;
                        }
                    }
                }

                max_v = std::max(max_v, cnt);
            }
        }
    }

    if(max_v / 2 >= N - max_v) {
        std::cout << N - max_v << '\n';        
    } else {
        std::cout << N / 3 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
