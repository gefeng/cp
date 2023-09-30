#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs(int len, int64_t cur, std::set<int64_t>& all) {
    if(cur != 0) {
        all.insert(cur);
    }
    
    int st = len == 1 ? 1 : 0;
    for(int d = st; d < 10; d++) {
        if(len == 1) {
            dfs(len + 1, d, all);
        } else {
            if(d < cur % 10) {
                dfs(len + 1, cur * 10 + d, all);
            }
        }
    }
}

void run_case() {
    int64_t K;
    std::cin >> K;

    std::set<int64_t> all;
    
    dfs(1, 0, all);

    for(int64_t x : all) {
        if(K == 1) {
            std::cout << x << '\n';
            return;
        }        
        K -= 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
