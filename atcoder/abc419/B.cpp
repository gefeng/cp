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
    int Q;
    std::cin >> Q;
    
    std::multiset<int> ms;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int X;
            std::cin >> X;
            ms.insert(X);
        } else {
            int res = *ms.begin();
            ms.erase(ms.begin());
            std::cout << res << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
