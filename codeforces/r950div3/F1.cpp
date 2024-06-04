#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    std::map<int, std::vector<int>> col;
    for(int i = 0; i < K; i++) {
        col[A[i].second].push_back(A[i].first);
    }

    for(auto& [_, row] : col) {
        std::sort(row.begin(), row.end());
    }

    int64_t ans = 0;
    int pre_c = 0;
    int pre_r = 0; 
    std::set<std::pair<int, int>> points;
    for(auto& [c, row] : col) {
        ans += (int64_t)(N - pre_r) * (c - pre_c);
        pre_c = c;
        if(row.back() + 1 > pre_r) {
            pre_r = row.back() + 1;
            points.emplace(pre_r - 1, c);
        }
    }
    ans += (int64_t)(N - pre_r) * (M - pre_c);

    std::cout << ans << '\n';
    for(int i = 0; i < K; i++) {
        int64_t res = 0;
        if(points.find(A[i]) != points.end()) {
            res = 1;
        }    
        std::cout << res << " \n"[i == K - 1];
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
