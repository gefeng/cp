#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

std::pair<int64_t, int64_t> dfs(int64_t K, int64_t l, int64_t r) {
    if(l > r) {
        return {0, 0};
    }

    int64_t len = r - l + 1;
    if(len < K) {
        return {0, 0};
    }

    int64_t mid = (l + r) / 2;
    int64_t res = 0;
    int64_t cnt = 0;
    if(len % 2 == 0) {
        auto [sum, f] = dfs(K, l, mid);
        res = sum + sum + f * mid; 
        cnt = f * 2;
    } else {
        auto [sum, f] = dfs(K, l, mid - 1);
        res = sum + sum + f * mid + mid;
        cnt = f * 2 + 1;
    }

    return {res, cnt};
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::cout << dfs(K, 1, N).first << '\n';
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
