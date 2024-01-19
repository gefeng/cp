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
    int N;
    std::cin >> N;

    std::vector<int> ans(N, 0);
    std::vector<std::set<int>> potions(N + 1);
    
    std::vector<std::pair<int, int>> E(N);
    for(int i = 0; i < N; i++) {
        std::cin >> E[i].first >> E[i].second;
    }
    
    for(int i = 0; i < N; i++) {
        int t = E[i].first;
        int x = E[i].second;
        if(t == 1) {
            potions[x].insert(i);    
        } else {
            if(potions[x].empty()) {
                std::cout << -1 << '\n';
                return;
            }

            auto it = potions[x].lower_bound(i);
            it--;
            ans[*it] = 1;
            ans[i] = -1;
            potions[x].erase(it);
        }
    }

    int max_k = 0;
    int have = 0;
    for(int i = 0; i < N; i++) {
        if(ans[i] == -1) {
            have -= 1; 
        } else if(ans[i] == 1) {
            have += 1;
        }
        max_k = std::max(max_k, have);
    }

    std::cout << max_k << '\n';
    for(int i = 0; i < N; i++) {
        if(ans[i] != -1) {
            std::cout << ans[i] << ' ';
        }
    }

    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
