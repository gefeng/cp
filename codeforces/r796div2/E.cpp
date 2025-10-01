#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    auto query = [](std::string& s) {
        std::cout << "? " << s << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<std::pair<int, int>> edges;
    for(int i = 0; i < M; i++) {
        std::string s(M, '0'); 
        s[i] = '1';
        edges.emplace_back(query(s), i);
    }

    std::ranges::sort(edges);

    int ans = 0;
    std::string now(M, '0');
    for(int i = 0; i < M; i++) {
        auto [e, idx] = edges[i];
        now[idx] = '1';
        int cap = query(now);
        if(cap == ans + e) {
            ans += e;
            continue;
        }
        now[idx] = '0';
    }

    std::cout << "! " << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
