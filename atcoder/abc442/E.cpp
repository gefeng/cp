#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

struct P {
    int x = 0;
    int y = 0;
    bool operator< (const auto& o) const {
        int h1 = y > 0 || (y == 0 && x > 0);
        int h2 = o.y > 0 || (o.y == 0 && o.x > 0);
        
        if(h1 == h2) {
            return static_cast<int64_t>(x) * o.y > static_cast<int64_t>(o.x) * y;
        } else {
            return h1 > h2;
        }
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<P> A(N);
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        A[i] = {X, Y};
    }

    std::vector<P> a(A);
    
    std::sort(a.begin(), a.end());

    for(int i = 0; i < Q; i++) {
        int S, T;
        std::cin >> S >> T;
        S -= 1;
        T -= 1;

        int res = 0;
        if(A[S] < A[T]) {
            res = std::upper_bound(a.begin(), a.end(), A[S]) - a.begin() + a.end() - std::lower_bound(a.begin(), a.end(), A[T]);
        } else {
            res = std::upper_bound(a.begin(), a.end(), A[S]) - std::lower_bound(a.begin(), a.end(), A[T]);
        }

        std::cout << res << '\n';
        

        // double s = std::atan2(A[S].second, A[S].first);
        // double t = std::atan2(A[T].second, A[T].first);
        //
        // int res = 0;
        // if(s >= t) {
        //     res = std::upper_bound(a.begin(), a.end(), s, [](double x, const auto& y) {
        //             return x < std::atan2(y.second, y.first);
        //         }) - std::lower_bound(a.begin(), a.end(), t, [](const auto& y, double x) {
        //                 return std::atan2(y.second, y.first) < x;
        //             });
        // } else {
        //     res = std::upper_bound(a.begin(), a.end(), s, [](double x, const auto& y) {
        //             return x < std::atan2(y.second, y.first);
        //         }) - a.begin() + a.end() - std::lower_bound(a.begin(), a.end(), t, [](const auto& y, double x) {
        //                 return std::atan2(y.second, y.first) < x;
        //             });
        // }
        //
        // std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
