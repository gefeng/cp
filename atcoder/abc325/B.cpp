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

    int ans = 0;
    for(int i = 0; i < 24; i++) {
        int cnt = 0;
        for(auto [w, x] : A) {
            int ts = (i + x) % 24;
            int te = (i + x + 1) % 24; 
            if(ts >= 9 && ts <= 18 && te >= 9 && te <= 18) {
                cnt += w; 
            }
        } 

        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
