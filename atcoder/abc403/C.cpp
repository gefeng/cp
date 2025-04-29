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
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<std::set<int>> p(N);
    std::vector<int> all(N, 0);
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int X, Y;
            std::cin >> X >> Y;
            p[X - 1].insert(Y);
        } else if(T == 2) {
            int X;
            std::cin >> X;
            all[X - 1] = 1;
        } else {
            int X, Y;
            std::cin >> X >> Y;
            
            std::cout << (all[X - 1] || p[X - 1].find(Y) != p[X - 1].end() ? "Yes" : "No") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
