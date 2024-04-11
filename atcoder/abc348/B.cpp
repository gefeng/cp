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

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto get_dist = [&](int i, int j) {
        int64_t d = (A[i].first - A[j].first) * (A[i].first - A[j].first) + (A[i].second - A[j].second) * (A[i].second - A[j].second);
        return d;
    };

    for(int i = 0; i < N; i++) {
        int p = -1;
        int64_t max_d = 0;
        
        for(int j = 0; j < N; j++) {
            if(i != j) {
                int64_t d = get_dist(i, j);
                if(d > max_d) {
                    max_d = d;
                    p = j;
                }
            }
        }

        std::cout << p + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
