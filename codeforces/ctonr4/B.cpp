#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    if(N % 2 == 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans;
    while(N != 1) {
        int x = (N + 1) / 2;
        int y = (N - 1) / 2;
        if(x % 2 == 0) {
            N = y;
            ans.push_back(2);
        } else {
            N = x; 
            ans.push_back(1);
        }
    }

    std::reverse(ans.begin(), ans.end());

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
