#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, L;
    std::cin >> N >> K >> L;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    } 

    std::vector<int> suit;
    for(int i = 0; i < N; i++) {
        if(A[i].second == L) {
            suit.push_back(A[i].first);
        }
    }

    std::sort(suit.begin(), suit.end(), std::greater<int>());
    
    if(suit.size() < K) {
        std::cout << -1 << '\n';
    } else {
        int ans = 0;
        for(int i = 0; i < K; i++) {
            ans += suit[i];
        }

        std::cout << ans << '\n';
    }
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
