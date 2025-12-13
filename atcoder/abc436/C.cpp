#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int ans = 0;
    std::set<std::pair<int, int>> s;
    for(auto [r, c] : A) {
        bool ok = true;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(s.find({r + i, c + j}) != s.end()) {
                    ok = false;
                }
            }
        } 
        if(ok) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    s.insert({r + i, c + j});
                }
            } 
            ans += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
