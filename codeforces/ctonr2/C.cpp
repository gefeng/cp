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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::ranges::sort(A);

    if(M == 1) {
        std::cout << std::min(2, N) << '\n';
        return;
    }

    std::vector<int> a;
    for(int i = 0; i < M; i++) {
        int nxt = A[(i + 1) % M];
        if(nxt - A[i] > 1) {
            a.push_back(nxt - A[i] - 1);
        }
        if(nxt < A[i]) {
            a.push_back(N - A[i] - 1 + nxt);
        }
    }

    std::ranges::sort(a, std::greater<int>());

    int64_t saved = 0;
    int64_t day = 1;
    for(auto x : a) {
        int infected = (day - 1) * 2;
        if(x > infected) {
            saved += 1;
            if(x - infected - 1 > 0) {
                saved += x - infected - 2;
            }
        }
        day += 2;
    }

    std::cout << N - saved << '\n';
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
