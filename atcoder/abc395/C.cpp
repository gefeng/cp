#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);
constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<std::vector<int>> pos(MAX + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    }

    int ans = INF;
    for(auto& a : pos) {
        if(a.size() < 2) {
            continue;
        }

        int n = a.size();
        for(int i = 1; i < n; i++) {
            ans = std::min(ans, a[i] - a[i - 1] + 1);
        }
    } 

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
