#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 100;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    int max_w = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        max_w = std::max(max_w, A[i].first);
    }

    std::vector<int> max_h(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < A[i].first; j++) {
            max_h[j] = std::max(max_h[j], A[i].second);
        }
    }

    int ans = 0;
    for(int i = 0; i <= MAX; i++) {
        if(max_h[i] == 0) {
            ans += max_h[i - 1];
            break;
        }
        if(i == 0) {
            ans += 1;
        } else {
            ans += max_h[i - 1] - max_h[i] + 1;
        }
    }

    ans += max_w + max_h[0];

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
