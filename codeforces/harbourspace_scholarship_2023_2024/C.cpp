#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    std::vector<int> ans;
    ans.push_back(X);
    for(int i = 0; i <= 30; i++) {
        if((X & (1 << i)) && (X ^ (1 << i))) {
            X ^= 1 << i;
            ans.push_back(X);
        }
    }

    while(X != 1) {
        ans.push_back(X / 2);
        X /= 2;
    }

    int sz = ans.size();
    std::cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
