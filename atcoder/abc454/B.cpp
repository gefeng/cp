#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> seen(M + 1, 0);
    int ans1 = 1;
    int ans2 = 1;
    for(int i = 0; i < N; i++) {
        if(seen[A[i]]) {
            ans1 = 0;
        }
        seen[A[i]] = 1;
    }

    for(int i = 1; i <= M; i++) {
        if(!seen[i]) {
            ans2 = 0;
        }
    }

    std::cout << (ans1 ? "Yes" : "No") << '\n';
    std::cout << (ans2 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
