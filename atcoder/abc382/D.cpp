#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int N, int M, std::vector<int>& now, std::vector<std::vector<int>>& ans) {
    if(now.size() == N) {
        ans.push_back(now);        
        return;
    }

    int size = now.size();
    int ub = M - 10 * (N - size - 1);

    for(int i = size == 0 ? 1 : now.back() + 10; i <= ub; i++) {
        now.push_back(i);
        dfs(N, M, now, ans);
        now.pop_back();
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ans;
    std::vector<int> now;
    dfs(N, M, now, ans);

    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
