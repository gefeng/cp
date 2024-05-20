#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i][0] >> A[i][1];
        A[i][2] = i;
    }

    std::sort(A.begin(), A.end());
    
    std::vector<int> min_cost(N, INF);
    int min_c = INF;
    for(int i = N - 1; i >= 0; i--) {
        if(i + 1 < N) {
            min_cost[i] = min_c;
        }
        min_c = std::min(min_c, A[i][1]);
    }

    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(A[i][1] <= min_cost[i]) {
            ans.push_back(A[i][2]);
        } 
    }

    std::sort(ans.begin(), ans.end());

    int m = ans.size();
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        std::cout << ans[i] + 1 << " \n"[i == m - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
