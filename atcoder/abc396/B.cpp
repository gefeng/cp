#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int Q;
    std::cin >> Q;
    
    std::vector<int> stk(100, 0);
    
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int X;
            std::cin >> X;
            stk.push_back(X);
        } else {
            int top = stk.back();
            stk.pop_back();
            std::cout << top << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
