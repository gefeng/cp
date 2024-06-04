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
    int N, M, K; std::cin >> N >> M >> K;
    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    std::map<int, std::vector<int>> m_col;
    std::map<int, std::vector<int>> m_row;
    for(int i = 0; i < K; i++) {
        m_col[A[i].second].push_back(A[i].first);
        m_row[A[i].first].push_back(A[i].second);
    }

    for(auto& [_, row] : m_col) {
        std::sort(row.begin(), row.end());
    }
    
    for(auto& [_, col] : m_row) {
        std::sort(col.begin(), col.end());
    }

    int64_t ans = 0;
    std::vector<std::pair<int, int>> key_p;
    std::map<std::pair<int, int>, int64_t> delta;

    for(auto& [c, row] : m_col) {
        if(key_p.empty() || row.back() > key_p.rbegin()->first) {
            key_p.emplace_back(row.back(), c);
            delta[{row.back(), c}] = 0;
        }
    }

    int n = key_p.size();
    int pre_r = -1;
    int pre_c = 0;
    for(int i = 0; i < n; i++) {
        auto [r, c] = key_p[i];
        ans += (int64_t)(N - pre_r - 1) * (c - pre_c); 
        pre_r = r;
        pre_c = c;
    }
    ans += (int64_t)(N - pre_r - 1) * (M - pre_c);

    for(int i = 0; i < n; i++) {
        auto [r, c] = key_p[i];
        int cur_r = i == 0 ? -1 : key_p[i - 1].first;
        int to_c = 0;
        int64_t res = 0;
        if(i == n - 1) {
            auto it = std::upper_bound(m_row[r].begin(), m_row[r].end(), c);
            if(it == m_row[r].end()) {
                to_c = M;
            } else {
                to_c = *it;
            }
        } else {
            to_c = key_p[i + 1].second;
        }

        auto it = m_col.find(c); 
        while(it != m_col.end()) {
            int nxt_r = -1;
            for(int x : it->second) {
                if(x > cur_r && (it->first != c || x != r)) {
                    nxt_r = x;
                }
            }

            if(nxt_r != -1) {
                res += (int64_t)(nxt_r - cur_r) * (it->first - c);
                cur_r = nxt_r;
            }
    
            it++;
            if(it == m_col.end() || it->first == to_c) {
                res += (int64_t)(r - cur_r) * (to_c - c); 
                break;
            }
        }  
        
        delta[{r, c}] = res;
    }

    std::cout << ans << '\n';
    for(int i = 0; i < K; i++) {
        if(delta.find(A[i]) == delta.end()) {
            std::cout << 0 << " \n"[i == K - 1];
        } else {
            std::cout << delta[A[i]] << " \n"[i == K - 1];
        }
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
