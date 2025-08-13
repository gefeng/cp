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
    
    auto query = [](int i, int j) {
        std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> ans(N, 0);
    std::vector<int> q(N, 0);
    int p = 0;
    for(int i = 1; i < N; i++) {
        int x = query(p, i);
        int y = query(i, p);
        if(x < y) {
            ans[i] = y;
        } else {
            ans[p] = x;
            p = i;
        }
    }

    ans[p] = N;
    std::cout << "! ";
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
