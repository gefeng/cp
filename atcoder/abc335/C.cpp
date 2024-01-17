#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    int x = 0;
    int y = 0;
    std::vector<std::pair<int, int>> save;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            char C;
            std::cin >> C;

            if(C == 'R') {
                x += 1;
            } else if(C == 'L') {
                x -= 1;
            } else if(C == 'U') {
                y += 1;
            } else {
                y -= 1;
            }
            save.emplace_back(x, y);
        } else {
            int P;
            std::cin >> P;
            
            int size = save.size();
            if(size <= P - 1) {
                std::cout << P - size << ' ' << 0 << '\n';
            } else {
                std::cout << 1 + save[size - P].first << ' ' << save[size - P].second << '\n';
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
