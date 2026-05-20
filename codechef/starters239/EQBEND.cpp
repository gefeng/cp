#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;
constexpr int MAX = 100;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(A[0] == A.back()) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = INF;
    std::vector<int> first(MAX + 1, -1);
    std::vector<int> last(MAX + 1, -1);
    for(int i = 0; i < N; i++) {
        first[A[i]] = first[A[i]] == -1 ? i : first[A[i]];
        last[A[i]] = i;
    }

    for(int i = 1; i <= MAX; i++) {
        if(first[i] != -1 && last[i] != -1 && first[i] != last[i]) {
            ans = std::min(ans, first[i] + N - 1 - last[i]);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
