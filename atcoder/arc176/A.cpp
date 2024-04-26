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
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> ans;
    std::map<int, std::set<int>> m;
    for(int i = 0; i < M; i++) {
        int X, Y;
        std::cin >> X >> Y;

        X -= 1;
        Y -= 1;
        ans.emplace_back(X, Y);
        m[(X + Y) % N].emplace(X);
    }

    for(int r = 0; r < N && m.size() < M; r++) {
        if(m.find(r) == m.end()) {
            m[r];
        }
    }

    for(auto& [r, s] : m) {
        for(int i = 0; i < N; i++) {
            if(s.find(i) != s.end()) {
                continue;
            }
            int x = i % N;
            int j = 0;
            if(x <= r) {
                j = (r - x) % N;
            } else {
                j = (r - x + N) % N;
            }
            ans.emplace_back(i, j);
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
