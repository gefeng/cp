#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int64_t a, int64_t b, int64_t c, int64_t &x0, int64_t &y0, int64_t &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int64_t upper_bound(int64_t x, int64_t y) {
    if(x >= 0) {
        return (x + y - 1) / y;
    }
    return x / y;
}

int64_t lower_bound(int64_t x, int64_t y) {
    if(x >= 0) {
        return x / y;
    }
    return -((-x + y - 1) / y);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int M;
    std::cin >> M;

    std::vector<std::pair<int64_t, int64_t>> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.second - x.first > y.second - y.first;
            });

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + A[i].first;
        psum2[i + 1] = psum2[i] + A[i].second;
    }

    int64_t max_v = 0;
    int max_b = -1;
    for(int i = 0; i <= N; i++) {
        int64_t s = psum2[i] + psum1[N] - psum1[i];
        if(s > max_v) {
            max_v = s;
            max_b = i;
        }
    }

    for(auto [r, b] : B) {
        //x * r + y * b = n 
        int64_t x0 = 0;
        int64_t y0 = 0;
        int64_t g = 0;
        bool ok = find_any_solution(r, b, N, x0, y0, g);
        if(ok) {
            int64_t res = -1;
            
            int64_t d1 = b * y0 - max_b;
            int64_t d2 = (b * r) / g;
            int64_t k1 = upper_bound(d1, d2);
            int64_t k2 = lower_bound(d1, d2);

            int64_t y1 = y0 - k1 * (r / g);
            int64_t y2 = y0 - k2 * (r / g);

            if(y1 >= 0 && y1 * b <= N) {
                res = std::max(res, psum2[y1 * b] + psum1[N] - psum1[y1 * b]);
            }
            if(y2 >= 0 && y2 * b <= N) {
                res = std::max(res, psum2[y2 * b] + psum1[N] - psum1[y2 * b]);
            }

            std::cout << res << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
