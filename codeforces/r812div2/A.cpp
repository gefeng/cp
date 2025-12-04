#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::array<int, 4> far = {};
    for(int i = 0; i < N; i++) {
        if(A[i].first != 0) {
            if(A[i].first < 0) {
                far[0] = std::max(far[0], -A[i].first);
            } else {
                far[1] = std::max(far[1], A[i].first);
            }
        } else {
            if(A[i].second < 0) {
                far[2] = std::max(far[2], -A[i].second);
            } else {
                far[3] = std::max(far[3], A[i].second);
            }
        }
    }

    int ans = 0;;
    for(int i = 0; i < 4; i++) {
        ans += far[i] * 2;
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
