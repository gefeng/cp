#include <iostream>
#include <utility>
#include <cassert> 
#include <algorithm> 
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<std::pair<int64_t, int64_t>> ans;
    
    auto solve = [&](int rotated) {
        std::vector<std::map<int, std::multiset<int>>> m(2);
        
        for(int i = 0; i < N; i++) {
            m[0][A[i].first].insert(A[i].second);
            m[1][A[i].second].insert(A[i].first);
        }

        std::array<int64_t, 2> res = {};
        std::array<int64_t, 2> pre = {};
        std::array<int64_t, 2> sum = {};
        int t = 0;
        bool good = true;
        while(true) {
            if(m[t].empty()) {
                break;
            }
            
            auto& [v, s] = *m[t].rbegin();

            if(pre[t] != 0 && sum[t] + v != pre[t]) {
                good = false;
                break;
            }

            res[t] = std::max(res[t], sum[t] + v);
            
            int64_t new_sum = 0;
            for(int x : s) {
                new_sum += x;
                m[t ^ 1][x].erase(m[t ^ 1][x].find(v)); 
                if(m[t ^ 1][x].empty()) {
                    m[t ^ 1].erase(x);
                }
            }
            sum[t ^ 1] = new_sum;
            res[t ^ 1] = std::max(res[t ^ 1], new_sum);
            pre[t] = v; 
            m[t].erase(v);

            if(m[t].empty() && pre[t ^ 1] != 0 && sum[t ^ 1] != pre[t ^ 1]) {
                good = false;
            }

            t ^= 1;
        }

        if(good && m[0].empty() && m[1].empty()) {
            if(rotated) {
                std::swap(res[0], res[1]);
            }
            if(ans.empty() || ans[0] != std::pair<int64_t, int64_t>(res[0], res[1])) {
                ans.emplace_back(res[0], res[1]);
            }
        }
    };

    solve(0);
    for(int i = 0; i < N; i++) {
        std::swap(A[i].first, A[i].second);
    }
    solve(1);

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
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
