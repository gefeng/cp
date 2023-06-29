#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<LL> save_rating(N + 1, 0);
    std::vector<LL> save_min(N + 1);
    LL rating = 0LL;
    for(int i = 0; i < N; i++) {
        rating += A[i];
        save_rating[i + 1] = rating;
    }

    LL min_r = INF;
    for(int i = N; i >= 0; i--) {
        min_r = std::min(min_r, save_rating[i]);
        save_min[i] = min_r;
    }

    LL ans = 0LL;
    LL max_r = -INF;
    for(int i = 0; i <= N; i++) {
        LL k = save_rating[i]; 
        LL new_rating = save_rating.back() + (k - save_min[i]);

        if(new_rating > max_r) {
            max_r = new_rating;
            ans = k;
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
