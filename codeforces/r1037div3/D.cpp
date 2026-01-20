#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <queue>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;
        A[i] = {L, X};
    }

    std::ranges::sort(A);

    int now = K;
    int i = 0;
    while(i < N && A[i].first <= now) {
        now = std::max(now, A[i].second);
        i += 1;
    } 

    std::cout << now << '\n';
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
