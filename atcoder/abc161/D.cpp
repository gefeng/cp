#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr int MAX_LEN = 10;

void dfs(int tl, int l, LL cur, std::vector<LL>& all) {
    if(l == tl) {
        all.push_back(cur);
        return;
    }
    
    if(l == 0) {
        for(int i = 1; i < 10; i++) {
            dfs(tl, l + 1, i, all);
        }
    } else {
        int c = cur % 10;
        dfs(tl, l + 1, (cur * 10LL) + c, all);
        
        if(c + 1 < 10) {
            dfs(tl, l + 1, (cur * 10LL) + (c + 1), all);
        }
        if(c - 1 >= 0) {
            dfs(tl, l + 1, (cur * 10LL) + (c - 1), all);
        }
    }
}

void run_case() {
    int K;
    std::cin >> K;

    std::vector<LL> all;

    for(int i = 1; i <= MAX_LEN; i++) {
        dfs(i, 0, 0LL, all);
    }

    std::sort(all.begin(), all.end());

    std::cout << all[K - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
