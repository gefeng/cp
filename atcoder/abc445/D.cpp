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
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::pair<int, int>> A(N);
    std::map<int, std::set<int>> m1;
    std::map<int, std::set<int>> m2;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        m1[A[i].first].insert(i); 
        m2[A[i].second].insert(i);
    }

    int x = 0;
    int y = 0;
    std::vector<std::pair<int, int>> ans(N);
    while(!m1.empty()) {
        int i = m1.find(H) != m1.end() ? *m1[H].begin() : *m2[W].begin();
        auto [h, w] = A[i];
        m1[h].erase(i);
        m2[w].erase(i);

        if(m1[h].empty()) {
            m1.erase(h);
        }
        if(m2[w].empty()) {
            m2.erase(w);
        }

        ans[i] = {x + 1, y + 1};

        if(h == H) {
            W -= w;
            y += w;
        } else {
            H -= h;
            x += h;
        }
    }

    for(auto [r, c] : ans) {
        std::cout << r << ' ' << c << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
