#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    std::set<int> s;
    s.insert(0);

    auto dist = [&](int x) {
        int l = INF;
        int r = INF;
        auto it = s.upper_bound(x);

        if(it != s.end()) {
            r = *it - x;
        }

        it = s.lower_bound(x);
        if(it != s.begin()) {
            l = x - *std::prev(it);
        }
        return std::min(l, r);
    };

    for(int i = 0; i < N; i++) {
        if(i == 0) {
            sum += A[i] * 2;
            s.insert(A[i]);
        } else {
            int l = -1;
            int r = -1;
            auto it = s.upper_bound(A[i]);
            if(it != s.end()) {
                r = *it;
            }
            if(it != s.begin()) {
                l = *std::prev(it);
            }

            int dl = dist(l);

            if(r == -1) {
                sum -= dl;
                sum += std::min(dl, A[i] - l);
                sum += A[i] - l;
            } else {
                int dr = dist(r);
                sum -= dl;
                sum += std::min(dl, A[i] - l);
                sum -= dr;
                sum += std::min(dr, r - A[i]);
                sum += std::min(A[i] - l, r - A[i]);
            }
            s.insert(A[i]);
        }
        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
