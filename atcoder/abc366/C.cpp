#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int Q;
    std::cin >> Q;
    
    std::map<int, int> m;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int X;
            std::cin >> X;
            
            m[X] += 1;
        } else if(T == 2) {
            int X;
            std::cin >> X;

            if(--m[X] == 0) {
                m.erase(X);
            }
        } else {
            std::cout << int(m.size()) << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
