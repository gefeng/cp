#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    int64_t ans = 0;
    int64_t score = 0;
    int l = N % 2;
    int r = N - 1;
    while(l < r) {
        if(A[l] >= R) {
            score += A[r] - R + A[l] - R;
        } else if(A[r] <= L) {
            score += L - A[r] + L - A[l];
        } else {
            score += A[r] - A[l];
        }
        l += 1;
        r -= 1;
    }
    ans = score;

    auto single = [&](int x) {
        if(x < L) {
            return L - x;
        }
        if(x > R) {
            return x - R;
        }
        return 0;
    };

    if(N % 2 == 1) {
        ans = score + single(A[0]);
        for(int i = 1; i < N; i++) {
            int x = std::min(A[i], A[N - i]);
            int y = std::max(A[i], A[N - i]);
            if(x >= R) {
                score -= x - R + y - R;
            } else if(y <= L) {
                score -= L - x + L - y;
            } else {
                score -= y - x;
            }

            x = std::min(A[i - 1], A[N - i]);
            y = std::max(A[i - 1], A[N - i]);
            if(x >= R) {
                score += x - R + y - R;
            } else if(y <= L) {
                score += L - x + L - y;
            } else {
                score += y - x;
            }
            ans = std::max(ans, score + single(A[i]));
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
    }
}
