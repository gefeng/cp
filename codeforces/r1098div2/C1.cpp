#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int64_t X;
    int N;
    std::cin >> X >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(X == 0) {
        std::cout << A[0] << '\n';
        return;
    }

    std::vector<int> digits;
    int64_t x = X;
    while(x) {
        digits.push_back(x % 10);
        x /= 10;
    }

    int len = digits.size();
    int64_t ans = INF;

    if(len > 1) {
        x = 0;
        for(int i = 0; i < len - 1; i++) {
            x = x * 10 + A[1];
        }
        ans = std::min(ans, std::abs(X - x));
    }

    x = A[0] == 0 ? A[1] : A[0];
    for(int i = 0; i < len; i++) {
        x = x * 10 + A[0];
    }
    ans = std::min(ans, std::abs(X - x));

    int64_t now = 0;
    int i = len - 1;
    for(; i >= 0; i--) {
        for(int p = 0; p < 2; p++) {
            if(A[p] > digits[i]) {
                x = now * 10 + A[p];
                for(int j = i - 1; j >= 0; j--) {
                    x = x * 10 + A[0];
                }
                ans = std::min(ans, std::abs(X - x));
            }
            if(A[p] < digits[i]) {
                x = now * 10 + A[p];
                for(int j = i - 1; j >= 0; j--) {
                    x = x * 10 + A[1];
                }
                ans = std::min(ans, std::abs(X - x));
            }
        }
        if(digits[i] == A[0]) {
            now = now * 10 + A[0];
            continue;
        }
        if(digits[i] == A[1]) {
            now = now * 10 + A[1];
            continue;
        }
        break;
    }

    if(i < 0) {
        ans = 0;
    }

    std::cout << ans << '\n';
}

void naive() {
    int64_t X;
    int N;
    std::cin >> X >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto valid = [&](int64_t x) {
        if(x == 0) {
            return x == A[0];
        }
        while(x) {
            int d = x % 10;
            if(d != A[0] && d != A[1]) {
                return false;
            }
            x /= 10;
        }
        return true;
    };

    int max_v = 1000;
    int64_t ans = INF;
    for(int x = 0; x <= max_v; x++) {
        if(valid(x)) {
            ans = std::min(ans, std::abs(X - x));
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
        //naive();
    }
}
