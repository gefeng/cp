#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

std::vector<int> dfs(int N, int K, std::set<int>& p_2) {
    std::vector<int> res;
    if(p_2.find(N) != p_2.end()) {
        res.resize(N, K);
        return res;
    }

    auto it = std::prev(p_2.upper_bound(N));
    std::vector<int> tmp = dfs(N - *it, K, p_2);
    res.resize(N, 0);
    for(int i = 0; i < tmp.size(); i++) {
        res[i] = tmp[i];
        res[N - 1 - i] = tmp[i];
    }
    return res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::set<int> p_2;
    int now = 1;
    for(int i = 0; i <= 30; i++) {
        p_2.insert(now);
        now *= 2;
    }

    std::vector<int> ans = dfs(N, K, p_2);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
