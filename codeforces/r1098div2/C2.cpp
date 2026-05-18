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

    int64_t ans = INF;

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

    if(N == 1) {
        if(A[0] == 0) {
            std::cout << X << '\n';
            return;
        }
        int64_t now = 0;
        for(int i = 0; i <= len; i++) {
            now = now * 10 + A[0];
            ans = std::min(ans, std::abs(X - now));
        }
        std::cout << ans << '\n';
        return;
    }


    if(len > 1) {
        x = 0;
        for(int i = 0; i < len - 1; i++) {
            x = x * 10 + A.back();
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
        for(int p = 0; p < N; p++) {
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
                    x = x * 10 + A.back();
                }
                ans = std::min(ans, std::abs(X - x));
            }
        }
        bool found = false;
        for(int p = 0; p < N; p++) {
            if(digits[i] == A[p]) {
                now = now * 10 + A[p];
                found = true;
                break;
            }
        }
        if(!found) {
            break;
        }
    }

    if(i < 0) {
        ans = 0;
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
    }
}
