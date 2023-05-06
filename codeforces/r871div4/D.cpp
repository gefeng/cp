#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

bool dfs(int N, int M, std::set<int>& vis) {
    if(N == M) {
        return true;
    }
    if(N < M) {
        return false;
    }

    vis.insert(N);
    
    if(N % 3 == 0) {
        int x = N / 3;
        if(vis.find(x) == vis.end()) {
            if(dfs(x, M, vis)) {
                return true;
            }
        }
        if(vis.find(2 * x) == vis.end()) {
            if(dfs(2 * x, M, vis)) {
                return true;
            }
        }
    }

    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::set<int> vis;
    std::cout << (dfs(N, M, vis) ? "YES" : "NO") << '\n';
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
